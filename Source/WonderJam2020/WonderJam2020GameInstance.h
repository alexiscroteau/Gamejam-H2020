// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "WonderJam2020GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class WONDERJAM2020_API UWonderJam2020GameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:
	UWonderJam2020GameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init() override;

	UFUNCTION(BlueprintCallable)
	void LoadMenu();

	UFUNCTION(BlueprintCallable)
	void LoadInGameMenu();

	UFUNCTION(BlueprintCallable)
	void LoadLobbyMenu();

	UFUNCTION(BlueprintCallable)
	void LoadEndingMenu(class AActor* AttachedActor);

	UFUNCTION(Exec)
	virtual void Host();

	UFUNCTION(Exec)
	virtual void Join(const FString& IPAddress) override;

	virtual void LoadMainMenu() override;

	virtual void QuitGame() override;

	void NetworkError(UWorld* World, UNetDriver* NetDriver, ENetworkFailure::Type FailureType, const FString& ErrorString);


private:
	TSubclassOf<class UUserWidget> MainMenuClass;
	TSubclassOf<class UUserWidget> InGameMenuClass;
	TSubclassOf<class UUserWidget> LobbyMenuClass;
	TSubclassOf<class UUserWidget> EndingMenuClass;

	class UMenuWidget* MainMenu;
	class UMenuWidget* InGameMenu;
	class ULobbyMenu*  LobbyMenu;
	class UEndingMenu* EndingMenu;
};
