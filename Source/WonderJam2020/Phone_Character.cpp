// Fill out your copyright notice in the Description page of Project Settings.


#include "Phone_Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
// Sets default values
APhone_Character::APhone_Character()
{
	//RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	OurCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	OurCameraSpringArm->SetupAttachment(RootComponent);
	//OurCameraSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 00.0f), FRotator(0.0f, 0.0f, 0.0f));
	OurCameraSpringArm->TargetArmLength = 200.f;
	OurCameraSpringArm->bEnableCameraLag = true;
	OurCameraSpringArm->CameraLagSpeed = 3.0f;

	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	OurCamera->SetupAttachment(OurCameraSpringArm, USpringArmComponent::SocketName);
	AutoPossessPlayer = EAutoReceiveInput::Player0;
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
	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveRight", this, &APhone_Character::Rotate_Right);
	PlayerInputComponent->BindAxis("MoveForward", this, &APhone_Character::Rotate_Up);
	

}

void APhone_Character::Rotate_Right(float value) {
	OurCamera->RelativeRotation += FRotator(0.0f, value * 2, 0.0f);
	//SetActorRotation(FRotator(value*200, 0.0f, 0.0f));
}

void APhone_Character::Rotate_Up(float value) {
	//GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Yellow, OurCamera->GetRelativeRotation().Vector().ToString());
	bool can = false;
	if (value < 0) {
		if (OurCamera->GetRelativeRotation().Vector().Z > -0.4) {
			can = true;
		}
	}
	else {
		if (OurCamera->GetRelativeRotation().Vector().Z < 0.3) {
			can = true;
		
		}
	}
	if (can) {
		OurCamera->RelativeRotation += FRotator(value * 0.5, 0.0f, 0.0f);
	}
	
	//SetActorRotation(FRotator(value*200, 0.0f, 0.0f));
}

