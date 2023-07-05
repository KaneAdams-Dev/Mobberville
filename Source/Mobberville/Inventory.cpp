#include "Inventory.h"

#include "Item.h"

UInventory::UInventory()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInventory::AddItem(AItem* item, int64 count)
{
	if (count <= 0)
	{
		// If count is negative or non existent, don't do anything.
		return;
	}

	// Get item ID
	FString itemID = item->itemName;
	
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

	if (shouldAutoEquip && !IsItemEquipped())
	{
		// Equip the item if no item is currently equipped.
		EquipItem(itemID);
	}
}

void UInventory::RemoveItem(AItem* item, int64 count)
{
	if (count <= 0)
	{
		// If count is negative or non existent, don't do anything.
		return;
	}

	// Get item ID
	FString itemID = item->itemName;
	
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

		if (GetEquippedItemID() == itemID)
		{
			// Remove equipped item, if this is it.
			Unequip();
		}
	}
}

void UInventory::GetItemIDs(TArray<FString>& ids)
{
	items.GetKeys(ids);
}

bool UInventory::ItemExists(const FString& id)
{
	return items.Contains(id) && itemCounts.Contains(id);
}

AItem* UInventory::GetItem(const FString& id)
{
	if (!ItemExists(id))
	{
		// Return nullptr if there is no item.
		// TODO make safer way of handling this.
		return nullptr;
	}
	return items[id];
}

int64 UInventory::GetItemCount(const FString& id)
{
	if (!ItemExists(id))
	{
		// Item doesn't exist, so there is 0 of the item.
		return 0;
	}
	return itemCounts[id];
}

bool UInventory::EquipItem(const FString& id)
{
	if (GetItemCount(id) <= 0)
	{
		// Item doesn't exist, don't equip it.
		return false;
	}
	equippedItem = id;
	return true;
}

void UInventory::Unequip()
{
	equippedItem = "";
}

const FString& UInventory::GetEquippedItemID()
{
	return equippedItem;
}

bool UInventory::IsItemEquipped()
{
	return equippedItem != "";
}
