#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

UCLASS()
class LEARNING_UNREAL_01_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMyPlayerController();

	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputMappingContext* MyControllerContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputAction* PauseAction;

	void PauseGame(const struct FInputActionValue& Value);
};
