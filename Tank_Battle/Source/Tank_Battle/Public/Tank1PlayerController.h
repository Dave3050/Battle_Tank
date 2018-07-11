// Copyright AH Studios 2018

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "Tank.h"
#include "Engine/World.h"
#include "Tank1PlayerController.generated.h"

/*
  Responsible for helping the player aim
*/

 // Forward Declaration
class UTankBarrel;

class ATankAIController;

class UTankAimingComponent;

UCLASS()
class TANK_BATTLE_API ATank1PlayerController : public APlayerController
{
	GENERATED_BODY()

protected:



	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimingCompRef);

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:

	//Starts the tank moving the barrel so that the shot would hit
	//where it intersects with the world
	void AimTowardsCrosshair();

	//Return an OUT Parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
		float CrosshairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
		float CrosshairYLocation = 0.333333;

	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPlayerTankDeath();



};


