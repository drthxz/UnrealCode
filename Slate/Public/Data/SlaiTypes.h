// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM()
enum class ECultureTeam : uint8 {
	EN,
	JA,
};

//Menu button
namespace EMenuItem {
	enum Type {
		None,
		StartGame,
		GameOption,
		QuitGame,
		NewGame,
		Load,
		StartGameGoBack,
		GameOptionGoBack,
		NewGameGoBack,
		ChooseGoBack,
		EnterGame,
		EnterSave,
	};
}