// Copyright Cvxiv

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/BaseInputDamageGameplayAbility.h"
#include "BaseInputProjectileSpell.generated.h"

UCLASS()
class FIVEELEMENTS_API UBaseInputProjectileSpell : public UBaseInputDamageGameplayAbility
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void SpawnProjectile(const FVector& SpawnedLocation, const FRotator& SpawnedDirection);

private:
	void SpawnProjectile_Internal(const FVector& SpawnedLocation, const FRotator& SpawnedDirection) const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class ABaseProjectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, meta = (ClampMin = 0), Category = "Projectile")
	float ProjectileSpread = 90.f;

	UPROPERTY(EditDefaultsOnly, meta = (ClampMin = 1), Category = "Projectile")
	int32 MaxNumProjectiles = 1;
};
