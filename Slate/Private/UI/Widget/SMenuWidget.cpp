// Fill out your copyright notice in the Description page of Project Settings.

#include "SMenuWidget.h"
#include "SlateOptMacros.h"
#include "SlaiStyle.h"
#include "MenuWidgetStyle.h"
#include "SBox.h"
#include "STextBlock.h"
#include "SSlaiMenuItemWidget.h"
#include "SBoxPanel.h"
#include "SSlaiGameOptionWidget.h"
#include "SlaiHelper.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMenuWidget::Construct(const FArguments& InArgs)
{
	//get MenuStyle
	MenuStyle = &SlaiStyle::Get().GetWidgetStyle<FMenuStyle>("BPSlaiMenuStyle");


	ChildSlot
	[
		SAssignNew(RootSizeBox,SBox)
		[
			SNew(SOverlay)
			//MenuBackground
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(FMargin(0.f,50.f,0.f,0.f))
			[
				SNew(SImage)
				.Image(&MenuStyle->MenuBackgroundBrush)
			]
			//LeftIcon
			+SOverlay::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			.Padding(FMargin(0.f,25.f,0.f,0.f))
			[
				SNew(SImage)
				.Image(&MenuStyle->LeftIconBrush)
			]
			//RightIocn
			+ SOverlay::Slot()
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Center)
			.Padding(FMargin(0.f, 25.f, 0.f, 0.f))
			[
				SNew(SImage)
				.Image(&MenuStyle->RightIocnBrush)
			]
			//MenuText
			+SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Top)
			[
				SNew(SBox)
				.WidthOverride(400.f)
				.HeightOverride(100.f)
				[
					SNew(SBorder)
					.BorderImage(&MenuStyle->TitleBorderBrush)
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					[
						SAssignNew(TitleText,STextBlock)
						.Font(SlaiStyle::Get().GetFontStyle("MenuItemFont"))
						.Text(NSLOCTEXT("SlaiMenu", "Menu", "Menu"))
					]
				]
			]
			//Menu 
			+ SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Top)
			.Padding(FMargin(0.f,130.f,0.f,0.f))
			[
				SAssignNew(ContentBox,SVerticalBox)
			]
		]
	];
	
	RootSizeBox->SetWidthOverride(600.f);
	RootSizeBox->SetHeightOverride(510.f);

	ContentBox->AddSlot()
		[
			SNew(SSlaiGameOptionWidget)

		];

}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SMenuWidget::MenuItemOnClicked(EMenuItem::Type ItemType)
{
	//SlaiHelper::Debug(FString("StartGame"),3.f);
}
