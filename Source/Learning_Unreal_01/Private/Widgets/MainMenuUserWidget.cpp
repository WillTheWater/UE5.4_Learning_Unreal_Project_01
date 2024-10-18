#include "Widgets/MainMenuUserWidget.h"
#include "GameInstance/MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuUserWidget::StartGame()
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

void UMainMenuUserWidget::QuitGame()
{
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}
