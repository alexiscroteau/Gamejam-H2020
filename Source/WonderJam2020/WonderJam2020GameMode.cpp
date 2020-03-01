// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "WonderJam2020GameMode.h"
#include "WonderJam2020Pawn.h"
#include "WonderJam2020GameState.h"
#include "WonderJam2020Hud.h"
#include "WonderJam2020PlayerController.h"

AWonderJam2020GameMode::AWonderJam2020GameMode()
{
	PlayerControllerClass = AWonderJam2020PlayerController::StaticClass();
	GameStateClass = AWonderJam2020GameState::StaticClass();
	HUDClass = AWonderJam2020Hud::StaticClass();
}

/* Override To Read In Pawn From Custom Controller */
UClass* AWonderJam2020GameMode::GetDefaultPawnClassForController_Implementation(AController* InController)
{
	
	/* Override Functionality to get Pawn from PlayerController */
	AWonderJam2020PlayerController* PlayerController = Cast<AWonderJam2020PlayerController>(InController);
	if (PlayerController)
	{
		return PlayerController->GetPlayerPawnClass();
	}

	/* If we don't get the right Controller, use the Default Pawn */
	return DefaultPawnClass;
}

void AWonderJam2020GameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
}