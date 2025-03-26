// Fill out your copyright notice in the Description page of Project Settings.

#include "SpikePlayerController.h"
#include "SpikePlayerCameraManager.h"
#include "Spike.h"


ASpikePlayerController::ASpikePlayerController()
{
	PlayerCameraManagerClass = ASpikePlayerCameraManager::StaticClass();
}

void ASpikePlayerController::BeginPlay()
{
	SPIKE_LOG(LogSpikeNetwork, Log, TEXT("%s"), TEXT("Begin"));

	Super::BeginPlay();

	SPIKE_LOG(LogSpikeNetwork, Log, TEXT("%s"), TEXT("End"));

}


void ASpikePlayerController::SpawnPlayerCameraManager()
{
	Super::SpawnPlayerCameraManager();

}
