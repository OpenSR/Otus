// Copyright Epic Games, Inc. All Rights Reserved.

#include "OtusGameMode.h"
#include "OtusCharacter.h"
#include "UObject/ConstructorHelpers.h"

AOtusGameMode::AOtusGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
