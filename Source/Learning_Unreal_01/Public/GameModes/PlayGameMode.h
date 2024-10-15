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
protected:
	// TSubclassOf for the Blueprint version of PlayGameState
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game State")
	TSubclassOf<class APlayGameState> PlayGameStateClass;

private:

};
