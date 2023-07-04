#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "Inventory.generated.h"

class AItem;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MOBBERVILLE_API UInventory : public UActorComponent
{
	GENERATED_BODY()
public:
	UInventory();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(AItem* item, int64 count = 1);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(AItem* item, int64 count = 1);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool ItemExists(const FString& id);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	AItem* GetItem(const FString& id);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	int64 GetItemCount(const FString& id);

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<FString, AItem*> items;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<FString, int64> itemCounts;
};
