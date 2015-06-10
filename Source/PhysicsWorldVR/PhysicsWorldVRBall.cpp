// Fill out your copyright notice in the Description page of Project Settings.

#include "PhysicsWorldVR.h"
#include "PhysicsWorldVRBall.h"


// Sets default values
APhysicsWorldVRBall::APhysicsWorldVRBall(const FObjectInitializer& ObjectInitializer)
    :Super(ObjectInitializer)
{

    static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
                                            
    
    Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball0"));
    Ball->SetStaticMesh(StaticMesh.Object);
    Ball->BodyInstance.SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);
    Ball->SetSimulatePhysics(true);

}

// Called when the game starts or when spawned
void APhysicsWorldVRBall::BeginPlay()
{
	Super::BeginPlay();
	
}



