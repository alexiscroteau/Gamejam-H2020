// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "WonderJam2020GameMode.h"
#include "WonderJam2020Pawn.h"
#include "WonderJam2020Hud.h"
#include "Phone_Character.h"

AWonderJam2020GameMode::AWonderJam2020GameMode()
{
	DefaultPawnClass = APhone_Character::StaticClass();
	HUDClass = AWonderJam2020Hud::StaticClass();
}
