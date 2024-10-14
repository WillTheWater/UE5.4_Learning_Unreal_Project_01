#include "GameModes/MainMenuGameMode.h"
#include "Kismet/GameplayStatics.h" // For GameplayStatics
#include "Blueprint/UserWidget.h" // For UUserWidgets

AMainMenuGameMode::AMainMenuGameMode()
{
}

void AMainMenuGameMode::StartPlay()
{
	Super::StartPlay();

	// Make sure game is not paused
	UGameplayStatics::SetGamePaused(GetWorld(), false);

	if (MainMenuWidget != nullptr)
	{
		UUserWidget* MainMenu = CreateWidget<UUserWidget>(GetWorld(), MainMenuWidget);
		if (MainMenu != nullptr)
		{
			MainMenu->AddToViewport();
		}
	}
}
