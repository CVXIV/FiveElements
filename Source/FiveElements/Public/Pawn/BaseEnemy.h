// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Pawn/PawnBase.h"
#include "BaseEnemy.generated.h"

UCLASS()
class FIVEELEMENTS_API ABaseEnemy : public APawnBase {
	GENERATED_BODY()

public:
	ABaseEnemy();

	virtual void BeginPlay() override;

protected:
	UFUNCTION(BlueprintCallable)
	void OnElementTypeChange(const FGameplayTag& ElementType);

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class USphereComponent> SphereComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UNiagaraComponent> NiagaraComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Element", meta = (Categories = "Element"))
	TArray<FGameplayTag> ElementTypes;

private:
	int32 CurrentElementTypeIndex = 0;
};
