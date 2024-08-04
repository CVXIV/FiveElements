// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BaseInputGameplayAbility.generated.h"

UCLASS()
class FIVEELEMENTS_API UBaseInputGameplayAbility : public UGameplayAbility {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "Input", meta = (Categories = "InputTag"))
	FGameplayTag InputTag;
};
