#include "PlayerInventory.h"

UPlayerInventory::UPlayerInventory()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UPlayerInventory::BeginPlay()
{
	hotbar = NewObject<UInventory>();
	hotbar->SetMaxSize(hotbarSize);
}

int64 UPlayerInventory::AddItem(const FItem& item, int64 count)
{
	if (count > 0) count = hotbar->AddItem(item, count);
	return count;
}

int64 UPlayerInventory::HasItem(const FItem& item)
{
	int64 count = 0;
	count += hotbar->HasItem(item);
	return count;
}

int64 UPlayerInventory::RemoveItem(const FItem& item, int64 count)
{
	if (count > 0) count = hotbar->RemoveItem(item, count);
	return count;
}
