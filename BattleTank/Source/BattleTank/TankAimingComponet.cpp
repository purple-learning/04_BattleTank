// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponet.h"


// Sets default values for this component's properties
UTankAimingComponet::UTankAimingComponet()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponet::SetBarrelRefrence(UStaticMeshComponent* BarrelToSet) {
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

void UTankAimingComponet::AimAt(FVector WorldSpaceAim) {
	//UTankAimingComponet
	auto TankName = GetOwner()->GetName();
	auto BarrelLocation = Barrel->GetComponentLocation();
	UE_LOG(LogTemp, Warning, TEXT("%s Aiming at %s from %s"), *TankName, *(WorldSpaceAim.ToString()), *(BarrelLocation.ToString())   );
}