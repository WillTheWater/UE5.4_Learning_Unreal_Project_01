#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainMenuGameMode.generated.h"

UCLASS()
class LEARNING_UNREAL_01_API AMainMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AMainMenuGameMode();
	virtual void StartPlay() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "User Interface")
	TSubclassOf<class UUserWidget> MainMenuWidgetClass;

	UPROPERTY()
	class UMainMenuUserWidget* MainMenuWidget;
};
