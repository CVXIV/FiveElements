// Copyright Cvxiv


#include "Pawn/BaseEnemy.h"

#include "CustomGameplayTags.h"
#include "NiagaraComponent.h"
#include "AbilitySystem/CustomAbilitySystemComponent.h"
#include "AbilitySystem/CustomAttributeSet.h"
#include "Components/SphereComponent.h"
#include "FiveElements/FiveElements.h"

ABaseEnemy::ABaseEnemy() {
	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SphereComponent->SetCollisionObjectType(ECC_Pawn);
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComponent->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	SphereComponent->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
	SphereComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SphereComponent->SetCollisionResponseToChannel(ECC_PROJECTILE, ECR_Overlap);
	SphereComponent->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	SphereComponent->PrimaryComponentTick.bCanEverTick = false;
	SphereComponent->PrimaryComponentTick.bStartWithTickEnabled = false;
	SphereComponent->SetGenerateOverlapEvents(true);
	SetRootComponent(SphereComponent);

	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMeshComponent");
	SkeletalMeshComponent->PrimaryComponentTick.bCanEverTick = false;
	SkeletalMeshComponent->PrimaryComponentTick.bStartWithTickEnabled = false;
	SkeletalMeshComponent->SetupAttachment(SphereComponent);

	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>("NiagaraLoop");
	NiagaraComponent->SetupAttachment(SkeletalMeshComponent);

	AttributeSet = CreateDefaultSubobject<UCustomAttributeSet>("AttributeSet");

	AbilitySystemComponent = CreateDefaultSubobject<UCustomAbilitySystemComponent>("AbilitySystemComponent");
}

void ABaseEnemy::BeginPlay() {
	Super::BeginPlay();

	if (ElementTypes.Num() > CurrentElementTypeIndex) {
		OnElementTypeChange(ElementTypes[CurrentElementTypeIndex]);
	}
}

void ABaseEnemy::OnElementTypeChange(const FGameplayTag& ElementType) {
	if (ElementType.MatchesTagExact(FCustomGameplayTags::Get().Element_Golden)) {
	} else if (ElementType.MatchesTagExact(FCustomGameplayTags::Get().Element_Wood)) {
	} else if (ElementType.MatchesTagExact(FCustomGameplayTags::Get().Element_Water)) {
	} else if (ElementType.MatchesTagExact(FCustomGameplayTags::Get().Element_Fire)) {
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("!!!!"));
	} else if (ElementType.MatchesTagExact(FCustomGameplayTags::Get().Element_Soil)) {
	}
}
