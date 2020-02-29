// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameMenu.h"

#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/Widget.h"

// Initializes the object and sets up buttons callbacks
bool UInGameMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(CancelButton != nullptr)) return false;
	CancelButton->OnClicked.AddDynamic(this, &UInGameMenu::CloseMenu);

	if (!ensure(DisconnectButton != nullptr)) return false;
	DisconnectButton->OnClicked.AddDynamic(this, &UInGameMenu::OpenConfirmationDisconnectMenu);

	if (!ensure(QuitGameButton!= nullptr)) return false;
	QuitGameButton->OnClicked.AddDynamic(this, &UInGameMenu::OpenConfirmationQuitGameMenu);

	if (!ensure(YesDisconnectButton != nullptr)) return false;
	YesDisconnectButton->OnClicked.AddDynamic(this, &UInGameMenu::Disconnect);

	if (!ensure(NoDisconnectButton != nullptr)) return false;
	NoDisconnectButton->OnClicked.AddDynamic(this, &UInGameMenu::OpenBaseMenu);

	if (!ensure(YesQuitGameButton != nullptr)) return false;
	YesQuitGameButton->OnClicked.AddDynamic(this, &UInGameMenu::QuitGame);

	if (!ensure(NoQuitGameButton != nullptr)) return false;
	NoQuitGameButton->OnClicked.AddDynamic(this, &UInGameMenu::OpenBaseMenu);

	return true;
}

// Calls Super::Teardown()
void UInGameMenu::CloseMenu()
{
	Super::Teardown();
}

// Switch Menu to Disconnect SubMenu
void UInGameMenu::OpenConfirmationDisconnectMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(ConfirmationDisconnectMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(ConfirmationDisconnectMenu);
}

// Switch Menu to Quit Game SubMenu
void UInGameMenu::OpenConfirmationQuitGameMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(ConfirmationQuitGameMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(ConfirmationQuitGameMenu);
}

// Switch Menu to Main SubMenu
void UInGameMenu::OpenBaseMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(BaseMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(BaseMenu);
}

// Disconnect the player from the game
void UInGameMenu::Disconnect()
{
	if (MenuInterface != nullptr)
	{
		MenuInterface->LoadMainMenu();
	}
}

// Close the game to Desktop
void UInGameMenu::QuitGame()
{
	if (MenuInterface != nullptr)
	{
		MenuInterface->QuitGame();
	}
}