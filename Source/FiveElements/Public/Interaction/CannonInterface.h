// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CannonInterface.generated.h"

UINTERFACE(MinimalAPI)
class UCannonInterface : public UInterface {
	GENERATED_BODY()
};

class FIVEELEMENTS_API ICannonInterface {
	GENERATED_BODY()

public:
	virtual const FRotator GetCannonRotator() const = 0;

	virtual const FVector GetCannonShootLocation() const = 0;
};
