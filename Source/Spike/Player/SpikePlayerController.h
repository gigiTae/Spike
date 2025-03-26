// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SpikePlayerController.generated.h"

/**
 *
 */
UCLASS()
class SPIKE_API ASpikePlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	ASpikePlayerController();

	virtual void SpawnPlayerCameraManager() override;

};
