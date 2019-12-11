// Fill out your copyright notice in the Description page of Project Settings.

#include "SlaiGameMode.h"
#include "SlaiMenuHUD.h"
#include "SlaiMenuController.h"

ASlaiGameMode::ASlaiGameMode() {
	HUDClass = ASlaiMenuHUD::StaticClass();
	PlayerControllerClass = ASlaiMenuController::StaticClass();
}