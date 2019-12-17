// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlaiTypes.h"
#include "Widgets/SCompoundWidget.h"


class SBox;
class STextBlock;
class SVerticalBox;
/**
 * 
 */
class SLAICOURSE_API SMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMenuWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	void MenuItemOnClicked(EMenuItem::Type ItemType);

private :
	//root
	TSharedPtr<SBox> RootSizeBox;
	//title
	TSharedPtr<STextBlock> TitleText;
	//Vertical List
	TSharedPtr<SVerticalBox> ContentBox;

	//get MenuStyle
	const struct FMenuStyle* MenuStyle;
};
