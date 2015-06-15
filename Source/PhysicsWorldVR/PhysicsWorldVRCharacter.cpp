// Fill out your copyright notice in the Description page of Project Settings.

#include "PhysicsWorldVR.h"
#include "PhysicsWorldVRCharacter.h"


// Sets default values
APhysicsWorldVRCharacter::APhysicsWorldVRCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

APhysicsWorldVRCharacter::APhysicsWorldVRCharacter(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
    // Create a CameraComponent
    FirstPersonCameraComponent = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("FirstPersonCamera"));
    FirstPersonCameraComponent->AttachParent = GetCapsuleComponent();
    
    
    // Position the camera a bit above the eyes
    FirstPersonCameraComponent->RelativeLocation = FVector(0, 0, 50.0f + BaseEyeHeight);
    // Allow the pawn to control rotation.
    FirstPersonCameraComponent->bUsePawnControlRotation = true;
    
    // Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
    FirstPersonMesh = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("FirstPersonMesh"));
    FirstPersonMesh->SetOnlyOwnerSee(true);         // only the owning player will see this mesh
    FirstPersonMesh->AttachParent = FirstPersonCameraComponent;
    FirstPersonMesh->bCastDynamicShadow = false;
    FirstPersonMesh->CastShadow = false;
    GetMesh()->SetOwnerNoSee(true);
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
    check(InputComponent);
    
    InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
    InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
    
    //movements
    InputComponent->BindAxis("MoveForward", this, &APhysicsWorldVRCharacter::MoveForward);
    InputComponent->BindAxis("MoveRight", this, &APhysicsWorldVRCharacter::MoveRight);
    
    //look around
    InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
    InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

}

void APhysicsWorldVRCharacter::MoveForward(float Value)
{
    if (Value != 0.0f)
    {
        // Add movement in that direction
        AddMovementInput(GetActorForwardVector(), Value);
    }
}

void APhysicsWorldVRCharacter::MoveRight(float Value)
{
    if (Value != 0.0f)
    {
        // Add movement in that direction
        AddMovementInput(GetActorRightVector(), Value);
    }
}

