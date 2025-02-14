// Copyright Zoltán Fekete


#include "Character/AuraCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/AuraPlayerController.h"
#include "Player/AuraPlayerState.h"
#include "UI/HUD/AuraHud.h"

AAuraCharacter::AAuraCharacter()
{
	UCharacterMovementComponent* MovementComponent = GetCharacterMovement();

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SprintArm");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->TargetArmLength = 600;
	SpringArmComponent->SetUsingAbsoluteRotation(true);
	SpringArmComponent->bDoCollisionTest = false;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;
	
	MovementComponent->bOrientRotationToMovement = true;
	MovementComponent->RotationRate = FRotator(0.f, 400.f, 0.f);
	MovementComponent->bConstrainToPlane = true;
	MovementComponent->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init Ability Actor Info on the server
	InitAbilityActorInfo();
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	// Init Ability Actor Info on the client
	InitAbilityActorInfo();
}

void AAuraCharacter::InitAbilityActorInfo()
{
	AAuraPlayerState* PlayerState = GetPlayerState<AAuraPlayerState>();
	check(PlayerState);

	PlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(PlayerState, this);

	AbilitySystemComponent = Cast<UAuraAbilitySystemComponent>(PlayerState->GetAbilitySystemComponent());
	AttributeSet = PlayerState->GetAttributeSet();

	if (AAuraPlayerController* PlayerController = Cast<AAuraPlayerController>(GetController()))
	{
		if (AAuraHud* HUD = Cast<AAuraHud>(PlayerController->GetHUD()))
		{
			HUD->InitOverlay(PlayerController, PlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
}
