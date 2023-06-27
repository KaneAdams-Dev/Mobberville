#include "Inventory.h"

// Sets default values for this component's properties
UInventory::UInventory()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInventory::AddItem(FInventoryItem item, int64 count)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, item.name);
}

int64 UInventory::GetItemCount(FInventoryItem item)
{
	return 0;
}
