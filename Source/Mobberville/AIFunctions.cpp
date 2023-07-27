#include "AIFunctions.h"
#include "PlayerInventory.h"

TArray<FQuest> UAIFunctions::GetQuests(UPARAM(ref) TArray<FString>& questText, UPARAM(ref)TArray<FVector>& location, UPARAM(ref)TArray<int>& reward, UPARAM(ref)TArray<FObjectTypes>& questObjects, UPARAM(ref)int& numberOfQuests, UPARAM(ref) TArray<bool> isFetchQuest)
{
	TArray<FQuest> quests;

	for (int i = 0; i < numberOfQuests; i++) {
		FQuest quest;
		quest.QuestText = questText[i];
		quest.objectiveLocation = location[i];
		quest.reward = reward[i];
		quest.fetchQuest = isFetchQuest[i];
		for (int k = 0; k < questObjects[i].questsItems.Num(); k++) {
			for (int j = 0; j < questObjects[i].questsItems[k].numberOfObject; j++) {
				quest.objectsToCollect.Add(questObjects[i].questsItems[k].Object);
			}
		}

		quests.Add(quest);
	}

	return quests;
}

bool UAIFunctions::SplitQuestItems(UPARAM(ref)TSubclassOf<AItemInstance>& obj, UPARAM(ref)TSubclassOf<AItemInstance>& previousObj, UPARAM(ref) bool& firstItem, UPARAM(ref) int& numberOfObject, UPARAM(ref) int& ObjectsLength, UPARAM(ref) int& objIndex)
{
	if (ObjectsLength != 0) {
		if (objIndex == ObjectsLength - 1) {
			numberOfObject += 1;
			previousObj = obj;
			return true;
		}
	}

	if (firstItem || (obj == previousObj)) {
		numberOfObject += 1;
		return false;
	}
	else {
		previousObj = obj;
		return true;
	}
}

bool UAIFunctions::CheckFirstPositionChoice(UPARAM(ref) bool& firstChoice, UPARAM(ref) bool& posReached)
{
	if (firstChoice) {
		return true;
	}

	if (posReached) {
		return true;
	}

	return false;
}

void UAIFunctions::SetQuestParametersLength(UPARAM(ref)int& QuestLength, UPARAM(ref)TArray<FString>& QuestTexts, UPARAM(ref)TArray<FVector>& QuestLocations, UPARAM(ref)TArray<int>& QuestRewards, UPARAM(ref)TArray<FEncapsule>& QuestObjectsList) {

}

bool objsSet = false;
TArray<FEncapsule> UAIFunctions::SetQuestObjects(UPARAM(ref)int& numberOfQuests, UPARAM(ref)TArray<int>& numberOfObj, UPARAM(ref)TSubclassOf<AItemInstance> obj, UPARAM(ref)TArray<FEncapsule>& questObjectsList, UPARAM() TArray<TSubclassOf<AItemInstance>> objTypes, UPARAM(ref)TArray<int>& numberOfObjTypes)
{
	objTypes.Empty();
	numberOfObjTypes.Empty();

	FEncapsule questObjs;
	questObjectsList.Init(questObjs, numberOfQuests);

	for (int i = 0; i < numberOfQuests; i++) {
		for (int j = 0; j < numberOfObj[i]; j++) {
			obj = objTypes[j];
			for (int k = 0; k < numberOfObjTypes[j]; k++) {
				questObjectsList[i].questObjs.Add(obj);
			}
		}
	}

	return questObjectsList;
}

int startPos = 0;
TArray<FString> UAIFunctions::SetSpeechText(UPARAM(ref) TArray<FQuest>& quests, UPARAM(ref) int& questNo, UPARAM(ref) int& sentenceNo, UPARAM(ref) UAIFunctions* myObj)
{
	FString text = quests[questNo].QuestText;
	TArray<FString> sentences;

	for (int i = 0; i < text.Len(); i++) {
		FString currentChar = text.Mid(i, 1);
		if (currentChar.Equals(TEXT("."))) {
			int charCount = i - startPos;
			FString sentence = text.Mid(startPos, charCount);
			sentences.Add(sentence);
			startPos = i + 1;
		}
	}

	myObj->textRetrieved = true;
	startPos = 0;

	return sentences;
}

FQuest UAIFunctions::SetQuestStatus(UPARAM(ref)TArray<FQuest>& quests, UPARAM(ref)int& questNumber, UPARAM() bool questComplete, UPARAM()bool yesSelected)
{
	FQuest activeQuest = quests[questNumber];

	if (yesSelected) {
		activeQuest.questAccepted = true;
		return activeQuest;
	}

	activeQuest.questAccepted = false;
	return {};
}

///Returns true is the quest has been accepted and false if it has not
bool UAIFunctions::CheckQuestStatus(UPARAM(ref)TArray<FQuest>& quests, UPARAM(ref)FQuest& activeQuest, UPARAM(ref) int& questNumber)
{
	if (activeQuest.questAccepted) {
		return true;
	}
	else {
		return false;
	}
}

void UAIFunctions::CompleteQuest(UPARAM(ref)FQuest activeQuest, UPARAM(ref)TArray<FQuest> completedQuests) {
	if (!activeQuest.questComplete) {
		activeQuest.questComplete = true;
		completedQuests.Add(activeQuest);
	}

}
