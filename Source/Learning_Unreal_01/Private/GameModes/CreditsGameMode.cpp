#include "GameModes/CreditsGameMode.h"
#include "Widgets/CreditsUserWidget.h"

ACreditsGameMode::ACreditsGameMode()
{
	// Assigning the Blueprint of the widget to MainMenuWidgetClass
	static ConstructorHelpers::FClassFinder<UUserWidget> WidgetClass(TEXT("/Game/Blueprints/UserWidgets/BP_CreditsWidget"));
	if (WidgetClass.Succeeded())
	{
		CreditsWidgetClass = WidgetClass.Class;
	}
}

void ACreditsGameMode::StartPlay()
{
	Super::StartPlay();

	// Setting up the Main Menu Widget
	if (CreditsWidgetClass)
	{
		auto Menu = Cast<UCreditsUserWidget>(CreateWidget<UUserWidget>(GetWorld(), CreditsWidgetClass));
		if (Menu)
		{
			Menu->AddToViewport();
		}
	}
}
