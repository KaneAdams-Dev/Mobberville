#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Inventory.h"
#include "InventoryItem.h"

#include "InventoryItemWorld.generated.h"

UCLASS(Blueprintable)
class MOBBERVILLE_API AInventoryItemWorld : public AActor
{
	GENERATED_BODY()
public:
	AInventoryItemWorld();

	UPROPERTY(BlueprintReadWrite, EditAnywhere);
	FInventoryItem item;

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory")
	void OnItemPickup(UInventory* inventory);

private:
	UFUNCTION()
	void OverlapListener(AActor* actor, AActor* invoker);
};
