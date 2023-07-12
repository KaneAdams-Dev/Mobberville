#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "InventoryComponent.h"

#include "ItemInstance.generated.h"

UCLASS(Blueprintable)
class MOBBERVILLE_API AItemInstance : public AActor
{
	GENERATED_BODY()
public:
	AItemInstance();

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Item")
	FString name;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Item")
	int64 stackSize = 16;

	UFUNCTION(BlueprintNativeEvent, Category="Item")
	void OnPickup(const TScriptInterface<IInventoryComponent>& inventory);

private:
	UFUNCTION()
	void OverlapEvent(AActor* actor, AActor* invoker);
};
