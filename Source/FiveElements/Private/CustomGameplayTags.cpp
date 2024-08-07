// Copyright Cvxiv


#include "CustomGameplayTags.h"

#include "GameplayTagsManager.h"

FCustomGameplayTags FCustomGameplayTags::S_GameplayTags;

FOnGameplayTagsInitialized FCustomGameplayTags::S_OnGameplayTagsInitialized;

void FCustomGameplayTags::InitializeNativeGameplayTags() {
	S_GameplayTags.Montage_Shoot = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Montage.Shoot"));
	S_GameplayTags.State_Attack = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("State.Attack"));
	S_GameplayTags.State_HitReact = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("State.HitReact"));
	S_GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.LMB"));
	S_GameplayTags.InputTag_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.RMB"));
	
	S_GameplayTags.Element_Golden = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Element.Golden"));
	S_GameplayTags.Element_Wood = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Element.Wood"));
	S_GameplayTags.Element_Water = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Element.Water"));
	S_GameplayTags.Element_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Element.Fire"));
	S_GameplayTags.Element_Soil = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Element.Soil"));

	S_GameplayTags.S_OnGameplayTagsInitialized.Broadcast();
}
