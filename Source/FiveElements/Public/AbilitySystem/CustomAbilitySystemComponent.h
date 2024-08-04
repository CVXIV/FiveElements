// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "CustomAbilitySystemComponent.generated.h"

UCLASS()
class FIVEELEMENTS_API UCustomAbilitySystemComponent : public UAbilitySystemComponent {
	GENERATED_BODY()

public:
	void AbilityInputTagPressed(const FGameplayTag& InputTag);

	void AbilityInputTagHeld(const FGameplayTag& InputTag);

	void AbilityInputTagReleased(const FGameplayTag& InputTag);

	void AddAbility(const TSubclassOf<UGameplayAbility>& AbilityClass);
};
