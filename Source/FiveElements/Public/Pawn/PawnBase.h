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

protected:
	UPROPERTY()
	TObjectPtr<class UCustomAbilitySystemComponent> AbilitySystemComponent;
};
