#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
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

		FString QuestText;
	bool questAccepted = false;
	bool questComplete = false;
	FVector objectiveLocation;
	TArray<UObject*> objectsToCollect;
	int reward;
};

USTRUCT(BlueprintType)
struct FEncapsule {
	GENERATED_BODY()

		TArray<UObject*> questObjs;
};

UCLASS(Blueprintable)
class MOBBERVILLE_API UAIFunctions : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool textRetrieved;

	UFUNCTION(BlueprintCallable)
		static bool CheckFirstPositionChoice(UPARAM(ref)bool& firstChoice, UPARAM(ref)bool& posReached);

	UFUNCTION(BlueprintCallable)
		static void SetQuestParametersLength(UPARAM(ref)int& QuestLength, UPARAM(ref)TArray<FString>& QuestTexts, UPARAM(ref)TArray<FVector>& QuestLocations, UPARAM(ref)TArray<int>& QuestRewards, UPARAM(ref)TArray<FEncapsule>& QuestObjectsList);

	UFUNCTION(BlueprintCallable)
		static void SetQuestObjects(UPARAM(ref)TArray<int>& numberOfObj, UPARAM(ref)UObject* obj, UPARAM(ref)TArray<FEncapsule>& questObjectsList);

	UFUNCTION(BlueprintCallable)
		static TArray<FQuest> GetQuests(UPARAM(ref) TArray<FString>& questText, UPARAM(ref)TArray<FVector>& location, UPARAM(ref)TArray<int>& reward, UPARAM(ref)TArray<FEncapsule>& questObjects, UPARAM(ref)int& numberOfQuests);

	UFUNCTION(BlueprintCallable)
		static TArray<FString> SetSpeechText(UPARAM(ref) TArray<FQuest>& quests, UPARAM(ref)int& questNo, UPARAM(ref) int& sentenceNo, UPARAM(ref) UAIFunctions* myObj);

	UFUNCTION(BlueprintCallable)
		static FQuest SetQuestStatus(UPARAM(ref)TArray<FQuest>& quests, UPARAM(ref)int& questNumber, UPARAM()bool questComplete, UPARAM()bool yesSelected);

	UFUNCTION(BlueprintCallable)
		static bool CheckQuestStatus(UPARAM(ref)TArray<FQuest>& quests, UPARAM(ref)FQuest& activeQuest, UPARAM(ref)int& questNumber);
};