// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SlaiMenuController.generated.h"

/**
 * 
 */
UCLASS()
class SLAICOURSE_API ASlaiMenuController : public APlayerController
{
	GENERATED_BODY()
public :
	ASlaiMenuController();

protected:
	virtual void BeginPlay() override;
};
