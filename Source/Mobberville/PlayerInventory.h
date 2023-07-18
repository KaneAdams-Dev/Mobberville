#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "Inventory.h"
#include "InventoryComponent.h"

#include "ItemInstance.h"

#include "PlayerInventory.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MOBBERVILLE_API UPlayerInventory : public UActorComponent, public IInventoryComponent
{
	GENERATED_BODY()
public:
	UPlayerInventory();
	
	UPROPERTY(BlueprintReadOnly)
	UInventory* hotbar;

	UPROPERTY(BlueprintReadWrite)
	int32 equippedIndex = 0;

	UPROPERTY(BlueprintReadOnly)
	UInventory* inventory;

	UFUNCTION(BlueprintCallable, Category="PlayerInventory")
	virtual int64 AddItem(TSubclassOf<AItemInstance> item, int64 count = 1) override;

	UFUNCTION(BlueprintCallable, Category="PlayerInventory")
	virtual int64 HasItem(TSubclassOf<AItemInstance> item) override;

	UFUNCTION(BlueprintCallable, Category="PlayerInventory")
	virtual int64 RemoveItem(TSubclassOf<AItemInstance> item, int64 count = 1) override;

	UFUNCTION(BlueprintCallable, Category="PlayerInventory")
	FInventoryStack& GetEquippedItemStack();

private:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	int32 hotbarSize = 10;

	UPROPERTY(EditDefaultsOnly)
	int32 inventorySize = 40;
};
