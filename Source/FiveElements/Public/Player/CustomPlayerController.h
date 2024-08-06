// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/PlayerController.h"
#include "CustomPlayerController.generated.h"


UCLASS()
class FIVEELEMENTS_API ACustomPlayerController : public APlayerController {
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	virtual void OnPossess(APawn* InPawn) override;

private:
	void AbilityInputTagPressed(const FGameplayTag InputTag);

	void AbilityInputTagReleased(const FGameplayTag InputTag);

	void AbilityInputTagHeld(const FGameplayTag InputTag);

protected:

private:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<class UInputMappingContext> InputMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<class UInputConfig> InputConfig;

	UPROPERTY()
	TObjectPtr<class UPlayerAbilitySystemComponent> AbilitySystemComponent;
};
