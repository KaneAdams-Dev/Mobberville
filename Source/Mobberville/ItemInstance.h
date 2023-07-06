#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "InventoryComponent.h"
#include "Item.h"

#include "ItemInstance.generated.h"

UCLASS(Blueprintable, BlueprintType)
class MOBBERVILLE_API AItemInstance : public AActor
{
	GENERATED_BODY()
public:
	AItemInstance();

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="ItemInstance")
	FItem item;

	UFUNCTION(BlueprintNativeEvent, Category="Item")
	void OnPickup(const TScriptInterface<IInventoryComponent>& inventory);

	UFUNCTION(BlueprintCallable, Category = "ItemInstance")
	static AItemInstance* SpawnItem(AActor* context, const FItem& _item);

private:
	UFUNCTION()
	void OverlapEvent(AActor* actor, AActor* invoker);
};
