#include "InventoryItemWorld.h"

AInventoryItemWorld::AInventoryItemWorld()
{
	PrimaryActorTick.bCanEverTick = false;

	OnActorBeginOverlap.AddDynamic(this, &AInventoryItemWorld::OverlapListener);
}

void AInventoryItemWorld::OverlapListener(AActor* actor, AActor* invoker)
{
	if (invoker == this)
	{
		// Don't count self-hits as pickups
		return;
	}

	if (!invoker->ActorHasTag(FName("Player")))
	{
		// Don't execute code if it isn't a player that has picked up the item.
		return;
	}

	// Add this to the item as a prefab
	FInventoryItem itemInstance = item;
	itemInstance.prefab = FActorSpawnParameters();
	itemInstance.prefab.Template = this;

	// Add this item to inventory
	UInventory* inventory = invoker->GetComponentByClass<UInventory>();
	inventory->AddItem(itemInstance, 1);

	OnItemPickup(inventory);

	Destroy();
}
