// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "TankTrack.generated.h"

// Forward Declaration
class ATank1PlayerController;

class ATank;

class ATankAIController;

class UTankAimingComponent;

UCLASS(meta = (BlueprintSpawnableComponent))
class TANK_BATTLE_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	// Sets a throttle between -1 and 1
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);
	
	// This is tanks max force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 460000; // Assume 46 ton tank, and 1G accelleration

protected:

	UTankTrack();

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

private:

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

};

