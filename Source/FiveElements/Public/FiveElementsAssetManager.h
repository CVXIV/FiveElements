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
