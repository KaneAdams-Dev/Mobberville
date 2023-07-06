#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "InventoryComponent.h"

#include "Item.generated.h"

UCLASS(Blueprintable, BlueprintType)
class MOBBERVILLE_API AItem : public AActor
{
	GENERATED_BODY()
public:
	AItem();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Item")
	FString itemName;

	UPROPERTY(EditAnywhere, Category="Item")
	int64 stackSize = 16;

	UFUNCTION(BlueprintNativeEvent, Category="Item")
	void OnPickup(const TScriptInterface<IInventoryComponent>& inventory);

private:
	UFUNCTION()
	void OverlapEvent(AActor* actor, AActor* invoker);
};
