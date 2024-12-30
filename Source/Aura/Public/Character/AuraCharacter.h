// Copyright Zoltán Fekete

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	
private:
	UPROPERTY(VisibleAnywhere);
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(VisibleAnywhere);
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	void InitAbilityActorInfo();
};
