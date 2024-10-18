#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CreditsGameMode.generated.h"

UCLASS()
class LEARNING_UNREAL_01_API ACreditsGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	ACreditsGameMode();
	virtual void StartPlay() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "User Interface")
	TSubclassOf<class UUserWidget> CreditsWidgetClass;

	UPROPERTY()
	class UCreditsUserWidget* CreditsWidget;
};
