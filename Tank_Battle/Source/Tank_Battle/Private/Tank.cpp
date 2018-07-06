// Copyright AH Studios 2018

#include "Tank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"
#include "Projectile.h"
#include "Tank_Battle.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	

}

 //Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();


	TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
	
}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure (TankAimingComponent)) { return; }

	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
	
}

void ATank::Fire()
{

	if (!ensure(Barrel)) { return; }
	bool isReloaded = (GetWorld()->GetTimeSeconds() - LastFireTime) > ReloadTimeInSeconds;

	if (isReloaded)
	{

		// spawn a projectile at the socket location on the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>
			(
				ProjectileBlueprint,
				Barrel->GetSocketLocation(FName("Projectile")),
				Barrel->GetSocketRotation(FName("Projectile"))
				);
		Projectile->LaunchProjectile(LaunchSpeed);
		
		LastFireTime = GetWorld()->GetTimeSeconds();
	}

}

