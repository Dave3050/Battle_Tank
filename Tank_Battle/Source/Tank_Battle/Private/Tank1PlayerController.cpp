// Copyright AH Studios 2018

#pragma once

#include "Tank1PlayerController.h"
#include "TankAimingComponent.h"
#include "Tank_Battle.h"



void ATank1PlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	
	FoundAimingComponent(AimingComponent);
}

void ATank1PlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	
}



void ATank1PlayerController::AimTowardsCrosshair()
{

	if (!GetPawn()) { return; }
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	
	FVector HitLocation; //Out parameter
	bool bGotHitLocation = GetSightRayHitLocation(HitLocation);
	if (bGotHitLocation) // Has Side-effect, is going to line trace
	{
		AimingComponent->AimAt(HitLocation);
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
		return GetLookVectorHitLocation(LookDirection, HitLocation);

		//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *LookDirection.ToString());
	}

	return false;
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



