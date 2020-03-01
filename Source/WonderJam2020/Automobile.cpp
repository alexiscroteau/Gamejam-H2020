// Fill out your copyright notice in the Description page of Project Settings.


#include "Automobile.h"

void AAutomobile::Touche_Implementation(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if (HasAuthority()) {

			vie -= 1;
			if (vie < 0) {
				AAutomobile* voiture = (AAutomobile*)OtherActor;
				if (voiture->IsA(AAutomobile::StaticClass())) {
					voiture->AjouterPoint();
			}
		}
	}
}

bool AAutomobile::Touche_Validate(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	return true;
}

void AAutomobile::AjouterPoint_Implementation() {
	if (HasAuthority()) {
		point += 1;
	}
}

bool AAutomobile::AjouterPoint_Validate() {
	return true;
}