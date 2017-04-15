// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"




void UTankBarrel::Elevate(float degrees) {
	degrees = FMath::Clamp<float>(degrees, -1, 1);
	auto ElevationChange = degrees *  MaxDegreesPersecond * GetWorld()->DeltaTimeSeconds;//Frame indepdence.
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	//FMath::Clamp()
	SetRelativeRotation(FRotator(FMath::Clamp(RawNewElevation,MinElevationDegrees,MaxElevationDegrees), 0, 0));

	//UE_LOG(LogTemp, Warning, TEXT("Floaty"));
} // Move the barrel the right amount this frame
//Gvven a max elevaton speed