// Copyright Cvxiv


#include "ExecCalc/ExecCalc_Damage.h"

#include "AbilitySystemComponent.h"
#include "AbilityTypes.h"
#include "AbilitySystem/CustomAttributeSet.h"

UExecCalc_Damage::UExecCalc_Damage() {
}

void UExecCalc_Damage::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const {
	const UAbilitySystemComponent* SourceAsc = ExecutionParams.GetSourceAbilitySystemComponent();
	const UAbilitySystemComponent* TargetAsc = ExecutionParams.GetTargetAbilitySystemComponent();

	const AActor* SourceAvatar = SourceAsc ? SourceAsc->GetAvatarActor() : nullptr;
	const AActor* TargetAvatar = TargetAsc ? TargetAsc->GetAvatarActor() : nullptr;

	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();

	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FGameplayEffectContextHandle EffectSpecHandle = Spec.GetContext();
	FCustomGameplayEffectContext* EffectContext = static_cast<FCustomGameplayEffectContext*>(EffectSpecHandle.Get());
	// 获取基础伤害和DeBuff
	float Damage = 0.f;
	for (const TTuple<FGameplayTag, float>& Pair : Spec.SetByCallerTagMagnitudes) {
		 Damage += Pair.Value;
	}

	// 接下来如果是径向伤害，先计算衰减后的值
	/*if (UAuraAbilitySystemLibrary::IsRadialDamage(EffectSpecHandle)) {
		const FVector RadialDamageOrigin = UAuraAbilitySystemLibrary::GetRadialDamageOrigin(EffectSpecHandle);
		const float DamageInnerRadius = UAuraAbilitySystemLibrary::GetRadialDamageInnerRadius(EffectSpecHandle);
		const float DamageOuterRadius = UAuraAbilitySystemLibrary::GetRadialDamageOuterRadius(EffectSpecHandle);
		Damage = UAuraAbilitySystemLibrary::CalcRadialDamageWithFalloff(Damage, FVector::Distance(TargetAvatar->GetActorLocation(), RadialDamageOrigin), DamageInnerRadius, DamageOuterRadius, 0.5f);
	}*/

	const FGameplayModifierEvaluatedData EvaluatedData(UCustomAttributeSet::GetIncomingDamageAttribute(), EGameplayModOp::Override, Damage);
	OutExecutionOutput.AddOutputModifier(EvaluatedData);
}
