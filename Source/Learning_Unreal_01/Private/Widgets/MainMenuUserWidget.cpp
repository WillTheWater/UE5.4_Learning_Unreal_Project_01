#include "Widgets/MainMenuUserWidget.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuUserWidget::StartGame()
{
	ELevels NextLevel = Manager.GetNextLevel(CurrentLevel);
	FName NextLevelName = Manager.GetLevelName(NextLevel);
	UGameplayStatics::OpenLevel(this, NextLevelName);
	CurrentLevel = NextLevel;
}

void UMainMenuUserWidget::QuitGame()
{
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}
