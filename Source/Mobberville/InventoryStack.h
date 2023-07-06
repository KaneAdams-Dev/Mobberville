#pragma once

#include "CoreMinimal.h"

#include "InventoryStack.generated.h"

class AItem;

USTRUCT(BlueprintType)
struct MOBBERVILLE_API FInventoryStack
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	AItem* item;

	UPROPERTY(BlueprintReadOnly)
	int64 count;
};
