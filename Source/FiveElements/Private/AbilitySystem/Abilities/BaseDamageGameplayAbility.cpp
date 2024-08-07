// Copyright Cvxiv


#include "AbilitySystem/Abilities/BaseDamageGameplayAbility.h"

#include "AbilitySystemBlueprintLibrary.h"

FDamageEffectParams UBaseDamageGameplayAbility::MakeDamageEffectParamsFromClassDefaults(AActor* Instigator, AActor* Target, FVector InRadialDamageOrigin) const {
	FDamageEffectParams Params;
	Params.WorldContextObject = GetAvatarActorFromActorInfo();
	Params.Instigator = Instigator;
	Params.DamageGameplayEffectClass = DamageEffectClass;
	Params.SourceAbilitySystemComponent = GetAbilitySystemComponentFromActorInfo();
	Params.TargetAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);
	Params.DamageTypes = DamageTypes;
	Params.AbilityLevel = GetAbilityLevel();
	Params.DeathImpulseMagnitude = DeathImpulseMagnitude * 1000.f;
	Params.KnockBackForceMagnitude = KnockBackForceMagnitude * 1000.f;
	Params.bTakeHitReact = bTakeHitReact;

	if (bIsRadialDamage) {
		Params.bIsRadialDamage = bIsRadialDamage;
		Params.RadialDamageInnerRadius = RadialDamageInnerRadius;
		Params.RadiusDamageOuterRadius = RadiusDamageOuterRadius;
		Params.RadialDamageOrigin = InRadialDamageOrigin;
	}

	return Params;
}
