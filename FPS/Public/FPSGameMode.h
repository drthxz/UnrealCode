// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPSGameMode.generated.h"

UCLASS(minimalapi)
class AFPSGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFPSGameMode();

	void CompleteMission(APawn* pawn, bool IsSuccess);

	UFUNCTION(BlueprintImplementableEvent,Category="GameMode")
		void OnMissionCompleted(APawn* pawn,bool IsSuccess);

	UPROPERTY(EditDefaultsOnly, Category = "View Point Class")
		TSubclassOf<AActor> viewPointActorClass;
};



