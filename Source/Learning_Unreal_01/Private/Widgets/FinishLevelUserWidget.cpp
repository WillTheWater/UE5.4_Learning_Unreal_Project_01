#include "Widgets/FinishLevelUserWidget.h"
#include "Widgets/LevelManager.h"
#include "GameInstance/MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

void UFinishLevelUserWidget::NextLevel()
{
    GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
    auto LevelMgr = GameInstance->GetLevelMgr();
    // Get and set the next level
    ELevels NextLevel = LevelMgr->GetNextLevel(GameInstance->CurrentLevel);
    FName NextLevelName = LevelMgr->GetLevelName(NextLevel);

    // Update the current level in the game instance
    GameInstance->CurrentLevel = NextLevel;

    // Open the new level
    UGameplayStatics::OpenLevel(this, NextLevelName);
}

void UFinishLevelUserWidget::QuitGame()
{
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}

void UFinishLevelUserWidget::Restart()
{
    GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
    auto LevelMgr = GameInstance->GetLevelMgr();
	FName CurrentLevelName = LevelMgr->GetLevelName(GameInstance->CurrentLevel);
	UGameplayStatics::OpenLevel(this, CurrentLevelName);
}
