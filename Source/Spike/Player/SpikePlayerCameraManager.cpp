// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/SpikePlayerCameraManager.h"
#include "SpikePlayerCameraManager.h"

ASpikePlayerCameraManager::ASpikePlayerCameraManager()
{
	// 카메라 Pitch 각도 제한
	ViewPitchMin = -60;
	ViewPitchMax = 45;
}
