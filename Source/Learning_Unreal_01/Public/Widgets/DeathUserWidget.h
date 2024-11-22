#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DeathUserWidget.generated.h"

UCLASS()
class LEARNING_UNREAL_01_API UDeathUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void QuitGame();

	UFUNCTION(BlueprintCallable)
	void Restart();

private:
	class UMyGameInstance* GameInstance;
};
