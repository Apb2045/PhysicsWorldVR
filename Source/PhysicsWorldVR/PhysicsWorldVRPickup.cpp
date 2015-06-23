// Fill out your copyright notice in the Description page of Project Settings.

#include "PhysicsWorldVR.h"
#include "PhysicsWorldVRPickup.h"


// Sets default values
APhysicsWorldVRPickup::APhysicsWorldVRPickup(const FObjectInitializer& ObjectInitializer)
	 :Super(ObjectInitializer)
{
	 MeshComp = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	 RootComponent = MeshComp;
	
	 MeshComp->SetSimulatePhysics(true);
	
	 //SetRemoteRoleForBackwardsCompat(ROLE_SimulatedProxy);
	 
	 bReplicates = true;
	 bReplicateMovement = true;
	 
}

void APhysicsWorldVRPickup::BeginPlay()
{
	 Super::BeginPlay();

	 // TODO: Remove Hack to workaround constructor call not currently working.
	 MeshComp->SetSimulatePhysics(true);
}


// Called when the game starts or when spawned
void APhysicsWorldVRPickup::OnBeginFocus()
{
	 // Used by custom PostProcess to render outlines
	 MeshComp->SetRenderCustomDepth(true);
}



// Called every frame
void APhysicsWorldVRPickup::OnEndFocus()
{
	 // Used by custom PostProcess to render outlines
	 MeshComp->SetRenderCustomDepth(false);
}

void APhysicsWorldVRPickup::OnUsed(APawn* InstigatorPawn)
{
	 
	 OnUsed(InstigatorPawn);

	 UGameplayStatics::PlaySoundAtLocation(this, PickupSound, GetActorLocation());
	 
}