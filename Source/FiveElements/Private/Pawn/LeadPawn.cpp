// Copyright Cvxiv


#include "Pawn/LeadPawn.h"

#include "AbilitySystem/CustomAbilitySystemComponent.h"
#include "AbilitySystem/CustomAttributeSet.h"
#include "Kismet/KismetMathLibrary.h"
#include "Player/CannonPlayerState.h"

ALeadPawn::ALeadPawn() {
	PrimaryActorTick.bCanEverTick = true;

	RootMesh = CreateDefaultSubobject<UStaticMeshComponent>("RootMesh");
	HolderMesh = CreateDefaultSubobject<UStaticMeshComponent>("HolderMesh");

	RootMesh->PrimaryComponentTick.bCanEverTick = false;
	HolderMesh->PrimaryComponentTick.bCanEverTick = false;
	RootMesh->PrimaryComponentTick.bStartWithTickEnabled = false;
	HolderMesh->PrimaryComponentTick.bStartWithTickEnabled = false;

	RootMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);
	HolderMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);

	SetRootComponent(RootMesh);
	HolderMesh->SetupAttachment(RootMesh);
}

const FRotator ALeadPawn::GetCannonRotator() const {
	return HolderMesh->GetComponentRotation();
}

const FVector ALeadPawn::GetCannonShootLocation() const {
	return HolderMesh->GetComponentLocation() + FVector(0, 0, 300) + HolderMesh->GetForwardVector() * 200;
}

void ALeadPawn::BeginPlay() {
	Super::BeginPlay();
	if (Controller && Controller->IsPlayerController()) {
		PlayerController = Cast<APlayerController>(Controller);
	}
}

void ALeadPawn::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	FVector WorldLocation;
	FVector WorldDirection;
	if (PlayerController->DeprojectMousePositionToWorld(WorldLocation, WorldDirection)) {
		FHitResult HitResult;
		if (GetWorld()->LineTraceSingleByChannel(HitResult, WorldLocation, WorldLocation + WorldDirection * 100000, ECC_Visibility)) {
			FVector DiffVector = HitResult.ImpactPoint - GetActorLocation();
			DiffVector.Z = 0;

			HolderMesh->SetWorldRotation(UKismetMathLibrary::MakeRotFromX(DiffVector));
		}
	}
}

void ALeadPawn::PossessedBy(AController* NewController) {
	Super::PossessedBy(NewController);

	InitAbilityActorInfo();
	AddCharacterAbilities();
}

void ALeadPawn::InitAbilityActorInfo() {
	CannonPlayerState = GetPlayerState<ACannonPlayerState>();
	check(CannonPlayerState)

	AbilitySystemComponent = Cast<UCustomAbilitySystemComponent>(CannonPlayerState->GetAbilitySystemComponent());
	check(AbilitySystemComponent)

	AbilitySystemComponent->InitAbilityActorInfo(CannonPlayerState, this);

	AttributeSet = CastChecked<UCustomAttributeSet>(CannonPlayerState->GetAttributeSet());
}

void ALeadPawn::AddCharacterAbilities() const {
	for (const TSubclassOf<UGameplayAbility>& AbilityClass : StartupAbilities) {
		AbilitySystemComponent->AddAbility(AbilityClass);
	}
}
