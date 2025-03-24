// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "SpikePlayerAnimInstance.generated.h"

/**
 *
 */
UCLASS()
class SPIKE_API USpikePlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	USpikePlayerAnimInstance();

protected:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	TObjectPtr<ACharacter> Owner;
	TObjectPtr<class UCharacterMovementComponent> Movement;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	FVector Velocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	float GroundSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	float MovingThreshould;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	float JumpingThreshould;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	uint8 bIsIdle : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	uint8 bIsJumping: 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	uint8 bIsFalling : 1;

};
