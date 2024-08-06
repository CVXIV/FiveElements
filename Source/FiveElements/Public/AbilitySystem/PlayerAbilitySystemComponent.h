// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/CustomAbilitySystemComponent.h"
#include "PlayerAbilitySystemComponent.generated.h"

UCLASS()
class FIVEELEMENTS_API UPlayerAbilitySystemComponent : public UCustomAbilitySystemComponent {
	GENERATED_BODY()

public:
	void AbilityInputTagPressed(const FGameplayTag& InputTag);

	void AbilityInputTagHeld(const FGameplayTag& InputTag);

	void AbilityInputTagReleased(const FGameplayTag& InputTag);
};
