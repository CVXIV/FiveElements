// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "Pawn/PawnBase.h"
#include "LeadPawn.generated.h"

UCLASS()
class FIVEELEMENTS_API ALeadPawn : public APawnBase
{
	GENERATED_BODY()

public:
	ALeadPawn();
	
protected:
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> RootMesh;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> HolderMesh;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USkeletalMeshComponent> CannonMesh;

	UPROPERTY()
	TObjectPtr<APlayerController> PlayerController;
};
