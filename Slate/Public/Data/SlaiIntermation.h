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

SlaiIntermation::Register(LOCTEXT("Menu", "Menu"));//���j���[
SlaiIntermation::Register(LOCTEXT("StartGame", "StartGame"));//�Q�[���X�^�[�g
SlaiIntermation::Register(LOCTEXT("GameOption", "GameOption"));//�I�v�V����
SlaiIntermation::Register(LOCTEXT("QuitGame", "QuitGame"));//�Q�[���I��

SlaiIntermation::Register(LOCTEXT("NewGame", "NewGame"));//�ŏ�����n�߂�
SlaiIntermation::Register(LOCTEXT("Load", "Load"));//���[�h

SlaiIntermation::Register(LOCTEXT("Save", "Save"));//�Z�[�t

SlaiIntermation::Register(LOCTEXT("SaveName", "SaveName"));//�Z�[�t��
SlaiIntermation::Register(LOCTEXT("EnterGame", "EnterGame"));//�Q�[���ɓ���
SlaiIntermation::Register(LOCTEXT("EnterSave", "EnterSave"));//�Z�[�t����n�܂�
SlaiIntermation::Register(LOCTEXT("SaveNameHint", "Input Save Name!");//�Z�[�t������͂��Ă�������
SlaiIntermation::Register(LOCTEXT("NameRepeatedHint", "Save Name Repeated!");//�Z�[�t������͂���͂��Ă�������

SlaiIntermation::Register(LOCTEXT("Japanese", "Japanese"));//ja
SlaiIntermation::Register(LOCTEXT("English", "English"));//en
SlaiIntermation::Register(LOCTEXT("Music", "Music"));//���y
SlaiIntermation::Register(LOCTEXT("Sound", "Sound"));//�T�E���h

SlaiIntermation::Register(LOCTEXT("GoBack", "GoBack"));//�߂�

#undef LOCTEXT_NAMESPACE

#define LOCTEXT_NAMESPACE "SlAiGame"


SlaiIntermation::Register(LOCTEXT("E", "E"));//��
SlaiIntermation::Register(LOCTEXT("S", "S"));//��
SlaiIntermation::Register(LOCTEXT("W", "W"));//΁E
SlaiIntermation::Register(LOCTEXT("N", "N"));//��

SlaiIntermation::Register(LOCTEXT("Player", "Player"));//�v���C���[
SlaiIntermation::Register(LOCTEXT("Enemy", "Enemy"));//�G

SlaiIntermation::Register(LOCTEXT("EnemyDialogue", ": Fight with me !"));//
SlaiIntermation::Register(LOCTEXT("Send", "Send"));//

SlaiIntermation::Register(LOCTEXT("GameOption", "GameOption"));//�I�v�V����
SlaiIntermation::Register(LOCTEXT("SaveGame", "SaveGame"));//�Z�[�t����
SlaiIntermation::Register(LOCTEXT("SaveCompleted", "SaveCompleted"));//
SlaiIntermation::Register(LOCTEXT("QuitGame", "QuitGame"));//�Q�[���I��
SlaiIntermation::Register(LOCTEXT("GoBack", "GoBack"));//�߂�


#undef LOCTEXT_NAMESPACE
