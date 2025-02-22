// Copyright Cvxiv


#include "Actor/BaseProjectile.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Components/SphereComponent.h"
#include "FiveElements/FiveElements.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Tools/CustomAbilitySystemLibrary.h"

ABaseProjectile::ABaseProjectile() {
	PrimaryActorTick.bCanEverTick = false;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SphereComponent->SetCollisionObjectType(ECC_PROJECTILE);
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComponent->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	SphereComponent->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
	SphereComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SphereComponent->PrimaryComponentTick.bCanEverTick = false;
	SphereComponent->PrimaryComponentTick.bStartWithTickEnabled = false;
	SetRootComponent(SphereComponent);

	NiagaraLoopComponent = CreateDefaultSubobject<UNiagaraComponent>("NiagaraLoop");
	NiagaraLoopComponent->SetupAttachment(SphereComponent);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
	ProjectileMovementComponent->ProjectileGravityScale = 0;
}

void ABaseProjectile::BeginPlay() {
	Super::BeginPlay();

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnSphereOverlap);
	if (NiagaraLaunch) {
		UNiagaraComponent* LaunchNiagaraComponent = UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, NiagaraLaunch, GetActorLocation());
		LaunchNiagaraComponent->SetAutoDestroy(true);
	}
}

void ABaseProjectile::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	NiagaraLoopComponent->Deactivate();

	if (UAbilitySystemComponent* Asc = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OtherActor)) {
		DamageEffectParams.TargetAbilitySystemComponent = Asc;
		UCustomAbilitySystemLibrary::ApplyGameplayEffect(DamageEffectParams);
	}

	Destroy();
}
