// Copyright AH Studios 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "Tank.generated.h"



UCLASS()
class TANK_BATTLE_API ATank : public APawn
{
	GENERATED_BODY()

public:

	// Sets default values for this pawn's properties
	ATank();


protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	

	
};
