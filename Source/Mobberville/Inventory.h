#pragma once

#include "CoreMinimal.h"

#include "Item.h"
#include "InventoryStack.h"

#include "Inventory.generated.h"

UCLASS()
class MOBBERVILLE_API UInventory : public UObject
{
	GENERATED_BODY()
public:
	UInventory();

	UFUNCTION(BlueprintCallable, Category="Inventory")
	const TArray<FInventoryStack>& GetItems();

	UFUNCTION(BlueprintCallable, Category="Inventory")
	int64 AddItem(const FItem& item, int64 count = 1);
	UFUNCTION(BlueprintCallable, Category="Inventory")
	int64 HasItem(const FItem& item);
	UFUNCTION(BlueprintCallable, Category="Inventory")
	int64 RemoveItem(const FItem& item, int64 count = 1);

	UPROPERTY(BlueprintReadWrite)
	TArray<FInventoryStack> items;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	int32 MaxSize();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetMaxSize(int32 newSize);
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 size = 10;
};
