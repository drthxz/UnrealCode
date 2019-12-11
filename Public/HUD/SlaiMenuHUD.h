// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SlaiMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class SLAICOURSE_API ASlaiMenuHUD : public AHUD
{
	GENERATED_BODY()
public :
	ASlaiMenuHUD();
	TSharedPtr<class SMenuHUDWidget> MenuHUDWidget;
};
