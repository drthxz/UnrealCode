// Fill out your copyright notice in the Description page of Project Settings.

#include "SlaiStyle.h"
#include "SlateStyleRegistry.h"
#include "SlateGameResources.h"

TSharedPtr<class FSlateStyleSet> SlaiStyle::SlaiStyleInstence = NULL;

void SlaiStyle::Initialze()
{
	// check whether the StyleSetInstance hasn't been set yet.
	if (!SlaiStyleInstence.IsValid()) {
		SlaiStyleInstence = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*SlaiStyleInstence);
	}
}

FName SlaiStyle::GetStyleSetName()
{
	const static FName StyleName(TEXT("BPSlaiMenuStyle"));
	return StyleName;
}

void SlaiStyle::ShutDown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*SlaiStyleInstence);
	ensure(SlaiStyleInstence.IsUnique());
	SlaiStyleInstence.Reset();
}

const ISlateStyle & SlaiStyle::Get()
{
	return *SlaiStyleInstence;
}

TSharedRef<class FSlateStyleSet> SlaiStyle::Create()
{
	TSharedRef<class FSlateStyleSet> styleRef = FSlateGameResources::New(SlaiStyle::GetStyleSetName(), "/Game/UI/Style", "/Game/UI/Style");
	styleRef->Set("MenuItemFont", FSlateFontInfo("Roboto-Regular.ttf", 50));
	return styleRef;
}
