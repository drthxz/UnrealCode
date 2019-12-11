// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class SLAICOURSE_API SlaiIntermation
{
public:
	static void Register(FText value) {
		return;
	}
};

#define LOCTEXT_NAMESPACE "SlaiMenu"

SlaiIntermation::Register(LOCTEXT("Menu", "Menu"));//メニュー
SlaiIntermation::Register(LOCTEXT("StartGame", "StartGame"));//ゲームスタート
SlaiIntermation::Register(LOCTEXT("GameOption", "GameOption"));//オプション
SlaiIntermation::Register(LOCTEXT("QuitGame", "QuitGame"));//ゲーム終了

SlaiIntermation::Register(LOCTEXT("NewGame", "NewGame"));//最初から始める
SlaiIntermation::Register(LOCTEXT("Load", "Load"));//ロード

SlaiIntermation::Register(LOCTEXT("Save", "Save"));//セーフ

SlaiIntermation::Register(LOCTEXT("SaveName", "SaveName"));//セーフ名
SlaiIntermation::Register(LOCTEXT("EnterGame", "EnterGame"));//ゲームに入る
SlaiIntermation::Register(LOCTEXT("EnterSave", "EnterSave"));//セーフから始まる
SlaiIntermation::Register(LOCTEXT("SaveNameHint", "Input Save Name!");//セーフ名を入力してください
SlaiIntermation::Register(LOCTEXT("NameRepeatedHint", "Save Name Repeated!");//セーフ名を入力を入力してください

SlaiIntermation::Register(LOCTEXT("Japanese", "Japanese"));//ja
SlaiIntermation::Register(LOCTEXT("English", "English"));//en
SlaiIntermation::Register(LOCTEXT("Music", "Music"));//音楽
SlaiIntermation::Register(LOCTEXT("Sound", "Sound"));//サウンド

SlaiIntermation::Register(LOCTEXT("GoBack", "GoBack"));//戻る

#undef LOCTEXT_NAMESPACE

#define LOCTEXT_NAMESPACE "SlAiGame"


SlaiIntermation::Register(LOCTEXT("E", "E"));//ｶｫ
SlaiIntermation::Register(LOCTEXT("S", "S"));//ﾄﾏ
SlaiIntermation::Register(LOCTEXT("W", "W"));//ﾎ・
SlaiIntermation::Register(LOCTEXT("N", "N"));//ｱｱ

SlaiIntermation::Register(LOCTEXT("Player", "Player"));//プレイヤー
SlaiIntermation::Register(LOCTEXT("Enemy", "Enemy"));//敵

SlaiIntermation::Register(LOCTEXT("EnemyDialogue", ": Fight with me !"));//
SlaiIntermation::Register(LOCTEXT("Send", "Send"));//

SlaiIntermation::Register(LOCTEXT("GameOption", "GameOption"));//オプション
SlaiIntermation::Register(LOCTEXT("SaveGame", "SaveGame"));//セーフする
SlaiIntermation::Register(LOCTEXT("SaveCompleted", "SaveCompleted"));//
SlaiIntermation::Register(LOCTEXT("QuitGame", "QuitGame"));//ゲーム終了
SlaiIntermation::Register(LOCTEXT("GoBack", "GoBack"));//戻る


#undef LOCTEXT_NAMESPACE
