// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExamGameMode.h"
#include "ExamHUD.h"
#include "ExamCharacter.h"
#include "UObject/ConstructorHelpers.h"

AExamGameMode::AExamGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AExamHUD::StaticClass();
}
