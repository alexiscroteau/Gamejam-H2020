// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "WonderJam2020GameState.generated.h"

/**
 * 
 */
UCLASS()
class WONDERJAM2020_API AWonderJam2020GameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	AWonderJam2020GameState();
	int GetTeamSize() { return TeamSize; }
	void AssignTeam(APawn* Player);
	uint32 GetTeam(APawn* Player);
	APawn* GetTeammate(APawn* Player);

private:
	int TeamSize = 2;
	uint32 NextTeamToAssign = 1;
	TMap<uint32, TArray<APawn*>> TeamPlayersArray;
	TMap<APawn*, uint32> PlayerTeamArray;
};
