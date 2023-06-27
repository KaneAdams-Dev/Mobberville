#include "Inventory.h"

UInventory::UInventory()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInventory::AddItem(FInventoryItem item, int64 count)
{
	if (count <= 0)
	{
		// Don't add negative amounts of items
		return;
	}

	// Add to counter and create entry if required.
	int64* itemCounter = &items[item];
	*itemCounter += count;
}

void UInventory::RemoveItem(FInventoryItem item, int64 count)
{
	if (count <= 0)
	{
		// Don't remove negative amounts of items
		return;
	}

	if (items.count(item) == 0)
	{
		// Return if item already isn't in inventory.
		return;
	}

	// Decrement item counter.
	int64* itemCounter = &items.at(item);
	*itemCounter -= count;

	if (*itemCounter <= 0)
	{
		// Remove item from the inventory if the count is zero.
		items.erase(item);
	}
}

int64 UInventory::GetItemCount(FInventoryItem item)
{
	if (items.count(item) == 0)
	{
		// Item doesn't exist, so there are zero items.
		return 0;
	}
	return items.at(item);
}

bool UInventory::ItemComparator::operator() (const FInventoryItem& a, const FInventoryItem b) const
{
	// Comparator for FInventoryItem type: just use the FString comparator.
	return a.name < b.name;
}
