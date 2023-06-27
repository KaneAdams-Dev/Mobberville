#pragma once

#include <map>

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "InventoryItem.h"

#include "Inventory.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MOBBERVILLE_API UInventory : public UActorComponent
{
	GENERATED_BODY()
public:
	UInventory();

	UFUNCTION(BlueprintCallable, Category="Inventory")
	void AddItem(FInventoryItem item, int64 count = 1);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(FInventoryItem item, int64 count = 1);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	int64 GetItemCount(FInventoryItem item);

private:
	struct ItemComparator
	{
		bool operator() (const FInventoryItem& a, const FInventoryItem b) const;
	};
protected:
	std::map<FInventoryItem, int64, ItemComparator> items;
};
