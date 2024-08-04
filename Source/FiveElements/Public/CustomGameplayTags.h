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

private:
	static FCustomGameplayTags S_GameplayTags;
};
