#pragma once

#include "CoreMinimal.h"

#include "Item.generated.h"

class AItemInstance;

USTRUCT(BlueprintType)
struct MOBBERVILLE_API FItem
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, Category = "Item")
	TSubclassOf<AItemInstance> blueprint;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Item")
	FString name;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Item")
	int64 stackSize = 16;

	bool operator==(const FItem& other) const;
	bool operator!=(const FItem& other) const;
};
