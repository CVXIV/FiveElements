// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "CannonPlayerState.generated.h"

UCLASS()
class FIVEELEMENTS_API ACannonPlayerState : public APlayerState, public IAbilitySystemInterface {
	GENERATED_BODY()

public:
	ACannonPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UCustomAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<class UCustomAttributeSet> AttributeSet;
};
