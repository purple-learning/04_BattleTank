// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"


UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float);
	
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPersecond = 20.0;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegrees = 40.0;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegrees = 0.0;
	
};
