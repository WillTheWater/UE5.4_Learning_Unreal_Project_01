#include "Widgets/MainMenuUserWidget.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Init widget and bind buttons
}

void UMainMenuUserWidget::StartGame()
{
	UGameplayStatics::OpenLevel(this, FName("LevelOne"));
}

void UMainMenuUserWidget::QuitGame()
{
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}
