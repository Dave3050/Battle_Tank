// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Math/Rotator.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "TankAimingComponent.generated.h"

// Forward Declaration
class UTankBarrel; 

// Holds Parameters for barrel
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANK_BATTLE_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel * BarrelToSet);

	//TODO Add SetTurretReference

	void AimAt(FVector HitLocation, float LaunchSpeed);

protected:
	


private: 

	UTankBarrel * Barrel = nullptr;

	void MoveBarrel(FVector AimDirection);
	
};