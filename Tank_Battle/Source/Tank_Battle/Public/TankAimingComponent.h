// Copyright AH Studios 2018

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Math/Rotator.h"
#include "Engine/World.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "TankAimingComponent.generated.h"

// Enum For aiming state
UENUM()
enum class EFiringStatus : uint8
{
	Reloading,
	Aiming,
	Locked
};

// Forward Declaration
class UTankBarrel; 

class ATank1PlayerController;

class AProjectile;

class ATankAIController;

class UTankTurret;

// Holds Parameters for barrel
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TANK_BATTLE_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

protected:
	
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringStatus = EFiringStatus::Aiming;



private: 

	void MoveBarrel(FVector YAimDirection);

	UTankBarrel * Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 60960.0;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3;

	float LastFireTime = 0;
	
};

