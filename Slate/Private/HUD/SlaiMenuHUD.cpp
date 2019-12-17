// Fill out your copyright notice in the Description page of Project Settings.

#include "SlaiMenuHUD.h"
#include "SMenuHUDWidget.h"
#include "SlateBasics.h"

ASlaiMenuHUD::ASlaiMenuHUD() {
	if (GEngine && GEngine->GameViewport) {
		SAssignNew(MenuHUDWidget, SMenuHUDWidget);
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MenuHUDWidget.ToSharedRef()));
	}
}