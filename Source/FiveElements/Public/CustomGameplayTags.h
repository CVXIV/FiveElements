// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"

DECLARE_MULTICAST_DELEGATE(FOnGameplayTagsInitialized);

class FIVEELEMENTS_API FCustomGameplayTags
{
public:
	const static FCustomGameplayTags& Get() { return S_GameplayTags; }
	static void InitializeNativeGameplayTags();
	static FOnGameplayTagsInitialized S_OnGameplayTagsInitialized;

private:
	static FCustomGameplayTags S_GameplayTags;
};
