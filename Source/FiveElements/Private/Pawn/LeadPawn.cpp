// Copyright Cvxiv


#include "Pawn/LeadPawn.h"

#include "Kismet/KismetMathLibrary.h"

ALeadPawn::ALeadPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	RootMesh = CreateDefaultSubobject<UStaticMeshComponent>("RootMesh");
	HolderMesh = CreateDefaultSubobject<UStaticMeshComponent>("HolderMesh");
	CannonMesh = CreateDefaultSubobject<USkeletalMeshComponent>("CannonMesh");

	RootMesh->PrimaryComponentTick.bCanEverTick = false;
	HolderMesh->PrimaryComponentTick.bCanEverTick = false;
	CannonMesh->PrimaryComponentTick.bCanEverTick = false;

	SetRootComponent(RootMesh);
	HolderMesh->SetupAttachment(RootMesh);
	CannonMesh->SetupAttachment(HolderMesh);
}

void ALeadPawn::BeginPlay()
{
	Super::BeginPlay();
	if (Controller && Controller->IsPlayerController())
	{
		PlayerController = Cast<APlayerController>(Controller);
	}
}

void ALeadPawn::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	FVector WorldLocation;
	FVector WorldDirection;
	if (PlayerController->DeprojectMousePositionToWorld(WorldLocation, WorldDirection))
	{
		FHitResult HitResult;
		if (GetWorld()->LineTraceSingleByChannel(HitResult, WorldLocation, WorldLocation + WorldDirection * 100000, ECC_Visibility))
		{
			FVector DiffVector = HitResult.ImpactPoint - GetActorLocation();
			DiffVector.Z = 0;

			CannonMesh->SetWorldRotation(UKismetMathLibrary::MakeRotFromX(DiffVector));
		}
	}
}
