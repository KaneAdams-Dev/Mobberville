#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "InventoryComponent.generated.h"

class AItemInstance;
class UInventory;
struct FInventoryStack;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FComponentUpdated);

UCLASS()
class UInventoryUpdateEvent : public UObject
{
	GENERATED_BODY()
public:
	void RegisterInventory(UInventory* inventory);

	UFUNCTION(BlueprintCallable, Category="InventoryComponent")
	static UInventoryUpdateEvent* GetInventoryComponentUpdateEvent(const TScriptInterface<IInventoryComponent>& inventoryComponent);

	UPROPERTY(BlueprintAssignable, Category="InventoryComponent")
	FComponentUpdated onInventoryComponentUpdate;

private:
	UFUNCTION()
	void OnUpdate();
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
	UFUNCTION(BlueprintCallable, Category="InventoryComponent")
	static void SwapStacks(FInventoryReference a, FInventoryReference b);
};

UINTERFACE(MinimalAPI, BlueprintType)
class UInventoryComponent : public UInterface
{
	GENERATED_BODY()
};

class MOBBERVILLE_API IInventoryComponent
{
	GENERATED_BODY()
public:
	IInventoryComponent();

	virtual int64 AddItem(TSubclassOf<AItemInstance> item, int64 count = 1) = 0;
	virtual int64 HasItem(TSubclassOf<AItemInstance> item) = 0;
	virtual int64 RemoveItem(TSubclassOf<AItemInstance> item, int64 count = 1) = 0;
	
	UInventoryUpdateEvent* inventoryUpdateEvent;
};
