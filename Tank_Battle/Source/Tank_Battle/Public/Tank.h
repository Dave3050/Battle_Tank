// Copyright AH Studios 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class TANK_BATTLE_API ATank : public APawn
{
	GENERATED_BODY()

public:

	// Sets default values for this pawn's properties
	ATank();

	// called by the Engine when actor damage is dealt
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

	// Returns Current health as a percent of starting health between 0 and 1
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;


	FTankDelegate OnDeath;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditDefaultsOnly, Category = "Seetup")
	int32 StartHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth; // Initialised in Begin Play
	
};
