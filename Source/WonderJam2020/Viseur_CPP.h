// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Automobile.h"
#include "Viseur_CPP.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UShoot_UI;
UCLASS()
class WONDERJAM2020_API AViseur_CPP : public AAutomobile
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BluePrintReadWrite)
		USpringArmComponent* OurCameraSpringArm;
	UPROPERTY(EditAnywhere, BluePrintReadWrite)
		UCameraComponent* OurCamera;

	// Sets default values for this character's properties
	AViseur_CPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void Rotate_Right(float value);
	UFUNCTION()
		void Rotate_Up(float value);
	UFUNCTION()
		void Hit_Shoot();

	UShoot_UI* viseur = nullptr;
	TSubclassOf<class UShoot_UI> MenuClass;


	UFUNCTION(BlueprintImplementableEvent)
		void SpawnParticle(FVector location, bool touch = false);

};







