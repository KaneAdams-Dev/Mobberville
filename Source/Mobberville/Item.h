#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Item.generated.h"

UCLASS( Blueprintable, BlueprintType )
class MOBBERVILLE_API AItem : public AActor
{
	GENERATED_BODY()
public:
	AItem();

	UPROPERTY(BlueprintReadWrite, EditAnywhere);
	FString itemID;
	
	UFUNCTION(BlueprintCallable, Category="Inventory")
	static AItem* CreateWorldInstance(UObject* context, TSubclassOf<AItem> item);

private:
	void OverlapEvent(AActor* actor, AActor* invoker);
};
