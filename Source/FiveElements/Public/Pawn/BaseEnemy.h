// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "Pawn/PawnBase.h"
#include "BaseEnemy.generated.h"

UCLASS()
class FIVEELEMENTS_API ABaseEnemy : public APawnBase {
	GENERATED_BODY()

public:
	ABaseEnemy();

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class USphereComponent> SphereComponent;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UNiagaraComponent> NiagaraComponent;
};
