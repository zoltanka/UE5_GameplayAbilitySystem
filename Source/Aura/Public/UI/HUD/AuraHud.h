// Copyright Zoltan Fekete

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHud.generated.h"

class UAuraAttributeSet;
class UAuraAbilitySystemComponent;
class AAuraPlayerState;
struct FWidgetControllerParams;
class UOverlayWidgetController;
class UAuraUserWidget;

/**
 * 
 */
UCLASS()
class AURA_API AAuraHud : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget;

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	void InitOverlay(APlayerController* PC, AAuraPlayerState* PS, UAuraAbilitySystemComponent* ASC,
	                 UAuraAttributeSet* AS);

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
	
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;
};
