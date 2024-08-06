// Copyright Cvxiv


#include "AbilitySystem/CustomAbilitySystemComponent.h"


void UCustomAbilitySystemComponent::AddAbility(const TSubclassOf<UGameplayAbility>& AbilityClass) {
	const FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
	GiveAbility(AbilitySpec);
}
