// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WonderJam2020Pawn.h"
#include "WonderJam2020AndroidPawn.h"
#include "WonderJam2020PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class WONDERJAM2020_API AWonderJam2020PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	/* Constructor */
	AWonderJam2020PlayerController(const FObjectInitializer& ObjectInitializer);

	FORCEINLINE UClass* GetPlayerPawnClass() { return MyPawnClass; }

protected:
	/* Return The Correct Pawn Class Client-Side */
	UFUNCTION(Reliable, Client)
	virtual void DeterminePawnClass();

	/* Use BeginPlay to start the functionality */
	virtual void BeginPlay() override;

	/* Set Pawn Class On Server For This Controller */
	UFUNCTION(Reliable, Server, WithValidation)
	virtual void ServerSetPawn(TSubclassOf<APawn> InPawnClass);

	/* Actual Pawn class we want to use */
	UPROPERTY(Replicated)
	TSubclassOf<APawn> MyPawnClass;

	/* First Pawn Type To Use */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "My Controller")
	TSubclassOf<AWonderJam2020Pawn> PawnAndroid;

	/* Second Pawn Type To Use */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "My Controller")
	TSubclassOf<AWonderJam2020AndroidPawn> PawnWindows;
};
