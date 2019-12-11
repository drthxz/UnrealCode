// Fill out your copyright notice in the Description page of Project Settings.

#include "SMenuHUDWidget.h"
#include "SlateOptMacros.h"
#include "SButton.h"
#include "SImage.h"
#include "SlaiStyle.h"
#include "Engine/Engine.h"
#include "SDPIScaler.h"
#include "SOverlay.h"
#include "SMenuWidget.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMenuHUDWidget::Construct(const FArguments& InArgs)
{
	//get MenuStyle
	MenuStyle = &SlaiStyle::Get().GetWidgetStyle<FMenuStyle>("BPSlaiMenuStyle");
	//DPI getUIScaler
	UIScaler.Bind(this, &SMenuHUDWidget::GetUIScaler);

	ChildSlot
		[
			SNew(SDPIScaler)
			.DPIScale(UIScaler)
			[
				SNew(SOverlay)
				+ SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(SImage)
					.Image(&MenuStyle->MenuHUDBackgroundBrush)
				]
			+ SOverlay::Slot()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				[
					//SNew(SImage)
					//.Image(&MenuStyle->MenuBackgroundBrush)
					SAssignNew(MenuWidget,SMenuWidget)
				]

			]
	];
	
}
float SMenuHUDWidget::GetUIScaler() const
{
	return GetViewportSize().Y/1080.f;
}
FVector2D SMenuHUDWidget::GetViewportSize() const
{
	FVector2D Result(1920, 1080);
	if (GEngine && GEngine->GameViewport) {
		GEngine->GameViewport->GetViewportSize(Result);
	}
	return Result;
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
