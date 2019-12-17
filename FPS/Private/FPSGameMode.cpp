// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "FPSGameMode.h"
#include "FPSHUD.h"
#include "FPSCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "kismet/GameplayStatics.h"

AFPSGameMode::AFPSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSHUD::StaticClass();
}

void AFPSGameMode::CompleteMission(APawn * pawn, bool IsSuccess)
{
	if (pawn) {
		pawn->DisableInput(nullptr);
	}
	//OnMissionCompleted(pawn,true);

	TArray<AActor*> ReturnedActors;

	UGameplayStatics::GetAllActorsOfClass(this, viewPointActorClass, ReturnedActors);

	if (ReturnedActors.Num() > 0) {
		APlayerController* playerController = Cast<APlayerController>(pawn->GetController());
		if (playerController) {
			playerController->SetViewTargetWithBlend(ReturnedActors[0], 3);
		}
	}
	OnMissionCompleted(pawn, IsSuccess);
}



