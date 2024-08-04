// Copyright Cvxiv


#include "AbilitySystem/CustomAbilitySystemComponent.h"

#include "AbilitySystem/Abilities/BaseInputGameplayAbility.h"

void UCustomAbilitySystemComponent::AbilityInputTagPressed(const FGameplayTag& InputTag) {
	if (!InputTag.IsValid()) {
		return;
	}

	FScopedAbilityListLock AbilityListLock(*this);
	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities()) {
		if (const UBaseInputGameplayAbility* InputGameplayAbility = Cast<UBaseInputGameplayAbility>(AbilitySpec.Ability)) {
			if (InputGameplayAbility->InputTag.MatchesTagExact(InputTag)) {
				AbilitySpecInputPressed(AbilitySpec);
				if (AbilitySpec.IsActive()) {
					InvokeReplicatedEvent(EAbilityGenericReplicatedEvent::InputPressed, AbilitySpec.Handle, AbilitySpec.ActivationInfo.GetActivationPredictionKey());
				}
			}
		}
	}
}

void UCustomAbilitySystemComponent::AbilityInputTagHeld(const FGameplayTag& InputTag) {
	if (!InputTag.IsValid()) {
		return;
	}

	FScopedAbilityListLock AbilityListLock(*this);
	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities()) {
		if (const UBaseInputGameplayAbility* InputGameplayAbility = Cast<UBaseInputGameplayAbility>(AbilitySpec.Ability)) {
			if (InputGameplayAbility->InputTag.MatchesTagExact(InputTag)) {
				AbilitySpecInputPressed(AbilitySpec);
				if (!AbilitySpec.IsActive()) {
					TryActivateAbility(AbilitySpec.Handle);
				}
			}
		}
	}
}

void UCustomAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag) {
	if (!InputTag.IsValid()) {
		return;
	}

	FScopedAbilityListLock AbilityListLock(*this);
	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities()) {
		if (const UBaseInputGameplayAbility* InputGameplayAbility = Cast<UBaseInputGameplayAbility>(AbilitySpec.Ability)) {
			if (InputGameplayAbility->InputTag.MatchesTagExact(InputTag)) {
				AbilitySpecInputReleased(AbilitySpec);
				InvokeReplicatedEvent(EAbilityGenericReplicatedEvent::InputReleased, AbilitySpec.Handle, AbilitySpec.ActivationInfo.GetActivationPredictionKey());
			}
		}
	}
}

void UCustomAbilitySystemComponent::AddAbility(const TSubclassOf<UGameplayAbility>& AbilityClass) {
	const FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
	GiveAbility(AbilitySpec);
}
