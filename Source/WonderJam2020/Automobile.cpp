#include "Automobile.h"

void AAutomobile::Touche_Implementation(AAutomobile* aa) {
	if (HasAuthority()) {

		vie -= 1;
		SpawnParticle(GetActorLocation());
		if (vie < 0) {
			//AAutomobile* voiture = (AAutomobile)OtherActor;
			//if (voiture->IsA(AAutomobile::StaticClass())) {
			aa->AjouterPoint(5);
			vie = 100;
			AjouterPoint(-3);

			//}
		}
	}
}

bool AAutomobile::Touche_Validate(AAutomobile* aa) {
	return true;
}

void AAutomobile::AjouterPoint_Implementation(int i) {
	if (HasAuthority()) {
		point += i;
	}
}

bool AAutomobile::AjouterPoint_Validate(int i) {
	return true;
}