// Fill out your copyright notice in the Description page of Project Settings.


#include "Automobile.h"
#include "WonderJam2020GameState.h"

AAutomobile::AAutomobile()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAutomobile::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
		AWonderJam2020GameState* GState = GetWorld()->GetGameState<AWonderJam2020GameState>();
		GState->AssignTeam(this);
		Team = GState->GetTeam(this);
	}
}