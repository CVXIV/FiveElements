// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "Interaction/CannonInterface.h"
#include "Pawn/PawnBase.h"
#include "LeadPawn.generated.h"

UCLASS()
class FIVEELEMENTS_API ALeadPawn : public APawnBase, public ICannonInterface {
	GENERATED_BODY()

public:
	ALeadPawn();

	UFUNCTION(BlueprintCallable)
	virtual const FRotator GetCannonRotator() const override;

	UFUNCTION(BlueprintCallable)
	virtual const FVector GetCannonShootLocation() const override;

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void PossessedBy(AController* NewController) override;

private:
	void InitAbilityActorInfo();

	void AddCharacterAbilities() const;

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> RootMesh;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> HolderMesh;

	UPROPERTY()
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY()
	TObjectPtr<class ACannonPlayerState> CannonPlayerState;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	TArray<TSubclassOf<class UGameplayAbility>> StartupAbilities;
};
