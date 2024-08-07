// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CustomAbilitySystemLibrary.generated.h"

/**
 * 
 */
UCLASS()
class FIVEELEMENTS_API UCustomAbilitySystemLibrary : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AbilitySystemLibrary|DamageEffect")
	static FGameplayEffectContextHandle ApplyGameplayEffect(UPARAM(ref) FDamageEffectParams& DamageEffectParams);

	static TArray<FRotator> EvenlySpacedRotators(const FVector& Forward, const FVector& Axis, float SpreadInDegree, int32 Nums);

	/**
	 * 返回[0,1)的一个值，其中X>=0
	 * @param X 
	 * @return 
	 */
	UFUNCTION(BlueprintCallable, Category = "AuraAbilitySystemLibrary|Math")
	static float Sigmoid_Modify(const float X);

	UFUNCTION(BlueprintCallable, Category = "AuraAbilitySystemLibrary|Math")
	static bool ProbabilityCheck(const float Probability);
};
