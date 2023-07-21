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
