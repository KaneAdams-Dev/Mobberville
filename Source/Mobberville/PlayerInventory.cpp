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
	count = hotbar->AddItem(item, count);
	return count;
}
