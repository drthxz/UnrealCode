// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "SlateWidgetStyleContainerBase.h"
#include "SlateBrush.h"
#include "SlateFontInfo.h"

#include "MenuWidgetStyle.generated.h"


/**
 * 
 */
USTRUCT()
struct SLAICOURSE_API FMenuStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FMenuStyle();
	virtual ~FMenuStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FMenuStyle& GetDefault();

	//HUB Background
	UPROPERTY(EditAnywhere,Category=MenuHUD)
		FSlateBrush MenuHUDBackgroundBrush;

	//Menu Background
	UPROPERTY(EditAnywhere, Category = Menu)
		FSlateBrush MenuBackgroundBrush;
	//Menu LeftIcon
	UPROPERTY(EditAnywhere, Category = Menu)
		FSlateBrush LeftIconBrush;
	//Menu RightIocn
	UPROPERTY(EditAnywhere, Category = Menu)
		FSlateBrush RightIocnBrush;
	//Menu TitleBorder
	UPROPERTY(EditAnywhere, Category = Menu)
		FSlateBrush TitleBorderBrush;

	//Menu Item 
	UPROPERTY(EditAnywhere, Category = MenuItem)
		FSlateBrush MenuItemBrush;
	//font 50 ,40 ,30
	UPROPERTY(EditAnywhere, Category = Common)
		FSlateFontInfo Font_50;
	UPROPERTY(EditAnywhere, Category = Common)
		FSlateFontInfo Font_40;
	UPROPERTY(EditAnywhere, Category = Common)
		FSlateFontInfo Font_30;

	//BlackColor WhiteColor
	UPROPERTY(EditAnywhere, Category = Common)
		FLinearColor FontColor_White;
	UPROPERTY(EditAnywhere, Category = Common)
		FLinearColor FontColor_Black;

	//Game Option
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSlateBrush GameOptionBGBrush;

	//no check
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSlateBrush UnCheckedBoxBrush;
	//check
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSlateBrush CheckedBoxBrush;
	//SliderBar 
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSlateBrush SliderBarBrush;
	//Slider
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSliderStyle SliderStyle;
};

/**
 */
UCLASS(hidecategories=Object, MinimalAPI)
class UMenuWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FMenuStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};
