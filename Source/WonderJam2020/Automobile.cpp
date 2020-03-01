#include "Automobile.h"

void AAutomobile::Touche_Implementation(AAutomobile* aa) {
	if (HasAuthority()) {

		vie -= 1;
		SpawnParticle(GetActorLocation());
		if (vie < 0) {
			//AAutomobile* voiture = (AAutomobile)OtherActor;
			//if (voiture->IsA(AAutomobile::StaticClass())) {
			aa->AjouterPoint();
			//}
		}
	}
}

bool AAutomobile::Touche_Validate(AAutomobile* aa) {
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