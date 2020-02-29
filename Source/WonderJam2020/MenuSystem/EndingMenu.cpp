// Fill out your copyright notice in the Description page of Project Settings.


#include "EndingMenu.h"

//#include "PuzzlePlatformsCharacter.h"

#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"

// Initializes the object and sets up buttons callbacks
bool UEndingMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(ReturnToLobbyButton != nullptr)) return false;
	ReturnToLobbyButton->OnClicked.AddDynamic(this, &UEndingMenu::ReturnToLobbyButtonHandler);

	return true;
}

void UEndingMenu::ReturnToLobbyButtonHandler()
{
	// Return to lobby
}

void UEndingMenu::SetVictoryDisplay()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(VictoryDisplay != nullptr)) return;
	MenuSwitcher->SetActiveWidget(VictoryDisplay);
}

void UEndingMenu::SetDefeatDisplay()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(DefeatDisplay != nullptr)) return;
	MenuSwitcher->SetActiveWidget(DefeatDisplay);
}