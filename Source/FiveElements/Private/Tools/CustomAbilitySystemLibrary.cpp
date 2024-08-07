// Copyright Cvxiv


#include "Tools/CustomAbilitySystemLibrary.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "AbilityTypes.h"
#include "CustomGameplayTags.h"

FGameplayEffectContextHandle UCustomAbilitySystemLibrary::ApplyGameplayEffect(FDamageEffectParams& DamageEffectParams) {
	FGameplayEffectContextHandle EffectContextHandle = DamageEffectParams.SourceAbilitySystemComponent->MakeEffectContext();
	EffectContextHandle.AddSourceObject(DamageEffectParams.SourceAbilitySystemComponent->GetAvatarActor());
	const FGameplayEffectSpecHandle EffectSpecHandle = DamageEffectParams.SourceAbilitySystemComponent->MakeOutgoingSpec(DamageEffectParams.DamageGameplayEffectClass, DamageEffectParams.AbilityLevel, EffectContextHandle);

	const FCustomGameplayTags& AuraGameplayTags = FCustomGameplayTags::Get();
	for (int i = 0; i < DamageEffectParams.DamageTypes.Num(); ++i) {
		const FDamageTypeInfo& DamageTypeInfo = DamageEffectParams.DamageTypes[i];

		UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(EffectSpecHandle, DamageTypeInfo.ElementType, DamageTypeInfo.Damage.GetValueAtLevel(DamageEffectParams.AbilityLevel));

		/*const FGameplayTag& DeBuff_Chance = AuraGameplayTags.DamageTypesToDeBuffAndResistance[Tag].DeBuff_Chance;
		const FGameplayTag& DeBuff_Damage = AuraGameplayTags.DamageTypesToDeBuffAndResistance[Tag].DeBuff_Damage;
		const FGameplayTag& DeBuff_Frequency = AuraGameplayTags.DamageTypesToDeBuffAndResistance[Tag].DeBuff_Frequency;
		const FGameplayTag& DeBuff_Duration = AuraGameplayTags.DamageTypesToDeBuffAndResistance[Tag].DeBuff_Duration;
		UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(EffectSpecHandle, DeBuff_Chance, DamageTypeInfo.DeBuffChance);
		UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(EffectSpecHandle, DeBuff_Damage, DamageTypeInfo.DeBuffDamage);
		UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(EffectSpecHandle, DeBuff_Frequency, DamageTypeInfo.DeBuffFrequency);
		UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(EffectSpecHandle, DeBuff_Duration, DamageTypeInfo.DeBuffDuration);*/
	}

	// TODO 待优化
	/*SetKnockBackForce(EffectContextHandle, DamageEffectParams.Instigator->GetActorForwardVector() * DamageEffectParams.KnockBackForceMagnitude);
	SetDeathImpulse(EffectContextHandle, DamageEffectParams.Instigator->GetActorForwardVector() * DamageEffectParams.DeathImpulseMagnitude);

	SetTakeHitReact(EffectContextHandle, DamageEffectParams.bTakeHitReact);
	SetIsRadialDamage(EffectContextHandle, DamageEffectParams.bIsRadialDamage);
	SetRadialDamageInnerRadius(EffectContextHandle, DamageEffectParams.RadialDamageInnerRadius);
	SetRadialDamageOuterRadius(EffectContextHandle, DamageEffectParams.RadiusDamageOuterRadius);
	SetRadialDamageOrigin(EffectContextHandle, DamageEffectParams.RadialDamageOrigin);*/

	DamageEffectParams.TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data);

	return EffectContextHandle;
}

TArray<FRotator> UCustomAbilitySystemLibrary::EvenlySpacedRotators(const FVector& Forward, const FVector& Axis, float SpreadInDegree, int32 Nums) {
	TArray<FRotator> Rotators;
	if (Nums > 1) {
		const FVector LeftOfSpread = Forward.RotateAngleAxis(-SpreadInDegree * 0.5f, Axis);
		// 360°特殊情况，起点和终点会重合
		const float DeltaSpread = SpreadInDegree / (SpreadInDegree < 360.f ? Nums - 1 : Nums);
		for (int32 i = 0; i < Nums; ++i) {
			const FVector Direction = LeftOfSpread.RotateAngleAxis(DeltaSpread * i, Axis);
			Rotators.Add(Direction.Rotation());
		}
	} else {
		Rotators.Add(Forward.Rotation());
	}

	return Rotators;
}

float UCustomAbilitySystemLibrary::Sigmoid_Modify(const float X) {
	return (1.0f / (1.0f + exp(-X * 0.03f)) - 0.5f) * 2.f;
}

bool UCustomAbilitySystemLibrary::ProbabilityCheck(const float Probability) {
	return FMath::RandRange(0.f, 1.f) <= Probability;
}
