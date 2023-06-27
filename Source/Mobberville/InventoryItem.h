#pragma once

#include "CoreMinimal.h"

#include "InventoryItem.generated.h"

USTRUCT(BlueprintType)
struct MOBBERVILLE_API FInventoryItem
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere);
	FString name;
};
