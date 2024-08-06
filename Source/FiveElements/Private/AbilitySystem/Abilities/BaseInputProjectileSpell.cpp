// Copyright Cvxiv


#include "AbilitySystem/Abilities/BaseInputProjectileSpell.h"

#include "Actor/BaseProjectile.h"
#include "Tools/CustomAbilitySystemLibrary.h"

void UBaseInputProjectileSpell::SpawnProjectile(const FVector& SpawnedLocation, const FRotator& SpawnedDirection)
{
	check(ProjectileClass)
	check(DamageEffectClass)
	//Rotation.Pitch = 0.f;

	if (MaxNumProjectiles == 1)
	{
		SpawnProjectile_Internal(SpawnedLocation, SpawnedDirection);
	}
	else
	{
		const TArray<FRotator> Rotators = UCustomAbilitySystemLibrary::EvenlySpacedRotators(
			SpawnedDirection.Vector(), FVector::UpVector, ProjectileSpread, MaxNumProjectiles);
		for (const FRotator& Rotator : Rotators)
		{
			SpawnProjectile_Internal(SpawnedLocation, Rotator);
		}
	}
}

void UBaseInputProjectileSpell::SpawnProjectile_Internal(const FVector& SpawnedLocation,
                                                         const FRotator& SpawnedDirection) const
{
	FTransform SpawnTransform;
	SpawnTransform.SetLocation(SpawnedLocation);
	SpawnTransform.SetRotation(SpawnedDirection.Quaternion());

	ABaseProjectile* Projectile = GetWorld()->SpawnActorDeferred<ABaseProjectile>(
		ProjectileClass, SpawnTransform, GetAvatarActorFromActorInfo(), Cast<APawn>(GetAvatarActorFromActorInfo()),
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	Projectile->DamageEffectParams = MakeDamageEffectParamsFromClassDefaults(Projectile);
	Projectile->FinishSpawning(SpawnTransform);
}
