#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerOverlay.generated.h"

UCLASS()
class LEARNING_UNREAL_01_API UPlayerOverlay : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetScore();

private:

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ScoreText;

	class UMyGameInstance* GameInstance;
};
