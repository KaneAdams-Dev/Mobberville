#include "Inventory.h"

#include "Item.h"

UInventory::UInventory()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInventory::AddItem(TSubclassOf<AItem> item, int64 count)
{
	if (count <= 0)
	{
		// If count is negative or non existent, don't do anything.
		return;
	}

	// Get item ID
	AItem* itemPtr = (AItem*) item.Get();
	FString itemID = itemPtr->itemID;
	
	if (!items.Contains(itemID))
	{
		// Item does not exist, create the entries.
		items.Add(itemID, item);
		itemCounts.Add(itemID, count);
	}
	else
	{
		// Item exists, add the count to it.
		itemCounts[itemID] += count;
	}
}

void UInventory::RemoveItem(TSubclassOf<AItem> item, int64 count)
{
	if (count <= 0)
	{
		// If count is negative or non existent, don't do anything.
		return;
	}

	// Get item ID
	AItem* itemPtr = (AItem*) item.Get();
	FString itemID = itemPtr->itemID;
	
	if (!items.Contains(itemID) || !itemCounts.Contains(itemID))
	{
		// Item already doesn't exist. Don't do anything.
		return;
	}

	// Remove the item count
	itemCounts[itemID] -= count;

	if (itemCounts[itemID] <= 0)
	{
		// Remove the item from the inventory if count is less or equal to zero.
		itemCounts.Remove(itemID);
		items.Remove(itemID);
	}
}
