// Fill out your copyright notice in the Description page of Project Settings.


#include "WonderJam2020AndroidPawn.h"

// Sets default values
AWonderJam2020AndroidPawn::AWonderJam2020AndroidPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWonderJam2020AndroidPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWonderJam2020AndroidPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWonderJam2020AndroidPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

