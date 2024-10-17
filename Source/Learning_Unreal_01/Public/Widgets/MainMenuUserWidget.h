#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/LevelManager.h"
#include "MainMenuUserWidget.generated.h"

UCLASS()
class LEARNING_UNREAL_01_API UMainMenuUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Main Menu")
	void StartGame();

	UFUNCTION(BlueprintCallable, Category = "Main Menu")
	void QuitGame();

private:
	LevelManager Manager;
	ELevels CurrentLevel = ELevels::MainMenu;
};
