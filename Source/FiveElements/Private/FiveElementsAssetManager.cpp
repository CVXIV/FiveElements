// Fill out your copyright notice in the Description page of Project Settings.


#include "FiveElementsAssetManager.h"

UFiveElementsAssetManager& UFiveElementsAssetManager::Get() {
	check(GEngine)

	UFiveElementsAssetManager* FiveElementsAssetManager = Cast<UFiveElementsAssetManager>(GEngine->AssetManager.Get());
	return *FiveElementsAssetManager;
}

void UFiveElementsAssetManager::StartInitialLoading() {
	Super::StartInitialLoading();
}
