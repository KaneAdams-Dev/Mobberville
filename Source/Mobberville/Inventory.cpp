#include "Inventory.h"

#include "ItemInstance.h"
#include "InventoryStack.h"

void UInventory::SetMaxSize(int32 newSize)
{
	if (newSize <= 0)
	{
		// Throw notice if negative count, since that really shouldn't happen.
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Inventory size cannot be set to a value <= 0."));
		return;
	}

	items.SetNumUninitialized(newSize);
	for (int32 i = size; i < newSize; i++)
	{
		items[i] = FInventoryStack();
		items[i].item = nullptr;
		items[i].count = 0;
	}
	size = newSize;
}

int32 UInventory::GetMaxSize()
{
	return size;
}

int64 UInventory::AddItem(TSubclassOf<AItemInstance> item, int64 count)
{
	if (count == 0)
	{
		// Don't do anything if count is zero.
		return 0;
	}
	else if (count < 0)
	{
		// Throw notice if negative count, since that really shouldn't happen.
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Inventory::AddItem called with negative count."));
		return -1;
	}

	// Add to existing stacks of this item.
	for (int32 i = 0; i < size; i++)
	{
		if (items[i].IsEmpty())
		{
			// This stack is empty.
			continue;
		}
		if (items[i].item.Get()->GetClass() != item.Get()->GetClass())
		{
			// This is not the same item as the provided one. Get next item.
			continue;
		}

		items[i].count += count;

		AItemInstance* stackItem = items[i].item.GetDefaultObject();
		const int64 maxStack = stackItem->stackSize;

		// Set count to the remainder
		count = items[i].count - maxStack;

		// Clamp the stack to the max stack
		items[i].count = FMath::Min(items[i].count, maxStack);

		if (count <= 0) {
			// All items added, return.
			return 0;
		}
	}

	// Create a new stack if there is space in the inventory.
	AItemInstance* itemInstance = item.GetDefaultObject();
	const int32 maxStack = itemInstance->stackSize;

	for (int32 i = 0; i < size; i++)
	{
		if (!items[i].IsEmpty())
		{
			// This stack is not empty, move to next slot.
			continue;
		}
		
		// Set this stack to this item
		items[i].item = item;
		items[i].count = count;

		// Set count to the remainder
		count = items[i].count - maxStack;

		// Clamp the stack to the max stack
		items[i].count = FMath::Min(items[i].count, maxStack);

		if (count <= 0) {
			// All items added, return.
			return 0;
		}
	}

	// No more space in inventory, return the amount of items that could not be added.
	return count;
}

int64 UInventory::HasItem(TSubclassOf<AItemInstance> item)
{
	int64 count = 0;
	for (const FInventoryStack& invItem : items)
	{
		// True if this item is the specified item.
		bool isItem = invItem.item.Get()->GetClass() == item.GetDefaultObject()->GetClass();
		
		// Add count of the stack, multiplied by a mask of whether this is the item.
		count += invItem.count * isItem;
	}
	return count;
}

int64 UInventory::RemoveItem(TSubclassOf<AItemInstance> item, int64 count)
{
	if (count == 0)
	{
		// Don't do anything if count is zero.
		return 0;
	}
	else if (count < 0)
	{
		// Throw notice if negative count, since that really shouldn't happen.
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Inventory::RemoveItem called with negative count."));
		return -1;
	}
	
	for (int32 i = 0; i < size; i++)
	{
		if (items[i].IsEmpty())
		{
			// This stack is empty.
			continue;
		}
		if (items[i].item.Get()->GetClass() != item.Get()->GetClass())
		{
			// This is not the same item as the provided one. Get next item.
			continue;
		}

		items[i].count -= count;
		count = -items[i].count;

		if (items[i].count <= 0)
		{
			// Clear this stack if all have been removed.
			items[i].item = nullptr;
			items[i].count = 0;
		}

		if (count <= 0)
		{
			// Items have been removed.
			return 0;
		}
	}

	// Return the amount of items that couldn't be removed.
	return count;
}
