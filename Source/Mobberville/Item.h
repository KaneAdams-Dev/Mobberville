#pragma once

#include "CoreMinimal.h"

#include "Item.generated.h"

USTRUCT(BlueprintType)
struct MOBBERVILLE_API FItem
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Item")
	FString name;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Item")
	int64 stackSize = 16;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Item")
	UStaticMesh* mesh;
};
