#include "Inventory.h"

#include "ItemInstance.h"

UInventory::UInventory()
{
}

int32 UInventory::MaxSize()
{
	return size;
}

void UInventory::SetMaxSize(int32 newSize)
{
	if (newSize < size)
	{
		items.SetNumZeroed(newSize, true);
	}
	size = newSize;
}

const TArray<FInventoryStack>& UInventory::GetItems()
{
	return items;
}

int64 UInventory::AddItem(const FItem& item, int64 count)
{
	if (count == 0)
	{
		// Don't do anything if count is zero.
		return 0;
	}
	else if (count < 0)
	{
		// Throw notice if negative count, since that really shouldn't happen.
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("SubInventory::AddItem called with negative count."));
		return -1;
	}

	for (FInventoryStack& stack : items)
	{
		if (item == stack.item)
		{
			int64 capacity = stack.item.stackSize - stack.count;
			if (capacity >= count)
			{
				stack.count += count;
				return 0;
			}
			else if (capacity > 0)
			{
				stack.count += capacity;
				count -= capacity;
				continue;
			}
		}
	}

	while (items.Num() < MaxSize())
	{
		// Clamp to stack size
		int64 stackAmount = FMath::Min(item.stackSize, count);

		// Create & add stack
		FInventoryStack stack;
		stack.item = item;
		stack.count = stackAmount;
		items.Add(stack);

		// Iterate if count is still above zero
		count -= stackAmount;
		if (count <= 0)
		{
			// All items added, can return.
			return 0;
		}
	}
	// Not all items fit into inventory,
	// return the amount of items that could not fit.
	return count;
}
