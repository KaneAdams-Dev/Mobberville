#include "ItemInstance.h"

AItemInstance::AItemInstance()
{
	PrimaryActorTick.bCanEverTick = false;
	OnActorBeginOverlap.AddDynamic(this, &AItemInstance::OverlapEvent);
}

void AItemInstance::OverlapEvent(AActor* actor, AActor* invoker)
{
	if (actor == nullptr || invoker == nullptr)
	{
		// Invalid actor parameter
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Actor/Invoker null."));
		return;
	}
	if (actor == invoker || invoker == this)
	{
		// Should not be invoked by itself.
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Invoker is itself."));
		return;
	}

	if (!invoker->ActorHasTag(FName("Player")))
	{
		// Entity unable to pick up item.
		return;
	}

	TScriptInterface<IInventoryComponent> inventory = nullptr;
	for (UActorComponent* component : invoker->GetComponentsByInterface(UInventoryComponent::StaticClass()))
	{
		inventory = component;
		break;
	}
	if (inventory == nullptr)
	{
		// Inventory component does not exist on the invoker.
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Could not find inventory component."));
		return;
	}

	OnPickup(inventory);
}

void AItemInstance::OnPickup_Implementation(const TScriptInterface<IInventoryComponent>& inventory)
{
	inventory->AddItem(this->GetClass());
	this->Destroy();
}
