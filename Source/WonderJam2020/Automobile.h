// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "Automobile.generated.h"

/**
 * 
 */
UCLASS()
class WONDERJAM2020_API AAutomobile : public AWheeledVehicle
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=VieVoiture)
	int32 vie = 100;
	
};
