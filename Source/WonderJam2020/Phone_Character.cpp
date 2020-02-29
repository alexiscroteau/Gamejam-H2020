// Fill out your copyright notice in the Description page of Project Settings.


#include "Phone_Character.h"
#include "Camera/CameraComponent.h"
// Sets default values
APhone_Character::APhone_Character()
{
	m_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	//RootComponent = m_Camera;
	//m_Camera->bUsePawnControlRotation = false;
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APhone_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APhone_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void APhone_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//PlayerInputComponent->BindAxis("Rotate_Right_Phone", this, &APhone_Character::Rotate_Right);


}

void APhone_Character::Rotate_Right(float value) {
	//GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Yellow, "bouge a droite, yes !!!");
}

