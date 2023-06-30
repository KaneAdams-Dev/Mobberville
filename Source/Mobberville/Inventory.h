#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "Item.h"

#include "Inventory.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MOBBERVILLE_API UInventory : public UActorComponent
{
	GENERATED_BODY()
public:
	UInventory();

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<TSubclassOf<AItem>> items;
};
