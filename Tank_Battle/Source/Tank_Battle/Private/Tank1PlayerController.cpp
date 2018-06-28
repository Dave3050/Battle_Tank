// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank1PlayerController.h"
#include "Public/Tank.h"
#include "Tank_Battle.h"



void ATank1PlayerController::BeginPlay()
{
	Super::BeginPlay();

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
	
	FVector HitLocation; //Out parameter
	if (GetSightRayHitLocation(HitLocation)) // Has Side-effect, is going to line trace
	{
		GetControlledTank()->AimAt(HitLocation);
	}
	
}
// Get World Location of line trace through crosshair, true if hits landscape
bool ATank1PlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{

	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	
	// "De-project" the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		// Line-trace along that look direction and see what we hit (up to a max range)
		GetLookVectorHitLocation(LookDirection, HitLocation);

		//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *LookDirection.ToString());
	}

	

	return true;
}

bool ATank1PlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel
				(
					HitResult,
					StartLocation,
					EndLocation,
					ECollisionChannel::ECC_Visibility
				)
		)
		{
		HitLocation = HitResult.Location;
			return true;
		}
	return false; // line trace didn't succeed

}

bool ATank1PlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld
	(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);

}



