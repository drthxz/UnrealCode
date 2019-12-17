// Fill out your copyright notice in the Description page of Project Settings.

#include "SSlaiMenuItemWidget.h"
#include "SlateOptMacros.h"
#include "SlaiStyle.h"
#include "MenuWidgetStyle.h"
#include "SBox.h"
#include "SImage.h"
#include "STextBlock.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlaiMenuItemWidget::Construct(const FArguments& InArgs)
{
	//get MenuStyle
	MenuStyle = &SlaiStyle::Get().GetWidgetStyle<FMenuStyle>("BPSlaiMenuStyle");

	OnClicked = InArgs._OnClicked;
	ItemType = InArgs._ItemType.Get();

	ChildSlot
	[
		SNew(SBox)
		.WidthOverride(500.f)
		.HeightOverride(100.f)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SImage)
				.Image(&MenuStyle->MenuItemBrush)
				.ColorAndOpacity(this,&SSlaiMenuItemWidget::GetTintColor)
			]

			+SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(InArgs._ItemText)
				.Font(MenuStyle->Font_50)
			]
		]
	];
	IsMouseButtonDown = false;
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SSlaiMenuItemWidget::OnMouseButtonDown(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent)
{
	IsMouseButtonDown = true;
	return FReply::Handled();
}

FReply SSlaiMenuItemWidget::OnMouseButtonUp(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent)
{
	if (IsMouseButtonDown) {
		IsMouseButtonDown = false;
		OnClicked.ExecuteIfBound(ItemType);
	}
	return FReply::Handled();
}

void SSlaiMenuItemWidget::OnMouseLeave(const FPointerEvent & MouseEvent)
{
	IsMouseButtonDown = false;
}

FSlateColor SSlaiMenuItemWidget::GetTintColor() const
{
	if (IsMouseButtonDown) {
		return FLinearColor(1.f,0.1f,0.1f,0.5f);
	}
	return FLinearColor(1.f, 1.f, 1.f, 1.f);
}
