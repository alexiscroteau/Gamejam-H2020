// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "MainMenu.generated.h"

/**
 * The Menu used in the MainMenu Map
 */
UCLASS()
class WONDERJAM2020_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

protected:
	// Initializes the object and sets up buttons callbacks
	virtual bool Initialize() override;

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* QuitGameButton;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	// Main SubMenu
	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;

	// Join SubMenu
	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinMenu;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* IPAddressField;

	UPROPERTY(meta = (BindWidget))
	class UButton* CancelJoinMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinServerButton;


	// Host a new game
	UFUNCTION()
	void HostServer();

	// Join an existing server
	UFUNCTION()
	void JoinServer();

	// Switch Menu to Join SubMenu
	UFUNCTION()
	void OpenJoinMenu();

	// Switch Menu to Main SubMenu
	UFUNCTION()
	void OpenMainMenu();

	// Quit the game to Desktop
	UFUNCTION()
	void QuitGame();

};
