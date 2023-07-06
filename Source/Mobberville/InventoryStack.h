#pragma once

#include "CoreMinimal.h"

#include "Item.h"

#include "InventoryStack.generated.h"

USTRUCT(BlueprintType)
struct MOBBERVILLE_API FInventoryStack
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	FItem item;

	UPROPERTY(BlueprintReadOnly)
	int64 count;
};
