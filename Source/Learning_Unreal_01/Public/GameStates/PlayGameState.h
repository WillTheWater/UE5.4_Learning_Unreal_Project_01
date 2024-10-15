#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PlayGameState.generated.h"

UCLASS()
class LEARNING_UNREAL_01_API APlayGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	APlayGameState();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gameplay")
	float LevelTimer;

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void UpdateLevelTimer(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void TogglePause();

protected:
	virtual void BeginPlay() override;

private:
	bool bIsPaused;
};
