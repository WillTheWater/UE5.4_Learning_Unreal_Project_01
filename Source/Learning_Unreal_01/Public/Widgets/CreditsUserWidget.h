#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CreditsUserWidget.generated.h"

UCLASS()
class LEARNING_UNREAL_01_API UCreditsUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void QuitGame();
};
