// Fill out your copyright notice in the Description page of Project Settings.


#include "Phone_Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Shoot_UI.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MotionControllerComponent.h"
#include "XRMotionControllerBase.h"
#include "Particles/ParticleSystem.h"

// Sets default values
APhone_Character::APhone_Character()
{
	PrimaryActorTick.bCanEverTick = true;
	OurCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	OurCameraSpringArm->SetupAttachment(RootComponent);
	OurCameraSpringArm->TargetArmLength = 200.f;
	OurCameraSpringArm->bEnableCameraLag = true;
	OurCameraSpringArm->CameraLagSpeed = 3.0f;


	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	OurCamera->SetupAttachment(OurCameraSpringArm, USpringArmComponent::SocketName);
	//AutoPossessPlayer = EAutoReceiveInput::Player0;
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ConstructorHelpers::FClassFinder<UUserWidget> MenuClassFinder(TEXT("/Game/BluePrint/UI/Viseur_UI"));
	//MenuClass = MenuClassFinder.Class;

	

	//ParticleSystem = Cast<UParticleSystem>(StaticConstructObject(Particle));

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
	/*PlayerInputComponent->BindAxis("MoveRight", this, &APhone_Character::Rotate_Right);
	PlayerInputComponent->BindAxis("MoveForward", this, &APhone_Character::Rotate_Up);
	PlayerInputComponent->BindAction("Shoot", IE_Repeat, this, &APhone_Character::Hit_Shoot);
	*/

}

void APhone_Character::Rotate_Right(float value) {
	//OurCamera->RelativeRotation += FRotator(0.0f, value * 2, 0.0f);
	
}

void APhone_Character::Rotate_Up(float value) {
	//GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Yellow, OurCamera->GetRelativeRotation().Vector().ToString());
	/*bool can = false;
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
		OurCamera->RelativeRotation += FRotator(value, 0.0f, 0.0f);
	}
	*/
	//SetActorRotation(FRotator(value*200, 0.0f, 0.0f));
}

void APhone_Character::Hit_Shoot() {
		
		/*SpawnParticle(FVector(0,0,0));
		FHitResult OutHit;
		FVector Start = OurCamera->GetComponentLocation();
		FVector ForwardVector = OurCamera->GetForwardVector();
		FVector End = ((ForwardVector * 1000.f) + Start);
		FCollisionQueryParams CollisionParams;
		if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams))
		{
			if (OutHit.bBlockingHit)
			{
				SpawnParticle(OutHit.Location,true);
			}
		}*/
}
