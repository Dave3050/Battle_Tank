// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "Math/UnrealMathUtility.h"
#include "TankBarrel.generated.h"


 // Forward Declaration
class ATank1PlayerController;

class ATank;

class ATankAIController;

class UTankAimingComponent;

UCLASS(meta = (BlueprintSpawnableComponent))
class TANK_BATTLE_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// Max downward speed -1 max upward speed is 1
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxDegreesPerSecond = 15; // A sensible default

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxPitchDegrees = 30;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinPitchDegrees = -5;


};
