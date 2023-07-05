#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Inventory.h"

#include "Item.generated.h"

UCLASS( Blueprintable, BlueprintType )
class MOBBERVILLE_API AItem : public AActor
{
	GENERATED_BODY()
public:
	AItem();

	UPROPERTY(EditAnywhere, Category="Item")
	FString itemName;

	UPROPERTY(EditAnywhere, Category="Item")
	int64 stackSize = 16;

	UFUNCTION(BlueprintNativeEvent, Category="Item")
	void OnPickup(UInventory* inventory);

private:
	UFUNCTION()
	void OverlapEvent(AActor* actor, AActor* invoker);
};
