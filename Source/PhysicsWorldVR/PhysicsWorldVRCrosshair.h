// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "PhysicsWorldVRCrosshair.generated.h"

/**
 * 
 */
UCLASS()
class PHYSICSWORLDVR_API APhysicsWorldVRCrosshair : public AHUD
{
	GENERATED_BODY()
    virtual void DrawHUD() OVERRIDE;
    
public:
    APhysicsWorldVRCrosshair(const FObjectInitializer& ObjectInitializer);
    
    
private:
    UTexture2D* CrosshairTex;
    
	
	
	
};
