#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "Inventory.h"
#include "InventoryComponent.h"

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

	UFUNCTION(BlueprintCallable, Category="PlayerInventory")
	virtual int64 AddItem(const FItem& item, int64 count = 1) override;
private:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	int32 hotbarSize = 10;
};
