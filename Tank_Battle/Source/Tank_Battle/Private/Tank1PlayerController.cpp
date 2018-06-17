// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank1PlayerController.h"
#include "Tank_Battle.h"



ATank* ATank1PlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

