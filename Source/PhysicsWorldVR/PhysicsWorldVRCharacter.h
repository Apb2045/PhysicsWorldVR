// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "PhysicsWorldVRCharacter.generated.h"

UCLASS()
class PHYSICSWORLDVR_API APhysicsWorldVRCharacter : public ACharacter
{
	GENERATED_BODY()
    
public:
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
    UCameraComponent* FirstPersonCameraComponent;
    
    /** Pawn mesh: 1st person view (arms; seen only by self) */
    UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
    USkeletalMeshComponent* FirstPersonMesh;
    
	// Sets default values for this character's properties
	APhysicsWorldVRCharacter();
    
    APhysicsWorldVRCharacter(const FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
    
protected:
    
	void MoveRight(float Val);
	void MoveForward(float Val);
};
