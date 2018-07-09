// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "AIController.h"
#include "TankAIController.generated.h"

// Forward Declaration
class UTankBarrel;

class ATank1PlayerController;

class UTankAimingComponent;


UCLASS()
class TANK_BATTLE_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// Controls how close the AI tank can get
	UPROPERTY(EditDefaultsOnly, Category = "Setup") // Consider EditDefaultsOnly Later
	float AcceptanceRadious = 8000;
	
private:

	

};
