#pragma once

#include "CoreMinimal.h"

#include "ItemInstance.h"
#include "InventoryStack.h"

#include "Inventory.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInventoryUpdated);

UCLASS(BlueprintType)
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

	UPROPERTY(BlueprintAssignable, Category="Inventory")
	FInventoryUpdated inventoryUpdatedEvent;

	UPROPERTY(BlueprintReadWrite)
	TArray<FInventoryStack> items;

	int32 GetMaxSize() const;

	UFUNCTION(BlueprintCallable, Category="Inventory")
	void SetMaxSize(int32 newSize);
protected:
	UPROPERTY(BlueprintReadOnly)
	int32 size = 0;

private:
	/// <summary>
	/// Calls the update event and passes through the given value.
	/// </summary>
	int64 InventoryReturn(int64 val);
};

USTRUCT(BlueprintType)
struct FInventoryReference
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
	UInventory* subInventory;

	UPROPERTY(BlueprintReadWrite)
	int32 subInventoryIndex;
};

UCLASS()
class UInventoryReferenceFunctions : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category="Inventory")
	static FInventoryStack& GetReferencedItem(const FInventoryReference& reference);

	UFUNCTION(BlueprintCallable, Category="Inventory")
	static void SwapStacks(const FInventoryReference& a, const FInventoryReference& b);
};
