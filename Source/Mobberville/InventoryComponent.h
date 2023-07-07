#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "Item.h"

#include "InventoryComponent.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UInventoryComponent : public UInterface
{
	GENERATED_BODY()
};

class MOBBERVILLE_API IInventoryComponent
{
	GENERATED_BODY()
public:
	virtual int64 AddItem(const FItem& item, int64 count = 1) = 0;
};
