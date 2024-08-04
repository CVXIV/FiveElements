// Copyright Cvxiv


#include "Pawn/PawnBase.h"
#include "AbilitySystem/CustomAbilitySystemComponent.h"

APawnBase::APawnBase() {
	PrimaryActorTick.bCanEverTick = false;
}

UAbilitySystemComponent* APawnBase::GetAbilitySystemComponent() const {
	return AbilitySystemComponent;
}
