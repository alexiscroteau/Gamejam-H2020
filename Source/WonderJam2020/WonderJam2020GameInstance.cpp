// Fill out your copyright notice in the Description page of Project Settings.


#include "WonderJam2020GameInstance.h"

#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

#include "MenuSystem/MenuWidget.h"
#include "MenuSystem/EndingMenu.h"
#include "MenuSystem/LobbyMenu.h"

UWonderJam2020GameInstance::UWonderJam2020GameInstance(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> MainMenuBPClass(TEXT("/Game/MenuSystem/Blueprints/BP_MainMenu"));
	if (!ensure(MainMenuBPClass.Class != nullptr)) return;

	MainMenuClass = MainMenuBPClass.Class;

	ConstructorHelpers::FClassFinder<UUserWidget> InGameMenuBPClass(TEXT("/Game/MenuSystem/Blueprints/BP_InGameMenu"));
	if (!ensure(InGameMenuBPClass.Class != nullptr)) return;

	InGameMenuClass = InGameMenuBPClass.Class;

	ConstructorHelpers::FClassFinder<UUserWidget> LobbyMenuBPClass(TEXT("/Game/MenuSystem/Blueprints/BP_LobbyMenu"));
	if (!ensure(LobbyMenuBPClass.Class != nullptr)) return;

	LobbyMenuClass = LobbyMenuBPClass.Class;

	ConstructorHelpers::FClassFinder<UUserWidget> EndingMenuBPClass(TEXT("/Game/MenuSystem/Blueprints/BP_EndingMenu"));
	if (!ensure(EndingMenuBPClass.Class != nullptr)) return;

	EndingMenuClass = EndingMenuBPClass.Class;
}

void UWonderJam2020GameInstance::Init()
{
	Super::Init();

	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;
	Engine->OnNetworkFailure().AddUObject(this, &UWonderJam2020GameInstance::NetworkError);
}

void UWonderJam2020GameInstance::LoadMenu()
{
	if (!ensure(MainMenuClass != nullptr)) return;

	MainMenu = CreateWidget<UMenuWidget>(this, MainMenuClass);
	if (!ensure(MainMenu != nullptr)) return;

	MainMenu->Setup();

	MainMenu->SetMenuInterface(this);
}

void UWonderJam2020GameInstance::LoadInGameMenu()
{
	if (!ensure(InGameMenuClass != nullptr)) return;

	InGameMenu = CreateWidget<UMenuWidget>(this, InGameMenuClass);
	if (!ensure(InGameMenu != nullptr)) return;

	InGameMenu->Setup();

	InGameMenu->SetMenuInterface(this);
}

void UWonderJam2020GameInstance::LoadLobbyMenu()
{
	if (!ensure(LobbyMenuClass != nullptr)) return;

	LobbyMenu = CreateWidget<ULobbyMenu>(this, LobbyMenuClass);
	if (!ensure(LobbyMenu != nullptr)) return;

	LobbyMenu->Setup();

	LobbyMenu->SetMenuInterface(this);
}

void UWonderJam2020GameInstance::LoadEndingMenu(AActor* PlayerActor)
{
	if (!ensure(EndingMenuClass != nullptr)) return;

	EndingMenu = CreateWidget<UEndingMenu>(this, EndingMenuClass);
	if (!ensure(EndingMenu != nullptr)) return;

	EndingMenu->Setup();
/* if(playerwon)
		EndingMenu->SetVictoryDisplay();
   else
		EndingMenu->SetDefeatDisplay();
*/

	EndingMenu->SetMenuInterface(this);
}

void UWonderJam2020GameInstance::Host()
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2.f, FColor::Green, TEXT("Hosting a server ..."));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/VehicleAdvCPP/Maps/NetworkMap?listen");
}

void UWonderJam2020GameInstance::Join(const FString& IPAddress)
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2.f, FColor::Green, FString::Printf(TEXT("Joining a server : %s ..."), *IPAddress));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel(IPAddress, ETravelType::TRAVEL_Absolute);
}

void UWonderJam2020GameInstance::LoadMainMenu()
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel("/Game/MenuSystem/MainMenu", ETravelType::TRAVEL_Absolute);
}

void UWonderJam2020GameInstance::QuitGame()
{
	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ConsoleCommand("quit");
}

void UWonderJam2020GameInstance::NetworkError(UWorld* World, UNetDriver* NetDriver, ENetworkFailure::Type FailureType, const FString& ErrorString)
{
	LoadMainMenu();
}