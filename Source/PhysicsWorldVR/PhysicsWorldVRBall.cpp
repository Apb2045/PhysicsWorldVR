// Fill out your copyright notice in the Description page of Project Settings.

#include "PhysicsWorldVR.h"
#include "PhysicsWorldVRBall.h"


// Sets default values

//	APhysicsWorldVRBall(const FObjectInitializer& ObjectInitializer);

APhysicsWorldVRBall::APhysicsWorldVRBall(const FObjectInitializer& ObjectInitializer)
    :Super(ObjectInitializer)
{

    static ConstructorHelpers::FObjectFinder<UStaticMesh> BallMesh(TEXT("/Game/Rolling/Meshes/BallMesh.Ballmesh"));
    Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball0"));
    Ball->SetStaticMesh(BallMesh.Object);
    Ball->BodyInstance.SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);
    Ball->SetSimulatePhysics(true);
    
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APhysicsWorldVRBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
/*
void APhysicsWorldVRBall::Tick( float DeltaTime )
{
    
	Super::Tick( DeltaTime );
    
    
    FVector NewLocation = GetActorLocation();
    float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
    NewLocation.Z += DeltaHeight * 200.0f;       //Scale our height by a factor of 20
    RunningTime += DeltaTime;
    SetActorLocation(NewLocation);
    
*/

    /*
    FVector NewLocation = GetActorLocation();
    
    while (NewLocation.Z > 75.f)
    {

        static const float DeltaHeight = -1.f;
        NewLocation.Z +=DeltaHeight*DeltaTime;
        SetActorLocation(NewLocation);
    }
        
    */

//}


