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

	bool IsEmpty();
};
