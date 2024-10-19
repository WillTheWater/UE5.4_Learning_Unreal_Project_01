#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlayGameMode.generated.h"

UCLASS()
class LEARNING_UNREAL_01_API APlayGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	APlayGameMode();
	virtual void StartPlay() override;
	virtual void Tick(float DeltaTime) override;
	void HandleLevelComplete();
protected:
	// TSubclassOf for the Blueprint version of PlayGameState
	UPROPERTY()
	TSubclassOf<class APlayGameState> PlayGameStateClass;

	// TSubclassOf for the Blueprint version of MyCharacter
	UPROPERTY()
	TSubclassOf<class AMyCharacter> PlayerCharacterClass;

	// TSubclassOf for the Blueprint version of PlayModeHUD
	UPROPERTY()
	TSubclassOf<class APlayModeHUD> PlayModeHUDClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "User Interface")
	TSubclassOf<class UUserWidget> FinishLevelWidgetClass;

	UPROPERTY()
	class UFinishLevelUserWidget* FinishLevelWidget;
private:

};
