// Fill out your copyright notice in the Description page of Project Settings.


#include "Shoot_UI.h"
#include "Components/Button.h"
#include "Phone_Character.h"

void UShoot_UI::SetUp(APhone_Character* character) {
	this->AddToViewport();
	this->m_character = character;
	

}

void UShoot_UI::NativeConstruct()
{
	
	/*if (ensure(Shoot_Button != nullptr))
	{
		Shoot_Button->OnClicked.AddDynamic(this, &UShoot_UI::Shoot);
	}*/
	
}

void UShoot_UI::Shoot() {
	this->m_character->Hit_Shoot();
}
