// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn_cppp.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class WONDERJAM2020_API AMyPawn_cppp : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn_cppp();
	UPROPERTY(EditAnywhere, BluePrintReadWrite)
		USpringArmComponent* OurCameraSpringArm;
	UPROPERTY(EditAnywhere, BluePrintReadWrite)
		UCameraComponent* OurCamera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
