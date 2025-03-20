// Fill out your copyright notice in the Description page of Project Settings.
#include "Player/SpikeCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"

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

	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();
		UEnhancedInputLocalPlayerSubsystem* InputSubsystem = LocalPlayer ?
			LocalPlayer->GetSubsystem< UEnhancedInputLocalPlayerSubsystem>() : nullptr;

		if (InputSubsystem)
		{
			InputSubsystem->AddMappingContext(InputMappingContext, 0);
		}
	}
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

	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (EnhancedInput)
	{
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Triggered, this, ACharacter::Jump);
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Completed, this, ACharacter::StopJumping);
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, ASpikeCharacter::Move);
	}
}

void ASpikeCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller)
	{
		const FRotator Rotation = Controller->GetControlRotation();


		const FVector Forward = GetActorForwardVector();
		const FVector Right = GetActorRightVector();

		AddMovementInput(Forward, MovementVector.X);
		AddMovementInput(Right, MovementVector.Y);
	}

}


