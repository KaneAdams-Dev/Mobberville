#include "Item.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = false;
	OnActorBeginOverlap.AddDynamic(this, &AItem::OverlapEvent);
}

void AItem::OverlapEvent(AActor* actor, AActor* invoker)
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

	if (!invoker->ActorHasTag(FName("Player"))) {
		// Entity unable to pick up item.
		return;
	}

	UInventory* inventory = invoker->FindComponentByClass<UInventory>();
	if (inventory == nullptr)
	{
		// Inventory component does not exist on the invoker.
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Could not find inventory component."));
		return;
	}

	OnPickup(inventory);
}

void AItem::OnPickup_Implementation(UInventory* inventory)
{
	inventory->AddItem(this);
	this->Destroy();
}

AItem* AItem::CreateWorldInstance(UObject* context, TSubclassOf<AItem> item)
{
	return context->GetWorld()->SpawnActor<AItem>(item, FVector(0, 0, 0), FRotator());
}
