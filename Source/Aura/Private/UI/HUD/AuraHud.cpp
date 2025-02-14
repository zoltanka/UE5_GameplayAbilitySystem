// Copyright Zoltan Fekete


#include "UI/HUD/AuraHud.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AAuraHud::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);

		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallbacksToDependencies();
	}

	return OverlayWidgetController;
}

void AAuraHud::InitOverlay(APlayerController* PC, AAuraPlayerState* PS, UAuraAbilitySystemComponent* ASC,
	UAuraAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass is not initialized. Please fill out BP_AuraHUD!"));
	checkf(OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass is not initialized. Please fill out BP_AuraHUD!"));

	FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);

	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);
	
	UAuraUserWidget* OverlayWidget = CreateWidget<UAuraUserWidget>(GetWorld(), OverlayWidgetClass);
	
	OverlayWidget->SetWidgetController(WidgetController);

	WidgetController->BroadcastInitialValues();
	
	OverlayWidget->AddToViewport();
}
