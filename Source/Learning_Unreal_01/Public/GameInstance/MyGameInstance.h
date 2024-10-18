#pragma once
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Widgets/LevelManager.h"
#include "MyGameInstance.generated.h"

UCLASS()
class LEARNING_UNREAL_01_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;
	virtual void OnStart() override;
	virtual void StartGameInstance() override;

	LevelManager* GetLevelMgr() { return &MyLevelManager; }

	UFUNCTION(BlueprintCallable, Category = "Player Data")
	int32 GetPlayerScore() const { return PlayerScore; }

	UFUNCTION(BlueprintCallable, Category = "Player Data")
	int32 GetPlayerLevel() const { return PlayerLevel; }
	
	UFUNCTION(BlueprintCallable, Category = "Graphics Settings")
	int32 GetGraphicsQuality() const { return GraphicsQuality; }

	UFUNCTION(BlueprintCallable, Category = "Player Data")
	void SetPlayerScore(int32 NewScore);

	UFUNCTION(BlueprintCallable, Category = "Player Data")
	void SetPlayerLevel(int32 NewLevel);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Data")
	ELevels CurrentLevel;

	UFUNCTION(BlueprintCallable, Category = "Graphics Settings")
	void SetGraphicsQuality(int32 NewQuality);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Data")
	int32 PlayerScore = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Data")
	int32 PlayerLevel = 1;

	// Graphic Settings: 1 = Low, 2 = Medium, 3 = High, 4 = Ultra
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Graphics Settings")
	int32 GraphicsQuality = 3;

private:
	LevelManager MyLevelManager;
};
