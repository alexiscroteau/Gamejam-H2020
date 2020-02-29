// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "WonderJam2020GameMode.h"
#include "WonderJam2020Pawn.h"
#include "WonderJam2020Hud.h"

AWonderJam2020GameMode::AWonderJam2020GameMode()
{
	DefaultPawnClass = AWonderJam2020Pawn::StaticClass();
	HUDClass = AWonderJam2020Hud::StaticClass();
}

void AWonderJam2020GameMode::PostLogin(APlayerController * NewPlayer)
{
	
}