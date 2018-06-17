// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank1PlayerController.h"
#include "Tank_Battle.h"



void ATank1PlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController NotPossesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Possesed: %s"), *(ControlledTank->GetName()));
	}
}

void ATank1PlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	
}

ATank* ATank1PlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATank1PlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}
	
	FVector OutHitLocation; //Out parameter
	if (GetSightRayHitLocation(OutHitLocation)) // Has Side-effect, is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Location %s"), *OutHitLocation.ToString());

	}
	
}
// Get World Location of line trace through crosshair, true if hits landscape
bool ATank1PlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;
}

