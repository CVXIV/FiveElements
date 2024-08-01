// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "FiveElementsAssetManager.generated.h"

UCLASS()
class FIVEELEMENTS_API UFiveElementsAssetManager : public UAssetManager {
	GENERATED_BODY()

public:
	static UFiveElementsAssetManager& Get();

protected:
	virtual void StartInitialLoading() override;
};
