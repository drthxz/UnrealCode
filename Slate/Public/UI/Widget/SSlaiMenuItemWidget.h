// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlaiTypes.h"
#include "Widgets/SCompoundWidget.h"

DECLARE_DELEGATE_OneParam(FItemClicked, const EMenuItem::Type)
/**
 * 
 */
class SLAICOURSE_API SSlaiMenuItemWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlaiMenuItemWidget)
	{}

	SLATE_ATTRIBUTE(FText,ItemText)

		SLATE_EVENT(FItemClicked,OnClicked)

		SLATE_ATTRIBUTE(EMenuItem::Type, ItemType)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//OnMouseButtonDown
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	//OnMouseButtonUp
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	//OnMouseLeave
	virtual void OnMouseLeave(const FPointerEvent& MouseEvent) override;

private:
	//Get color
	FSlateColor GetTintColor() const;

private:
	//get MenuStyle
	const struct FMenuStyle* MenuStyle;
	//Onclick
	FItemClicked OnClicked;
	//Item Type
	EMenuItem::Type ItemType;

	//OnMouseButtonDown
	bool IsMouseButtonDown;
};
