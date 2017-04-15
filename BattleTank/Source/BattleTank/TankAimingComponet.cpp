// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankAimingComponet.h"


// Sets default values for this component's properties
UTankAimingComponet::UTankAimingComponet()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;//TODO should this Tick.

	// ...
}


void UTankAimingComponet::SetBarrelRefrence(UTankBarrel* BarrelToSet) {
	Barrel = BarrelToSet;
}



// Called when the game starts
void UTankAimingComponet::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponet::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponet::AimAt(FVector WorldSpaceAim, float LaunchSpeed) {
	//UTankAimingComponet
	//auto TankName = GetOwner()->GetName();
	//auto BarrelLocation = Barrel->GetComponentLocation();
	//UE_LOG(LogTemp, Warning, TEXT("%s Aiming at %s from %s"), *TankName, *(WorldSpaceAim.ToString()), *(BarrelLocation.ToString())   );
	//UE_LOG(LogTemp, Warning, TEXT("Firing at %f"), LaunchSpeed);
	FVector TossVlocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("BarrelTip"));
	if (!Barrel)
		return;
	if (UGameplayStatics::SuggestProjectileVelocity(this,TossVlocity,StartLocation,WorldSpaceAim,LaunchSpeed,false,0,0, ESuggestProjVelocityTraceOption::DoNotTrace) ) {
		auto AimDirection = TossVlocity.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("Aiming at %s"), *AimDirection.ToString());
		MoveBarrel(AimDirection);
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("Aiming Soultion found: %f"), Time);
	}

	else {
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT(" No Aiming Soultion found: %f"), Time);
	}
}

void UTankAimingComponet::MoveBarrel(FVector Direction) {
	//wouk-out iddffernce betwen current barrel rotation and Aim Direction
	//Move the barrel the right amount this frame
	//Gvven a max elevaton speed

	auto BarrelRot = Barrel->GetForwardVector().Rotation();
	auto AimRot = Direction.Rotation();
	auto DeltaRotator = AimRot - BarrelRot;
	//UE_LOG(LogTemp, Warning, TEXT("Aiming Rot at %s"), *AimRot.ToString());

	Barrel->Elevate(DeltaRotator.Pitch);
}