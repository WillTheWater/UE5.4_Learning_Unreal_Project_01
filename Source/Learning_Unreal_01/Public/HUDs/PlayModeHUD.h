#pragma once
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayModeHUD.generated.h"

UCLASS()
class LEARNING_UNREAL_01_API APlayModeHUD : public AHUD
{
	GENERATED_BODY()

public:
	APlayModeHUD();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UPlayerOverlay> PlayerOverlayClass;
	
	UPROPERTY()
	UPlayerOverlay* Overlay;
};
