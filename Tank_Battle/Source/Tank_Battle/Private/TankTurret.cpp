// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::Rotate(float RotSpeed)
{
	RotSpeed = FMath::Clamp<float>(RotSpeed, -1, +1);
	auto RotationChange = RotSpeed * MaxDegreesPerSecond* GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, Rotation, 0));


}


