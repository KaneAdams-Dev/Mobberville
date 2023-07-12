#include "AIFunctions.h"

TArray<FQuest> UAIFunctions::GetQuests(UPARAM(ref) TArray<FString>& questText, UPARAM(ref)TArray<FVector>& location, UPARAM(ref)TArray<int>& reward, UPARAM(ref)TArray<FEncapsule>& questObjects, UPARAM(ref)int& numberOfQuests)
{
	TArray<FQuest> quests;

	for (int i = 0; i < numberOfQuests; i++) {
		FQuest quest;
		quest.QuestText = questText[i];
		quest.objectiveLocation = location[i];
		quest.reward = reward[i];
		quest.objectsToCollect = questObjects[i].questObjs;
		quests.Add(quest);
	}

	return quests;
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
	QuestTexts.SetNum(QuestLength);
	QuestLocations.SetNum(QuestLength);
	QuestRewards.SetNum(QuestLength);
	QuestObjectsList.SetNum(QuestLength);
}

void UAIFunctions::SetQuestObjects(UPARAM(ref)TArray<int>& numberOfObj, UPARAM(ref)UObject* obj, UPARAM(ref)TArray<FEncapsule>& questObjectsList)
{
	for (int i = 0; i < questObjectsList.Num(); i++) {
		for (int j = 0; j < numberOfObj[i]; j++) {
			questObjectsList[i].questObjs.Add(obj);
		}
	}
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
