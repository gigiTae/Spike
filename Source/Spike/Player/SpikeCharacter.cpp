// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/SpikeCharacter.h"

// Sets default values
ASpikeCharacter::ASpikeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Network
	bReplicates = true;
}

// Called when the game starts or when spawned
void ASpikeCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASpikeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpikeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


}

