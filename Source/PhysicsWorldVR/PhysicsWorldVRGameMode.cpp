// Fill out your copyright notice in the Description page of Project Settings.

#include "PhysicsWorldVR.h"
#include "PhysicsWorldVRCharacter.h"
#include "PhysicsWorldVRCrosshair.h"
#include "PhysicsWorldVRGameMode.h"


APhysicsWorldVRGameMode::APhysicsWorldVRGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnObject(TEXT("Blueprint'/Game/Blueprints/BP_PW_Character.BP_PW_Character_C'"));
    
    if (PlayerPawnObject.Class != NULL)
    {
        DefaultPawnClass = PlayerPawnObject.Class;
    }
    
    HUDClass = APhysicsWorldVRCrosshair::StaticClass();
    
   // Blueprint'/Game/Blueprints/BP_PW_Character.BP_PW_Character'
    //static ConstructorHelpers::FClassFinder<ACharacter> PlayerPawnBPClass(TEXT("Blueprint'/Game/BP_Character.BP_Character_C'"));
    //if (PlayerPawnBPClass.Class != NULL)
    //{
     //  DefaultPawnClass = PlayerPawnBPClass.Class;
    //}
    

}