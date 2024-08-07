// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

DECLARE_MULTICAST_DELEGATE(FOnGameplayTagsInitialized);

class FIVEELEMENTS_API FCustomGameplayTags {
public:
	const static FCustomGameplayTags& Get() { return S_GameplayTags; }

	static void InitializeNativeGameplayTags();

	static FOnGameplayTagsInitialized S_OnGameplayTagsInitialized;

	FGameplayTag Montage_Shoot;

	FGameplayTag State_Attack;

	FGameplayTag State_HitReact;

	// Input Tag
	FGameplayTag InputTag_LMB;

	FGameplayTag InputTag_RMB;

	// Element Tag
	FGameplayTag Element_Golden;

	FGameplayTag Element_Wood;

	FGameplayTag Element_Water;

	FGameplayTag Element_Fire;

	FGameplayTag Element_Soil;

private:
	static FCustomGameplayTags S_GameplayTags;
};
