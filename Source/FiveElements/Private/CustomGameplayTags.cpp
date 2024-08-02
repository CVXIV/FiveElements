// Copyright Cvxiv


#include "CustomGameplayTags.h"

FCustomGameplayTags FCustomGameplayTags::S_GameplayTags;

FOnGameplayTagsInitialized FCustomGameplayTags::S_OnGameplayTagsInitialized;

void FCustomGameplayTags::InitializeNativeGameplayTags()
{
	S_GameplayTags.S_OnGameplayTagsInitialized.Broadcast();
}
