// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"


UCLASS(Abstract)
class FIVEELEMENTS_API APawnBase : public APawn, public IAbilitySystemInterface {
	GENERATED_BODY()

public:
	APawnBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	class UAttributeSet* GetAttributeSet() const;

protected:
	UPROPERTY()
	TObjectPtr<class UCustomAttributeSet> AttributeSet;

	UPROPERTY()
	TObjectPtr<class UCustomAbilitySystemComponent> AbilitySystemComponent;
};
