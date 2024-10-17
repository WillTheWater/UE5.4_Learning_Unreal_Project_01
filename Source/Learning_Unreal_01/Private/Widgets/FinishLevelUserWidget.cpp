#include "Widgets/FinishLevelUserWidget.h"
#include "Kismet/GameplayStatics.h"

void UFinishLevelUserWidget::NextLevel()
{
	ELevels NextLevel = Manager.GetNextLevel(CurrentLevel);
	FName NextLevelName = Manager.GetLevelName(NextLevel);
	UGameplayStatics::OpenLevel(this, NextLevelName);
	CurrentLevel = NextLevel;
}

void UFinishLevelUserWidget::QuitGame()
{
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}

void UFinishLevelUserWidget::Restart()
{
	FName CurrentLevelName = Manager.GetLevelName(CurrentLevel);
	UGameplayStatics::OpenLevel(this, CurrentLevelName);
}
