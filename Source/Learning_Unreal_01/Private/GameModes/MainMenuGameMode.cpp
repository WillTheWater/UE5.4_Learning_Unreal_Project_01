#include "GameModes/MainMenuGameMode.h"
#include "Widgets/MainMenuUserWidget.h"
#include "Kismet/GameplayStatics.h" // For GameplayStatics
#include "UObject/ConstructorHelpers.h" // For ConstructorHelpers

AMainMenuGameMode::AMainMenuGameMode()
{
	// Assigning the Blueprint of the widget to MainMenuWidgetClass
	static ConstructorHelpers::FClassFinder<UUserWidget> WidgetClass(TEXT("/Game/Blueprints/UserWidgets/BP_MainMenuWidget"));
	if (WidgetClass.Succeeded())
	{
		MainMenuWidgetClass = WidgetClass.Class;
	}
}

void AMainMenuGameMode::StartPlay()
{
	Super::StartPlay();

	// Setting up the Main Menu Widget
	if (MainMenuWidgetClass)
	{
		auto MainMenu = Cast<UMainMenuUserWidget>(CreateWidget<UUserWidget>(GetWorld(), MainMenuWidgetClass));
		if (MainMenu)
		{
			MainMenu->AddToViewport();
		}
	}
}
