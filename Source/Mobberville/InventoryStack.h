#pragma once

#include "CoreMinimal.h"

#include "ItemInstance.h"

#include "InventoryStack.generated.h"

USTRUCT(BlueprintType)
struct MOBBERVILLE_API FInventoryStack
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	TSubclassOf<AItemInstance> item;

	UPROPERTY(BlueprintReadOnly)
	int64 count;

	bool IsEmpty() const;
};

UCLASS()
class MOBBERVILLE_API UInventoryStackMethods : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category="InventoryStack")
	static bool IsStackEmpty(const FInventoryStack& stack);
};
