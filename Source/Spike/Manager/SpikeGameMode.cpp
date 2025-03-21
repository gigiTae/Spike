// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/SpikeGameMode.h"
#include "Player/SpikeCharacter.h"
#include "Player/SpikePlayerController.h"

ASpikeGameMode::ASpikeGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/BP_SpikeCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	PlayerControllerClass = ASpikePlayerController::StaticClass();
}

void ASpikeGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	UE_LOG(LogTemp, Log, TEXT("Init SpikeGameMode"));
}
