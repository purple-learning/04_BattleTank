// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"



ATank* ATankPlayerController::GetControlledTank() const {

		return Cast<ATank>(GetPawn());
}



void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("No Tank"));
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Freindly Tank: %s"), *(ControlledTank->GetName()));


	


}

void ATankPlayerController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
	AimtowardsCrosshairs();
	//UE_LOG(LogTemp, Warning, TEXT("Tick"));
	//Tick
	//super
	//Aim towardsCrosshair();
}


void ATankPlayerController::AimtowardsCrosshairs() {

	if (!GetControlledTank())
		return;
	
	FVector Hitlocation;
	if (GetSightRayHitLocation(Hitlocation)) {
		UE_LOG(LogTemp, Warning, TEXT("Location is %s"), *(Hitlocation.ToString()));
		//TODO tell controlled tank to aim at this point
		// Get world location through crosshair.
		// If it hits the landscape
		//tell the controler to hit something.
	}

}
//Get World location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const {

	HitLocation = FVector(1.0);
	return true;
}