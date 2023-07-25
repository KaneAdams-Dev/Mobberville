#include "InventoryComponent.h"

#include "Inventory.h"
#include "InventoryStack.h"

IInventoryComponent::IInventoryComponent()
{
	inventoryUpdateEvent = NewObject<UInventoryUpdateEvent>();
}

void UInventoryUpdateEvent::RegisterInventory(UInventory* inventory)
{
	inventory->inventoryUpdatedEvent.AddDynamic(this, &UInventoryUpdateEvent::OnUpdate);
}

void UInventoryUpdateEvent::OnUpdate()
{
	onInventoryComponentUpdate.Broadcast();
}

UInventoryUpdateEvent* UInventoryUpdateEvent::GetInventoryComponentUpdateEvent(const TScriptInterface<IInventoryComponent>& inventoryComponent)
{
	return inventoryComponent->inventoryUpdateEvent;
}

void UInventoryReferenceFunctions::SwapStacks(FInventoryReference a, FInventoryReference b)
{
	FInventoryStack* aStack = &a.subInventory->items[a.subInventoryIndex];
	FInventoryStack* bStack = &b.subInventory->items[b.subInventoryIndex];
	FInventoryStack aStackClone = *aStack;

	aStack->item = bStack->item;
	aStack->count = bStack->count;

	bStack->item = aStackClone.item;
	bStack->count = aStackClone.count;
}
