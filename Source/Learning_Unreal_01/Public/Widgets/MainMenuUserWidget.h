#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
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
	class UMyGameInstance* GameInstance;
};
