// Fill out your copyright notice in the Description page of Project Settings.


#include "WonderJam2020GameState.h"


AWonderJam2020GameState::AWonderJam2020GameState()
{
	bReplicates = true;
}

void AWonderJam2020GameState::AssignTeam(APawn* Player)
{
	TArray<APawn*>* PlayersInTeam = TeamPlayersArray.Find(NextTeamToAssign);
	if (PlayersInTeam != nullptr)
	{
		PlayersInTeam->Add(Player);
	}
	else
	{
		TArray<APawn*> PlayersToAdd;
		PlayersToAdd.Add(Player);
		TeamPlayersArray.Add(NextTeamToAssign, PlayersToAdd);
		PlayersInTeam = &PlayersToAdd;
	}

	PlayerTeamArray.Add(Player, NextTeamToAssign);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Player  : %s in team nb "), *Player->GetName()) + FString::FromInt(NextTeamToAssign));

	if (PlayersInTeam->Num() == TeamSize)
		NextTeamToAssign++;
}

uint32 AWonderJam2020GameState::GetTeam(APawn* Player)
{
	return *PlayerTeamArray.Find(Player);
}


APawn* AWonderJam2020GameState::GetTeammate(APawn* Player)
{
	uint32 Team = *PlayerTeamArray.Find(Player);
	TArray<APawn*> PlayersInTeam = *TeamPlayersArray.Find(Team);
	for (APawn*& PawnPlayer : PlayersInTeam)
	{
		if (PawnPlayer != Player)
			return PawnPlayer;
	}

	return nullptr;
}