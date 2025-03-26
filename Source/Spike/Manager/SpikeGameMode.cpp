// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/SpikeGameMode.h"
#include "Player/SpikeCharacter.h"
#include "Player/SpikePlayerController.h"
#include "Spike.h"

ASpikeGameMode::ASpikeGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/BP_SpikeCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	PlayerControllerClass = ASpikePlayerController::StaticClass();
}

void ASpikeGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
}

void ASpikeGameMode::StartPlay()
{
	SPIKE_LOG(LogSpikeNetwork, Log, TEXT("%s"), TEXT("Begin"));
	Super::StartPlay();
	SPIKE_LOG(LogSpikeNetwork, Log, TEXT("%s"), TEXT("End"));
}

void ASpikeGameMode::PostLogin(APlayerController* NewPlayer)
{
	SPIKE_LOG(LogSpikeNetwork, Log, TEXT("%s"), TEXT("Begin"));
	Super::PostLogin(NewPlayer);
	SPIKE_LOG(LogSpikeNetwork, Log, TEXT("%s"), TEXT("End"));
}

void ASpikeGameMode::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	SPIKE_LOG(LogSpikeNetwork, Log, TEXT("%s"), TEXT("Begin"));
	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
	SPIKE_LOG(LogSpikeNetwork, Log, TEXT("%s"), TEXT("End"));
}

APlayerController* ASpikeGameMode::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	SPIKE_LOG(LogSpikeNetwork, Log, TEXT("%s"), TEXT("Begin"));
	APlayerController* PlayerController = Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);
	SPIKE_LOG(LogSpikeNetwork, Log, TEXT("%s"), TEXT("End"));
	return PlayerController;
}
