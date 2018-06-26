// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "Math/UnrealMathUtility.h"
#include "TankTurret.generated.h"

// Forward Declaration
class ATank1PlayerController;

class ATank;

class ATankAIController;

class UTankAimingComponent;

UCLASS(meta = (BlueprintSpawnableComponent))
class TANK_BATTLE_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// Min speed is -1 max speed is 1
	void Rotate(float RotSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 25; // A sensible default
	
	
};
