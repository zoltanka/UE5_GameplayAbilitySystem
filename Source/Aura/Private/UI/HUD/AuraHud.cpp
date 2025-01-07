// Copyright Zoltan Fekete


#include "UI/HUD/AuraHud.h"
#include "UI/Widget/AuraUserWidget.h"

void AAuraHud::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);

	Widget->AddToViewport();
}
