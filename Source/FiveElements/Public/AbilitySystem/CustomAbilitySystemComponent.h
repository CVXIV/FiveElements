// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "CustomAbilitySystemComponent.generated.h"

UCLASS()
class FIVEELEMENTS_API UCustomAbilitySystemComponent : public UAbilitySystemComponent {
	GENERATED_BODY()

public:
	void AddAbility(const TSubclassOf<UGameplayAbility>& AbilityClass);
};
