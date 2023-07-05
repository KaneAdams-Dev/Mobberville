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

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Item");
	FString itemID;

	UFUNCTION(BlueprintCallable, Category="Item")
	static AItem* CreateWorldInstance(UObject* context, TSubclassOf<AItem> item);

	UFUNCTION(BlueprintNativeEvent, Category="Item")
	void OnPickup(UInventory* inventory);

private:
	UFUNCTION()
	void OverlapEvent(AActor* actor, AActor* invoker);
};
