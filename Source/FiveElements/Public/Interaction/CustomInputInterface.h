// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "CustomInputInterface.generated.h"

UINTERFACE(MinimalAPI)
class UCustomInputInterface : public UInterface {
	GENERATED_BODY()
};

class FIVEELEMENTS_API ICustomInputInterface {
	GENERATED_BODY()

public:
	virtual FGameplayTag GetInputTag() const = 0;
};
