// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "MyTourelle.generated.h"

UCLASS()
class WONDERJAM2020_API AMyTourelle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTourelle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void RotateTourelle();

	void ShootTourelle();

	UPROPERTY()
		USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tourelle")
		USkeletalMeshComponent* Tourelle;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Tourelle")
		class UArrowComponent* TankDirection;

	UPROPERTY(EditAnywhere)
		float PitchValue;

	UPROPERTY(EditAnywhere)
		float YawValue;

	UPROPERTY()
		float RollValue;

	UPROPERTY(EditAnywhere)
		bool canShoot = false;
};
