// Copyright Cvxiv


#include "Player/CannonPlayerState.h"

#include "AbilitySystem/CustomAttributeSet.h"
#include "AbilitySystem/PlayerAbilitySystemComponent.h"

ACannonPlayerState::ACannonPlayerState() {
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UPlayerAbilitySystemComponent>("AbilitySystemComponent");
	AttributeSet = CreateDefaultSubobject<UCustomAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ACannonPlayerState::GetAbilitySystemComponent() const {
	return AbilitySystemComponent;
}
