// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/BaseDamageGameplayAbility.h"
#include "Interaction/CustomInputInterface.h"
#include "BaseInputDamageGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class FIVEELEMENTS_API UBaseInputDamageGameplayAbility : public UBaseDamageGameplayAbility, public ICustomInputInterface {
	GENERATED_BODY()

public:
	virtual FGameplayTag GetInputTag() const override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Input", meta = (Categories = "InputTag"))
	FGameplayTag InputTag;
};
