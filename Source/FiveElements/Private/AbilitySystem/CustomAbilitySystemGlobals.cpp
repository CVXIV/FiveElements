// Copyright Cvxiv


#include "AbilitySystem/CustomAbilitySystemGlobals.h"

#include "AbilityTypes.h"

FGameplayEffectContext* UCustomAbilitySystemGlobals::AllocGameplayEffectContext() const {
	return new FCustomGameplayEffectContext();
}
