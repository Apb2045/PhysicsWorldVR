// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PhysicsWorldVRBall.generated.h"

UCLASS()
class PHYSICSWORLDVR_API APhysicsWorldVRBall : public AActor
{
	GENERATED_BODY()
    
    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Ball, meta = (AllowPrivateAccess = "true"))
    class UStaticMeshComponent * Ball;
	
public:	
	// Sets default values for this actor's properties
	APhysicsWorldVRBall(const FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
/*
    
public:
    FORCEINLINE class UStaticMeshComponent* GetBall() const { return Ball; }
*/
};
