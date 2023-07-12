#pragma once

#include "CoreMinimal.h"

#include "ItemInstance.h"
#include "InventoryStack.h"

#include "Inventory.generated.h"

UCLASS()
class MOBBERVILLE_API UInventory : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category="Inventory")
	int64 AddItem(TSubclassOf<AItemInstance> item, int64 count = 1);

	UFUNCTION(BlueprintCallable, Category="Inventory")
	int64 HasItem(TSubclassOf<AItemInstance> item);
	
	UFUNCTION(BlueprintCallable, Category="Inventory")
	int64 RemoveItem(TSubclassOf<AItemInstance> item, int64 count = 1);

	UPROPERTY(BlueprintReadWrite)
	TArray<FInventoryStack> items;

	int32 GetMaxSize();

	UFUNCTION(BlueprintCallable, Category="Inventory")
	void SetMaxSize(int32 newSize);
protected:
	int32 size = 0;
};
