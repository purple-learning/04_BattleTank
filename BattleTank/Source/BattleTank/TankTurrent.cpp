// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurrent.h"


void UTankTurrent::shiftTurrent(float realtivespeed) {
 realtivespeed = FMath::Clamp<float>(realtivespeed, -1.0, 1.0);
 auto directionchange = realtivespeed*MaxDegreesPersecond*GetWorld()->DeltaTimeSeconds;
 auto rawnewdistance = RelativeRotation.Yaw + directionchange;
 //SetRelativeRotation(FRotator(0, FMath::Clamp(rawnewdistance, LeftMostDistance, RightMostDistance), 0));
 SetRelativeRotation(FRotator(0,rawnewdistance, 0));
}

