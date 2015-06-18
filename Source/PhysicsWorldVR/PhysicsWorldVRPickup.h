// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PhysicsWorldVRPickup.generated.h"

UCLASS()
class PHYSICSWORLDVR_API APhysicsWorldVRPickup : public AActor
{	 
public:
	//I needed to put the public identifier because GENERATED_UCLASS_BODY is public with out the identifier
	//so I had to do this in order to keep the code consistent with the change.
	GENERATED_BODY()
	
	//EditDefaultsOnly means can only be edited in property windows by archetypes aka blueprint assets
	UPROPERTY(EditDefaultsOnly, Category = Mesh)
	class UStaticMeshComponent* MeshComp;

	UPROPERTY(EditDefaultsOnly, Category = Sound)
	class USoundCue* PickupSound;
	
public:

	 //******************from SUsableActor.h

	 APhysicsWorldVRPickup(const FObjectInitializer& ObjectInitializer);

	 /* Player is looking at */
	 virtual void OnBeginFocus();

	 /* Player is no longer looking at */
	 virtual void OnEndFocus();

	 /* Called when player interacts with object */
	 virtual void OnUsed(APawn* InstigatorPawn);

	 //*****************from SPickupActor.h

	 void BeginPlay() override;

//	 void OnUsed(APawn* InstigatorPawn) override;


};
