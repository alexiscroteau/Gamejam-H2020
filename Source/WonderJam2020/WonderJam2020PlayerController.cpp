// Fill out your copyright notice in the Description page of Project Settings.


#include "WonderJam2020PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameModeBase.h"
#include "UObject/ConstructorHelpers.h"
#include "Net/UnrealNetwork.h"

AWonderJam2020PlayerController::AWonderJam2020PlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	/* Initialize The Values */
	ConstructorHelpers::FClassFinder<AViseur_CPP> PawnAndroidClass(TEXT("/Game/BluePrint/MyViseur_CPP"));
	PawnAndroid = PawnAndroidClass.Class;
	ConstructorHelpers::FClassFinder<AAutomobile> PawnWindowsClass(TEXT("/Game/DeplacementVehicule/Vehicule/Voiture"));
	PawnWindows = PawnWindowsClass.Class;
//	PawnWindows = AWonderJam2020Pawn::StaticClass();

	/* Make sure the PawnClass is Replicated */
	bReplicates = true;
}

void AWonderJam2020PlayerController::BeginPlay()
{
	Super::BeginPlay();

	DeterminePawnClass();
}

// Pawn Class
void AWonderJam2020PlayerController::DeterminePawnClass_Implementation()
{
	//if (IsLocalController()) //Only Do This Locally (NOT Client-Only, since Server wants this too!)
	//{
		FString platformName = UGameplayStatics::GetPlatformName();
//////		UE_LOG(LogTemp, Warning, TEXT("Platform is %s"), platformName);
		if (platformName.Equals(TEXT("Android"), ESearchCase::CaseSensitive))
		{
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Platform is : %s"), *platformName));
			ServerSetPawn(PawnAndroid);
			return;
		}

		ServerSetPawn(PawnWindows);
		return;
	//}
}


void AWonderJam2020PlayerController::ServerSetPawn_Implementation(TSubclassOf<APawn> InPawnClass)
{
	MyPawnClass = InPawnClass;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Platform is : %s"), *InPawnClass.Get()->GetFullName()));
	/* Just in case we didn't get the PawnClass on the Server in time... */
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->GetAuthGameMode()->RestartPlayer(this);
}

bool AWonderJam2020PlayerController::ServerSetPawn_Validate(TSubclassOf<APawn> InPawnClass)
{
	return true;
}

// Replication
void AWonderJam2020PlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
		DOREPLIFETIME(AWonderJam2020PlayerController, MyPawnClass);

}