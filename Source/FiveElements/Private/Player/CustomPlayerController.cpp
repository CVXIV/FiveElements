// Copyright Cvxiv


#include "Player/CustomPlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "EnhancedInputSubsystems.h"
#include "AbilitySystem/CustomAbilitySystemComponent.h"
#include "Input/CustomEnhancedInputComponent.h"

void ACustomPlayerController::BeginPlay() {
	Super::BeginPlay();

	check(InputMappingContext)
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer())) {
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}

	FInputModeGameOnly InputMode;
	InputMode.SetConsumeCaptureMouseDown(false);
	SetInputMode(InputMode);
}

void ACustomPlayerController::SetupInputComponent() {
	Super::SetupInputComponent();

	UCustomEnhancedInputComponent* CustomEnhancedInputComponent = CastChecked<UCustomEnhancedInputComponent>(InputComponent);
	CustomEnhancedInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
}

void ACustomPlayerController::OnPossess(APawn* InPawn) {
	Super::OnPossess(InPawn);

	AbilitySystemComponent = Cast<UCustomAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InPawn));
}

void ACustomPlayerController::AbilityInputTagPressed(const FGameplayTag InputTag) {
	AbilitySystemComponent->AbilityInputTagPressed(InputTag);
}

void ACustomPlayerController::AbilityInputTagReleased(const FGameplayTag InputTag) {
	AbilitySystemComponent->AbilityInputTagReleased(InputTag);
}

void ACustomPlayerController::AbilityInputTagHeld(const FGameplayTag InputTag) {
	AbilitySystemComponent->AbilityInputTagHeld(InputTag);
}
