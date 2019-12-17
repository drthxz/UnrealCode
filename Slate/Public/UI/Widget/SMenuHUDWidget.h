// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "MenuWidgetStyle.h"


/**
 * 
 */
class SLAICOURSE_API SMenuHUDWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMenuHUDWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	//getUIScaler
	float GetUIScaler() const;
	//get displayerSize
	FVector2D GetViewportSize() const;

private:
	//get MenuStyle
	const struct FMenuStyle *MenuStyle;
	//set DPI scaler
	TAttribute<float> UIScaler;
	//menu
	TSharedPtr<class SMenuWidget> MenuWidget;

};
