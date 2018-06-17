// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "Tank1PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANK_BATTLE_API ATank1PlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ATank * GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:

	//Starts the tank moving the barrel so that the shot would hit
	//where it intersects with the world
	void AimTowardsCrosshair();

	//Return an OUT Parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;


};
