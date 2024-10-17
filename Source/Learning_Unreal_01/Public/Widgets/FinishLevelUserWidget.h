#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/LevelManager.h"
#include "FinishLevelUserWidget.generated.h"

UCLASS()
class LEARNING_UNREAL_01_API UFinishLevelUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void NextLevel();

	UFUNCTION(BlueprintCallable)
	void QuitGame();
		
	UFUNCTION(BlueprintCallable)
	void Restart();

private:
	LevelManager Manager;
	ELevels CurrentLevel = ELevels::LevelOne;
};
