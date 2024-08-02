#include "FiveElementsAssetManager.h"

#include "CustomGameplayTags.h"

UFiveElementsAssetManager& UFiveElementsAssetManager::Get() {
	check(GEngine)

	UFiveElementsAssetManager* FiveElementsAssetManager = Cast<UFiveElementsAssetManager>(GEngine->AssetManager.Get());
	return *FiveElementsAssetManager;
}

void UFiveElementsAssetManager::StartInitialLoading() {
	Super::StartInitialLoading();

	FCustomGameplayTags::InitializeNativeGameplayTags();
}
