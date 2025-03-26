// Fill out your copyright notice in the Description page of Project Settings.


#include "SpikePlayerAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

USpikePlayerAnimInstance::USpikePlayerAnimInstance()
	:MovingThreshould(3.f),
	JumpingThreshould(100.0f)
{

}

void USpikePlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Owner = Cast<ACharacter>(GetOwningActor());
	if (Owner)
	{
		Movement = Owner->GetCharacterMovement();
	}

}

void USpikePlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (Movement)
	{
		const FTransform& Transform = Owner->GetRootComponent()->GetComponentTransform();
		const FVector Forward = Transform.GetUnitAxis(EAxis::X);
		const FVector Right = Transform.GetUnitAxis(EAxis::Y);

		Velocity = Movement->Velocity;

		APlayerController* PlayerController = Cast<APlayerController>(Owner->GetController());
		if (PlayerController)
		{
			PitchAngle = PlayerController->PlayerCameraManager->GetCameraRotation().Pitch;
		}

		FowardSpeed = Forward.Dot(Velocity);
		RightSpeed = Right.Dot(Velocity);

		float GroundSpeed = Velocity.Size2D();
		bIsIdle = GroundSpeed < MovingThreshould;
		bIsFalling = Movement->IsFalling();
		bIsJumping = bIsJumping & (Velocity.Z > JumpingThreshould);
	}
}
