#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "Automobile.generated.h"


UCLASS()
class WONDERJAM2020_API AAutomobile : public AWheeledVehicle
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=VieVoiture)
	int vie = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pOINTVoiture)
	int point = 0;

	UFUNCTION(Server, Reliable, WithValidation)
		 void Touche(AAutomobile* aa);

	UFUNCTION(Server, Reliable, WithValidation)
		void AjouterPoint();



};