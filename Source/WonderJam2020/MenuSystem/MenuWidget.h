// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MenuWidget.generated.h"

/**
 * Base Class for all Menus
 */
UCLASS()
class WONDERJAM2020_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// Sets up the Menu
	void Setup();
	// Close down the Menu
	void Teardown();

	// Set the Menu Interface
	void SetMenuInterface(IMenuInterface* MenuInterfaceInit);
	
protected:
	// Called when the game travels to another level
	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;

	IMenuInterface* MenuInterface;
};
