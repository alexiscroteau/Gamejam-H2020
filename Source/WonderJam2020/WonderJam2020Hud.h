// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "WonderJam2020Hud.generated.h"

UCLASS(config = Game)
class AWonderJam2020Hud : public AHUD
{
	GENERATED_BODY()

public:
	AWonderJam2020Hud();

	/** Font used to render the vehicle info */
	UPROPERTY()
	UFont* HUDFont;

	// Begin AHUD interface
	virtual void DrawHUD() override;
	// End AHUD interface

};
