// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "CustomAttributeSet.generated.h"
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

struct FEffectProperties {
	FEffectProperties() {
	}

	FGameplayEffectContextHandle EffectContextHandle;

	UAbilitySystemComponent* SourceAsc = nullptr;

	AActor* SourceAvatarActor = nullptr;

	AController* SourceController = nullptr;

	ACharacter* SourceCharacter = nullptr;

	UAbilitySystemComponent* TargetAsc = nullptr;

	AActor* TargetAvatarActor = nullptr;

	AController* TargetController = nullptr;

	ACharacter* TargetCharacter = nullptr;
};

UCLASS()
class FIVEELEMENTS_API UCustomAttributeSet : public UAttributeSet {
	GENERATED_BODY()

public:
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

private:
	static void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props);

	void HandleIncomingDamage(const FEffectProperties& Props);

public:
	UPROPERTY(BlueprintReadOnly, Category = "Meta Attributes")
	FGameplayAttributeData IncomingDamage;

	ATTRIBUTE_ACCESSORS(UCustomAttributeSet, IncomingDamage)
};
