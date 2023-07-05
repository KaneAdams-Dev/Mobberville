#pragma once

#include "CoreMinimal.h"

#include "InventoryStack.generated.h"

class AItem;

UCLASS()
class MOBBERVILLE_API UInventoryStack : public UObject
{
	GENERATED_BODY()
public:
	UInventoryStack();

	UFUNCTION(BlueprintCallable, Category="InventoryStack")
	static UInventoryStack* Create(AItem* item, int64 maxSize = 999, int64 size = 0);

	UPROPERTY(EditAnywhere)
	AItem* item;

	int64 GetSize();
	int64 GetMaxSize();

	UFUNCTION(BlueprintCallable, Category="InventoryStack")
	void Add(int64 count = 1);
	UFUNCTION(BlueprintCallable, Category="InventoryStack")
	void Remove(int64 count = 1);

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere);
	int64 size = 0;

	UPROPERTY(BlueprintReadOnly, EditAnywhere);
	int64 maxSize = 8;

	void ClampSize();
};
