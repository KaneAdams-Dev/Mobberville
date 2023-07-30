#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemInstance.h"
#include "MobbervilleCharacter.h"
#include "AIFunctions.generated.h"

UENUM(BlueprintType)
enum class AIStates : uint8 {
	Wandering		UMETA(DisplayName = "Wandering"),
	Following		UMETA(DisplayName = "Following"),
	MoveIn			UMETA(DisplayName = "MovingToHouse"),
	Idle			UMETA(DisplayName = "Idle"),
};

USTRUCT(BlueprintType)
struct FQuest {
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* questIssuer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString QuestText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool fetchQuest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool questAccepted = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool objectiveCompleted = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool questComplete = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector objectiveLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool objectRequirementMet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSubclassOf<AItemInstance>> objectsToCollect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int reward;
};

USTRUCT(BlueprintType)
struct FEncapsule {
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSubclassOf<AItemInstance>> questObjs;
};

USTRUCT(BlueprintType)
struct FObjectType {
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AItemInstance> Object;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int numberOfObject;
};

USTRUCT(BlueprintType)
struct FObjectTypes {
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FObjectType> questsItems;
};

UCLASS(Blueprintable)
class MOBBERVILLE_API UAIFunctions : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool textRetrieved;

	UFUNCTION(BlueprintCallable)
		static bool SplitQuestItems(UPARAM(ref) TSubclassOf<AItemInstance>& obj, UPARAM(ref) TSubclassOf<AItemInstance>& previousObj, UPARAM(ref) bool& firstItem, UPARAM(ref) int& numberOfObject, UPARAM(ref) int& ObjectsLength, UPARAM(ref) int& objIndex);

	UFUNCTION(BlueprintCallable)
		static bool CheckFirstPositionChoice(UPARAM(ref)bool& firstChoice, UPARAM(ref)bool& posReached);

	UFUNCTION(BlueprintCallable)
		static void SetQuestParametersLength(UPARAM(ref)int& QuestLength, UPARAM(ref)TArray<FString>& QuestTexts, UPARAM(ref)TArray<FVector>& QuestLocations, UPARAM(ref)TArray<int>& QuestRewards, UPARAM(ref)TArray<FEncapsule>& QuestObjectsList);

	UFUNCTION(BlueprintCallable)
		static TArray<FEncapsule> SetQuestObjects(UPARAM(ref)int& numberOfQuests, UPARAM(ref)TArray<int>& numberOfObj, UPARAM(ref)TSubclassOf<AItemInstance> obj, UPARAM(ref)TArray<FEncapsule>& questObjectsList, UPARAM() TArray<TSubclassOf<AItemInstance>> objTypes, UPARAM(ref)TArray<int>& numberOfObjTypes);

	UFUNCTION(BlueprintCallable)
		static TArray<FQuest> GetQuests(UPARAM(ref) TArray<FString>& questText, UPARAM(ref)TArray<FVector>& location, UPARAM(ref)TArray<int>& reward, UPARAM(ref)TArray<FObjectTypes>& questObjects, UPARAM(ref)int& numberOfQuests, UPARAM(ref) TArray<bool> isFetchQuest);

	UFUNCTION(BlueprintCallable)
		static TArray<FString> SetSpeechText(UPARAM(ref) TArray<FQuest>& quests, UPARAM(ref)int& questNo, UPARAM(ref) int& sentenceNo, UPARAM(ref) UAIFunctions* myObj);

	UFUNCTION(BlueprintCallable)
		static FQuest SetQuestStatus(UPARAM(ref)TArray<FQuest>& quests, UPARAM(ref)int& questNumber, UPARAM()bool questComplete, UPARAM()bool yesSelected);

	UFUNCTION(BlueprintCallable)
		static bool CheckQuestStatus(UPARAM(ref)TArray<FQuest>& quests, UPARAM(ref)FQuest& activeQuest, UPARAM(ref)int& questNumber);

	UFUNCTION(BlueprintCallable)
		static void CompleteQuest(UPARAM(ref)FQuest activeQuest, UPARAM(ref)TArray<FQuest> completedQuests);
};