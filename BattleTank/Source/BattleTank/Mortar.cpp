// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Mortar.h"


// Sets default values
AMortar::AMortar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMortar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMortar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

