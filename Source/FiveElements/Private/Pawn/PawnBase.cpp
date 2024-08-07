// Copyright Cvxiv


#include "Pawn/PawnBase.h"
#include "AbilitySystem/CustomAbilitySystemComponent.h"
#include "AbilitySystem/CustomAttributeSet.h"

APawnBase::APawnBase() {
	PrimaryActorTick.bCanEverTick = false;
}

UAbilitySystemComponent* APawnBase::GetAbilitySystemComponent() const {
	return AbilitySystemComponent;
}

UAttributeSet* APawnBase::GetAttributeSet() const {
	return AttributeSet;
}
