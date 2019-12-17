// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Slate.h"

/**
 * 
 */
class SLAICOURSE_API SlaiStyle
{
public:
	static void Initialze();
	static FName GetStyleSetName();
	static void ShutDown();
	static const ISlateStyle& Get();

private:
	static TSharedRef<class FSlateStyleSet> Create();
	static TSharedPtr<class FSlateStyleSet> SlaiStyleInstence;
};
