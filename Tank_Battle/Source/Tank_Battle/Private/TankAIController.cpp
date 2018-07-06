// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Tank_Battle.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AITank = GetPawn();

	if (!ensure(PlayerTank && AITank)) { return; }
	
		// Move towards player
		MoveToActor(PlayerTank, AcceptanceRadious);
		// Aim towards player
		auto AimingComponent = AITank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());
		
		
		AimingComponent->Fire(); 
	

};

