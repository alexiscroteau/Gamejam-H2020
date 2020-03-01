// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTourelle.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMyTourelle::AMyTourelle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PitchValue = 0.f;
	YawValue = 0.f;
	RollValue = 0.f;

	//Root = CreateDefaultSubobject<USceneComponent>(TEXT("Tourelle"));
	//RootComponent = Root;

	Tourelle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tourelle"));
	//Tourelle->AttachTo(Root);

	TankDirection = CreateDefaultSubobject<UArrowComponent>(TEXT("Tourelle Direction"));
}

// Called when the game starts or when spawned
void AMyTourelle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTourelle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RotateTourelle();

	if (canShoot) {
		ShootTourelle();
	}

}

void AMyTourelle::RotateTourelle() {

	FQuat QuatRotation = FQuat(FRotator(PitchValue, YawValue, RollValue));
	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);

}

void AMyTourelle::ShootTourelle() {

	FHitResult OutHit;
	FVector Start = Tourelle->GetComponentLocation();
	FVector ForwardVector = Tourelle->GetForwardVector();

	FVector End = ((ForwardVector * 1000.f) + Start);
	FCollisionQueryParams CollisionParams;

	if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams))
	{
		if (OutHit.bBlockingHit)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("Shoot : %s"), *OutHit.GetActor()->GetName()));

		}
	}
}

