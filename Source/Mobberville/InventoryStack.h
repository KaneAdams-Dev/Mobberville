#pragma once

#include "CoreMinimal.h"

#include "InventoryStack.generated.h"

class AItem;

USTRUCT(BlueprintType)
struct MOBBERVILLE_API FInventoryStack
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	AItem* item;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int64 count;
};
