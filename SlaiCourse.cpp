// Fill out your copyright notice in the Description page of Project Settings.

#include "SlaiCourse.h"
#include "Modules/ModuleManager.h"
#include "SlaiStyle.h"



void FSlaiCourceModule::StartupModule()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(SlaiStyle::GetStyleSetName());
	SlaiStyle::Initialze();
}

void FSlaiCourceModule::ShutdownModule()
{
	SlaiStyle::ShutDown();
}

IMPLEMENT_PRIMARY_GAME_MODULE(FSlaiCourceModule, SlaiCourse, "SlaiCourse");