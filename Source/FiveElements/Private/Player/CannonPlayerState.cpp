// Copyright Cvxiv


#include "Player/CannonPlayerState.h"

#include "AbilitySystem/CustomAbilitySystemComponent.h"
#include "AbilitySystem/CustomAttributeSet.h"

ACannonPlayerState::ACannonPlayerState() {
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UCustomAbilitySystemComponent>("AbilitySystemComponent");
	AttributeSet = CreateDefaultSubobject<UCustomAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ACannonPlayerState::GetAbilitySystemComponent() const {
	return AbilitySystemComponent;
}
