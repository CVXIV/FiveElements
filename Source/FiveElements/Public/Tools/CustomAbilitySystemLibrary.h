// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CustomAbilitySystemLibrary.generated.h"

/**
 * 
 */
UCLASS()
class FIVEELEMENTS_API UCustomAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	static TArray<FRotator> EvenlySpacedRotators(const FVector& Forward, const FVector& Axis, float SpreadInDegree, int32 Nums);
};
