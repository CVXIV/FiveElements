// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemGlobals.h"
#include "CustomAbilitySystemGlobals.generated.h"

/**
 * 
 */
UCLASS()
class FIVEELEMENTS_API UCustomAbilitySystemGlobals : public UAbilitySystemGlobals {
	GENERATED_BODY()
	virtual FGameplayEffectContext* AllocGameplayEffectContext() const override;
};
