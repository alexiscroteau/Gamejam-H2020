// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WonderJam2020GameMode.generated.h"

UCLASS(MinimalAPI)
class AWonderJam2020GameMode : public AGameModeBase
{
	GENERATED_BODY()

	/* Override To Read In Pawn From Custom Controller */
	UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;

	virtual void PostLogin(APlayerController* NewPlayer) override;

public:
	AWonderJam2020GameMode();

//private:
	/*APawn* ClavierPawn;
	APawn* AndroidPawn;*/

};

/*class BasePawn
	équipe
	--
	--

class clavierPawn : public BasePawn
	Position androidCameraAnchor

class androidPawn : public BasePawn
	Tick() {
	updatePosition(GetMyTeammate.androidCameraAnchor)
}*/