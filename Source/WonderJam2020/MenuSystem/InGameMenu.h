// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "InGameMenu.generated.h"

/**
 * The Menu used in game when pressing the Escape key
 */
UCLASS()
class WONDERJAM2020_API UInGameMenu : public UMenuWidget
{
	GENERATED_BODY()

protected:
	// Initializes the object and sets up buttons callbacks
	virtual bool Initialize() override;
	
private:
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	// Main SubMenu
	UPROPERTY(meta = (BindWidget))
	class UWidget* BaseMenu;

	UPROPERTY(meta = (BindWidget))
	class UButton* CancelButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* DisconnectButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* QuitGameButton;

	// Disconnect SubMenu
	UPROPERTY(meta = (BindWidget))
	class UWidget* ConfirmationDisconnectMenu;

	UPROPERTY(meta = (BindWidget))
	class UButton* YesDisconnectButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* NoDisconnectButton;

	// Quit Game SubMenu
	UPROPERTY(meta = (BindWidget))
	class UWidget* ConfirmationQuitGameMenu;

	UPROPERTY(meta = (BindWidget))
	class UButton* YesQuitGameButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* NoQuitGameButton;
	

	// Calls Super::Teardown()
	UFUNCTION()
	void CloseMenu();

	// Switch Menu to Disconnect SubMenu
	UFUNCTION()
	void OpenConfirmationDisconnectMenu();

	// Switch Menu to Quit Game SubMenu
	UFUNCTION()
	void OpenConfirmationQuitGameMenu();

	// Switch Menu to Main SubMenu
	UFUNCTION()
	void OpenBaseMenu();

	// Disconnect the player from the game
	UFUNCTION()
	void Disconnect();

	// Close the game to Desktop
	UFUNCTION()
	void QuitGame();
};
