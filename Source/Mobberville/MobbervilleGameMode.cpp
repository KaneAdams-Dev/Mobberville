// Copyright Epic Games, Inc. All Rights Reserved.

#include "MobbervilleGameMode.h"
#include "MobbervilleCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMobbervilleGameMode::AMobbervilleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TestPlayer"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
