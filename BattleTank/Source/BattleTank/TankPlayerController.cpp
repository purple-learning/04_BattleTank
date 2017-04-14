// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

/*
Needs heavy refactoring later.
*/


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
		//UE_LOG(LogTemp, Warning, TEXT("Hit location is %s"), *(Hitlocation.ToString()));
		//TODO tell controlled tank to aim at this point
		// Get world location through crosshair.
		// If it hits the landscape
		//tell the controler to hit something.

		GetControlledTank()->AimAt(Hitlocation);
	}

}
//Get World location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const {

	//Find the crosshair position.
	int32 ViewportSizex, ViewportSizey;
	GetViewportSize(ViewportSizex, ViewportSizey);
	auto ScreenLocation = FVector2D(ViewportSizex*crossHairXlocation, ViewportSizey*crossHairYlocation);
	//UE_LOG(LogTemp, Warning, TEXT("Screen location is %s"), *(ScreenLocation.ToString()));
	//"De-project the sreen position of the crosshair to a world direction //ttps://docs.unrealengine.com/latest/INT/API/Runtime/Engine/GameFramework/APlayerController/DeprojectScreenPositionToWorld/index.html/
	FVector LookDirection;
	
	
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		//Line-trace along that direaction, and see what we hit.(up to max range)
		//GetGetLookVectorHitLocationWorld()->LineTraceSingleByChannel
		GetLookVectorHitLocation(LookDirection,HitLocation);

		return true;
	}


	//Line-trace along that direaction, and see what we hit.(up to max range)

	//HitLocation = FVector(1.0);
	return false; //Fixed booleans.
}

//Chnge to bool if problems occurs. Bool looks unnescary.
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& Lookdirection) const {
	
	FVector CameraWorldDirection;

	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldDirection, Lookdirection);
	//UE_LOG(LogTemp, Warning, TEXT("Look Direction is %s"), *(Lookdirection.ToString()));
	//return false;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector Lookdirection, FVector& Hitlocation) const {
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (Lookdirection * MaxRange); //Unit directional vector times a constant.
	if (GetWorld()->LineTraceSingleByChannel(HitResult,StartLocation,EndLocation,ECollisionChannel::ECC_Visibility )){
		Hitlocation=HitResult.Location;
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation is %s"), *(HitResult.Location.ToString()));
		return true;
       }
	
	Hitlocation = FVector(0.0);
	//GetWorld()->LineTraceSingleByChannel
	return false;
}