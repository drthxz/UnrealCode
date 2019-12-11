// Fill out your copyright notice in the Description page of Project Settings.

#include "SlaiMenuController.h"

ASlaiMenuController::ASlaiMenuController() {
	//ShowMouse
	bShowMouseCursor = true;
}

void ASlaiMenuController::BeginPlay()
{
	FInputModeUIOnly InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	SetInputMode(InputMode);
}
