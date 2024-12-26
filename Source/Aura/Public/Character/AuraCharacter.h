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

private:
	UPROPERTY(VisibleAnywhere);
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(VisibleAnywhere);
	TObjectPtr<USpringArmComponent> SpringArmComponent;

};
