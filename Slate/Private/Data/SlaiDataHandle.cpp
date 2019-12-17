// Fill out your copyright notice in the Description page of Project Settings.

#include "SlaiDataHandle.h"
#include "Internationalization.h"

TSharedPtr<SlaiDataHandle> SlaiDataHandle::DataInstance = NULL;

SlaiDataHandle::SlaiDataHandle()
{
	CurrentCulture = ECultureTeam::JA;
}

void SlaiDataHandle::Initialize()
{
	if (DataInstance.IsValid()) {
		DataInstance = Create();
	}
}

TSharedPtr<SlaiDataHandle> SlaiDataHandle::Get()
{
	Initialize();
	return DataInstance;
}

void SlaiDataHandle::ChangeLocalizetionCultrue(ECultureTeam Culture)
{
	switch (Culture)
	{
	case ECultureTeam::EN:
		FInternationalization::Get().SetCurrentCulture(TEXT("en"));
		break;
	case ECultureTeam::JA:
		FInternationalization::Get().SetCurrentCulture(TEXT("ja"));
		break;
	}
	CurrentCulture = Culture;
}

TSharedRef<SlaiDataHandle> SlaiDataHandle::Create()
{
	TSharedRef<SlaiDataHandle>DataRef = MakeShareable(new SlaiDataHandle());
	return DataRef;
}
