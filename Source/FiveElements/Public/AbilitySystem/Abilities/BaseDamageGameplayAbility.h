// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "AbilityTypes.h"
#include "Abilities/GameplayAbility.h"
#include "BaseDamageGameplayAbility.generated.h"

UCLASS()
class FIVEELEMENTS_API UBaseDamageGameplayAbility : public UGameplayAbility {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FDamageEffectParams MakeDamageEffectParamsFromClassDefaults(AActor* Instigator, AActor* Target = nullptr, FVector InRadialDamageOrigin = FVector::ZeroVector) const;

	[[nodiscard]] bool IsIsRadialDamage() const {
		return bIsRadialDamage;
	}

	[[nodiscard]] float GetRadialDamageInnerRadius() const {
		return RadialDamageInnerRadius;
	}

	[[nodiscard]] float GetRadiusDamageOuterRadius() const {
		return RadiusDamageOuterRadius;
	}

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> DamageEffectClass;

	UPROPERTY(EditDefaultsOnly, Category = "Damage", meta = (DisplayName = "伤害类型", Categories = "Damage"))
	TMap<FGameplayTag, FDamageTypeInfo> DamageTypes;

	UPROPERTY(EditDefaultsOnly, meta = (ClampMin = 0), Category = "Damage")
	float DeathImpulseMagnitude = 0;

	UPROPERTY(EditDefaultsOnly, meta = (ClampMin = 0), Category = "Damage")
	float KnockBackForceMagnitude = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	bool bTakeHitReact = false;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	bool bIsRadialDamage = false;

	UPROPERTY(EditDefaultsOnly, Category = "Damage", meta = (ClampMin = 0, EditCondition = "bIsRadialDamage", EditConditionHides))
	float RadialDamageInnerRadius = 0.f;

	UPROPERTY(EditDefaultsOnly, Category = "Damage", meta = (ClampMin = 0, EditCondition = "bIsRadialDamage", EditConditionHides))
	float RadiusDamageOuterRadius = 0.f;
};
