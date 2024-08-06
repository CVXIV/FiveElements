// Copyright Cvxiv


#include "AbilitySystem/PlayerAbilitySystemComponent.h"

#include "AbilitySystem/Abilities/BaseInputGameplayAbility.h"

void UPlayerAbilitySystemComponent::AbilityInputTagPressed(const FGameplayTag& InputTag) {
	if (!InputTag.IsValid()) {
		return;
	}

	FScopedAbilityListLock AbilityListLock(*this);
	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities()) {
		if (const ICustomInputInterface* InputGameplayAbility = Cast<ICustomInputInterface>(AbilitySpec.Ability)) {
			if (InputGameplayAbility->GetInputTag().MatchesTagExact(InputTag)) {
				AbilitySpecInputPressed(AbilitySpec);
				if (AbilitySpec.IsActive()) {
					InvokeReplicatedEvent(EAbilityGenericReplicatedEvent::InputPressed, AbilitySpec.Handle, AbilitySpec.ActivationInfo.GetActivationPredictionKey());
				}
			}
		}
	}
}

void UPlayerAbilitySystemComponent::AbilityInputTagHeld(const FGameplayTag& InputTag) {
	if (!InputTag.IsValid()) {
		return;
	}

	FScopedAbilityListLock AbilityListLock(*this);
	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities()) {
		if (const ICustomInputInterface* InputGameplayAbility = Cast<ICustomInputInterface>(AbilitySpec.Ability)) {
			if (InputGameplayAbility->GetInputTag().MatchesTagExact(InputTag)) {
				AbilitySpecInputPressed(AbilitySpec);
				if (!AbilitySpec.IsActive()) {
					TryActivateAbility(AbilitySpec.Handle);
				}
			}
		}
	}
}

void UPlayerAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag) {
	if (!InputTag.IsValid()) {
		return;
	}

	FScopedAbilityListLock AbilityListLock(*this);
	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities()) {
		if (const ICustomInputInterface* InputGameplayAbility = Cast<ICustomInputInterface>(AbilitySpec.Ability)) {
			if (InputGameplayAbility->GetInputTag().MatchesTagExact(InputTag)) {
				AbilitySpecInputReleased(AbilitySpec);
				InvokeReplicatedEvent(EAbilityGenericReplicatedEvent::InputReleased, AbilitySpec.Handle, AbilitySpec.ActivationInfo.GetActivationPredictionKey());
			}
		}
	}
}
