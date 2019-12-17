// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlaiTypes.h"
#include "Widgets/SCompoundWidget.h"


class SCheckBox;
class SSlider;
class STextBlock;
/**
 * 
 */
class SLAICOURSE_API SSlaiGameOptionWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlaiGameOptionWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	//
	void StyleInitialized();

	//checkBox Ja
	void JaCeckBoxStateChanged(ECheckBoxState NewState);
	//checkBox En
	void EnCeckBoxStateChanged(ECheckBoxState NewState);
	//music
	void MusicSliderChanged(float value);
	//sound
	void SoundSliderChanged(float value);

private:
	//get MenuStyle
	const struct FMenuStyle* MenuStyle;
	//get checkBox
	TSharedPtr<SCheckBox> EnCheckBox;
	TSharedPtr<SCheckBox> JaCheckBox;
	//Slider
	TSharedPtr<SSlider> MusicSlider;//music
	TSharedPtr<SSlider> SoundSlider;//sound
	//%
	TSharedPtr<STextBlock> MusicTextBlock;//music
	TSharedPtr<STextBlock> SoundTextBlock;//sound

};
