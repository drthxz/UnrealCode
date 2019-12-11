// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlaiTypes.h"
#include "CoreMinimal.h"

/**
 * 
 */
class SLAICOURSE_API SlaiDataHandle
{
public:
	SlaiDataHandle();
	static void Initialize();
	static TSharedPtr<SlaiDataHandle> Get();

	//Change Language
	void ChangeLocalizetionCultrue(ECultureTeam Culture);

public:
	ECultureTeam CurrentCulture;

private:
	static TSharedRef<SlaiDataHandle> Create();

private:
	static TSharedPtr<SlaiDataHandle> DataInstance;
};
