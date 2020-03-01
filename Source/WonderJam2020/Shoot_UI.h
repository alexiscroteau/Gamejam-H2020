// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Shoot_UI.generated.h"

//class UButton;
class APhone_Character;
UCLASS()
class WONDERJAM2020_API UShoot_UI : public UUserWidget
{
	GENERATED_BODY()
public :
	void SetUp();
	/*UPROPERTY(meta = (BindWidget))
		UButton* Shoot_Button;*/
protected : 
	void NativeConstruct() override;

	
};
