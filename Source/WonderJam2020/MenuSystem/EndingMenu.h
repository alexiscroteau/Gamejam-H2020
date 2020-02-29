// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "EndingMenu.generated.h"

/**
 * 
 */
UCLASS()
class WONDERJAM2020_API UEndingMenu : public UMenuWidget
{
	GENERATED_BODY()

public :
	void SetVictoryDisplay();
	void SetDefeatDisplay();

protected:
	// Initializes the object and sets up buttons callbacks
	virtual bool Initialize() override;

private:
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	// Main SubMenu
	UPROPERTY(meta = (BindWidget))
	class UWidget* VictoryDisplay;

	UPROPERTY(meta = (BindWidget))
	class UWidget* DefeatDisplay;

	UPROPERTY(meta = (BindWidget))
	class UButton* ReturnToLobbyButton;

	UFUNCTION()
	void ReturnToLobbyButtonHandler();
};
