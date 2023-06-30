#include "Item.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = false;
	OnActorBeginOverlap.AddDynamic(this, &AItem::OverlapEvent);
}

void AItem::OverlapEvent(AActor* actor, AActor* invoker)
{
	
}

AItem* AItem::CreateWorldInstance(UObject* context, TSubclassOf<AItem> item)
{
	return context->GetWorld()->SpawnActor<AItem>(item, FVector(0, 0, 0), FRotator());
}
