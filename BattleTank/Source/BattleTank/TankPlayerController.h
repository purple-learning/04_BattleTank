// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
 public:
	 ATank* GetControlledTank() const;

	 void BeginPlay() override;

	 void Tick(float) override;
 
private:
      //Moves the tank barrel so that a shot would hit where the crosshair interesects the world.
	 void AimtowardsCrosshairs();
	 bool GetSightRayHitLocation(FVector&) const;
	
};
