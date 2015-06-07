// Fill out your copyright notice in the Description page of Project Settings.

#include "PhysicsWorldVR.h"
#include "PhysicsWorldVRCharacter.h"

// Sets default values
APhysicsWorldVRCharacter::APhysicsWorldVRCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APhysicsWorldVRCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APhysicsWorldVRCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void APhysicsWorldVRCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
    InputComponent->BindAxis("MoveForward", this, &APhysicsWorldVRCharacter::MoveForward);
    InputComponent->BindAxis("MoveRight", this, &APhysicsWorldVRCharacter::MoveRight);
    
}

void APhysicsWorldVRCharacter::MoveForward(float Val)
{
    if (Controller && Val != 0.f)
    {
        // Limit pitch when walking or falling
        const bool bLimitRotation = (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling());
        const FRotator Rotation = bLimitRotation ? GetActorRotation() : Controller->GetControlRotation();
        const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
        
        AddMovementInput(Direction, Val);
    }
}
void APhysicsWorldVRCharacter::MoveRight(float Val)
{
    if (Val != 0.f)
    {
        const FRotator Rotation = GetActorRotation();
        const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
        AddMovementInput(Direction, Val);
    }
}