// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "SpikeGameMode.generated.h"

/**
 *
 */
UCLASS()
class SPIKE_API ASpikeGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ASpikeGameMode();

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;


};
