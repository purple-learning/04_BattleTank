// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurrent.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurrent : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
		void shiftTurrent(float);

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPersecond = 30;
	UPROPERTY(EditAnywhere, Category = Setup)
		float LeftMostDistance= -120.0;
	UPROPERTY(EditAnywhere, Category = Setup)
		float RightMostDistance = 120.0;
	
	
	
};
