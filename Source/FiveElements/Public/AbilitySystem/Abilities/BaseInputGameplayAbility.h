// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Interaction/CustomInputInterface.h"
#include "BaseInputGameplayAbility.generated.h"

UCLASS()
class FIVEELEMENTS_API UBaseInputGameplayAbility : public UGameplayAbility, public ICustomInputInterface {
	GENERATED_BODY()

public:
	virtual FGameplayTag GetInputTag() const override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Input", meta = (Categories = "InputTag"))
	FGameplayTag InputTag;
};
