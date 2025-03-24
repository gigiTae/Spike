// Fill out your copyright notice in the Description page of Project Settings.

#include "SpikePlayerController.h"
#include "SpikePlayerCameraManager.h"

ASpikePlayerController::ASpikePlayerController()
{
	PlayerCameraManagerClass = ASpikePlayerCameraManager::StaticClass();
}

void ASpikePlayerController::SpawnPlayerCameraManager()
{
	Super::SpawnPlayerCameraManager();

}
