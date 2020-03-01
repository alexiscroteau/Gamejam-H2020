// Fill out your copyright notice in the Description page of Project Settings.


#include "Voiture.h"

// Sets default values
AVoiture::AVoiture()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVoiture::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVoiture::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVoiture::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

