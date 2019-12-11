// Fill out your copyright notice in the Description page of Project Settings.

#include "SSlaiGameOptionWidget.h"
#include "SlateOptMacros.h"
#include "SlaiStyle.h"
#include "MenuWidgetStyle.h"
#include "SBox.h"
#include "SImage.h"
#include "SBorder.h"
#include "SOverlay.h"
#include "STextBlock.h"
#include "SBoxPanel.h"
#include "SCheckBox.h"
#include "SSlider.h"
#include "SlaiDataHandle.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlaiGameOptionWidget::Construct(const FArguments& InArgs)
{

	//get MenuStyle
	MenuStyle = &SlaiStyle::Get().GetWidgetStyle<FMenuStyle>("BPSlaiMenuStyle");

	
	ChildSlot
	[
		SNew(SBox)
		.WidthOverride(500.f)
		.HeightOverride(300.f)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SImage)
				.Image(&MenuStyle->GameOptionBGBrush)
			]
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(FMargin(50.f))
			[
				SNew(SVerticalBox)
				
				// 1
				+SVerticalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.FillHeight(1.f)
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					.FillWidth(1.f)
					[
						SAssignNew(JaCheckBox,SCheckBox)
						.OnCheckStateChanged(this,&SSlaiGameOptionWidget::JaCeckBoxStateChanged)
						[
							SNew(STextBlock)
							.Font(MenuStyle->Font_40)
							.ColorAndOpacity(MenuStyle->FontColor_Black)
							.Text(NSLOCTEXT("SlaiMenu", "Japanese", "Japanese"))
						]
					]
					
					+ SHorizontalBox::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.FillWidth(1.f)
						[
							SAssignNew(EnCheckBox, SCheckBox)
							.OnCheckStateChanged(this, &SSlaiGameOptionWidget::EnCeckBoxStateChanged)
						[
							SNew(STextBlock)
							.Font(MenuStyle->Font_40)
							.ColorAndOpacity(MenuStyle->FontColor_Black)
							.Text(NSLOCTEXT("SlaiMenu", "English", "English"))
						]
						]
				]
				//2
				+ SVerticalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.FillHeight(1.f)
				[
					SNew(SOverlay)
					+SOverlay::Slot()
					.HAlign(HAlign_Left)
					.VAlign(VAlign_Center)
					[
						SNew(STextBlock)
						.Text(MenuStyle->Font_40)
						.ColorAndOpacity(MenuStyle->FontColor_Black)
						.Text(NSLOCTEXT("SlaiMenu","Music","Music"))
					]

					+SOverlay::Slot()
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					[
						SNew(SBox)
						.WidthOverride(240.f)
						[
							SNew(SOverlay)
							+SOverlay::Slot()
							.HAlign(HAlign_Fill)
							.VAlign(VAlign_Center)
							.Padding(FMargin(30.f,0.f))
							[
								SNew(SImage)
								.Image(&MenuStyle->SliderBarBrush)
							]
							
							+ SOverlay::Slot()
							.HAlign(HAlign_Fill)
							.VAlign(VAlign_Center)
							[
								SAssignNew(MusicSlider,SSlider)
								.Style(&MenuStyle->SliderStyle)
								.OnValueChanged(this,&SSlaiGameOptionWidget::MusicSliderChanged)
							]
						]
					]

					+ SOverlay::Slot()
					.HAlign(HAlign_Right)
					.VAlign(VAlign_Center)
					[
						SAssignNew(MusicTextBlock,STextBlock)
						.Font(MenuStyle->Font_40)
						.ColorAndOpacity(MenuStyle->FontColor_Black)
					]
				]
				//3
				+ SVerticalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.FillHeight(1.f)
				[
					SNew(SOverlay)
				]
			]
		]
	];

	StyleInitialized();
}
void SSlaiGameOptionWidget::StyleInitialized()
{
	//set JaCheckBox
	JaCheckBox->SetUncheckedImage(&MenuStyle->UnCheckedBoxBrush);
	JaCheckBox->SetUncheckedHoveredImage(&MenuStyle->UnCheckedBoxBrush);
	JaCheckBox->SetUncheckedPressedImage(&MenuStyle->UnCheckedBoxBrush);
	JaCheckBox->SetCheckedHoveredImage(&MenuStyle->CheckedBoxBrush);
	JaCheckBox->SetCheckedPressedImage(&MenuStyle->CheckedBoxBrush);

	//set EnCheckBox
	EnCheckBox->SetUncheckedImage(&MenuStyle->UnCheckedBoxBrush);
	EnCheckBox->SetUncheckedHoveredImage(&MenuStyle->UnCheckedBoxBrush);
	EnCheckBox->SetUncheckedPressedImage(&MenuStyle->UnCheckedBoxBrush);
	EnCheckBox->SetCheckedHoveredImage(&MenuStyle->CheckedBoxBrush);
	EnCheckBox->SetCheckedPressedImage(&MenuStyle->CheckedBoxBrush);

	switch (SlaiDataHandle::Get()->CurrentCulture) {
		case ECultureTeam::EN:
			EnCheckBox->SetIsChecked(ECheckBoxState::Checked);
			JaCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
			break;
		case ECultureTeam::JA:
			EnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
			JaCheckBox->SetIsChecked(ECheckBoxState::Checked);
			break;
	}

	MusicTextBlock->SetText(FText::FromString(FString("50%")));
}
void SSlaiGameOptionWidget::JaCeckBoxStateChanged(ECheckBoxState NewState)
{
	//set check
	EnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
	JaCheckBox->SetIsChecked(ECheckBoxState::Checked);
	SlaiDataHandle::Get()->ChangeLocalizetionCultrue(ECultureTeam::JA);
}
void SSlaiGameOptionWidget::EnCeckBoxStateChanged(ECheckBoxState NewState)
{
	//set check
	JaCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
	EnCheckBox->SetIsChecked(ECheckBoxState::Checked);
	SlaiDataHandle::Get()->ChangeLocalizetionCultrue(ECultureTeam::EN);
}
void SSlaiGameOptionWidget::MusicSliderChanged(float value)
{
	MusicTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(value * 100)) + FString("%")));
}
void SSlaiGameOptionWidget::SoundSliderChanged(float value)
{

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
