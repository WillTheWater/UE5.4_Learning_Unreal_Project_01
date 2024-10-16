#include "Controllers/MyPlayerController.h"
#include "Kismet/GameplayStatics.h" // For UGameplayStatucs
// The following are all need for use of the EnhancedInput Sysytem
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
// ---------------------------------------------------------------

AMyPlayerController::AMyPlayerController()
{
    // Enable ticking and input processing during pause
    bShouldPerformFullTickWhenPaused = true;
}

void AMyPlayerController::BeginPlay()
{
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// The IMC Blueprint is set in the editor via the Character Blueprint
		Subsystem->AddMappingContext(MyControllerContext, 0);
	}

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		// Binding the PauseGame function
		EnhancedInputComponent->BindAction(PauseAction, ETriggerEvent::Started, this, &AMyPlayerController::PauseGame);
	}
}

void AMyPlayerController::PauseGame(const FInputActionValue& Value)
{
    bool bIsPaused = UGameplayStatics::IsGamePaused(this);

    // Toggle the paused state
    if (bIsPaused)
    {
        // Game is currently paused, so unpause it
        UGameplayStatics::SetGamePaused(this, false);
        SetInputMode(FInputModeGameOnly()); // Set input mode back to gameplay
        bShowMouseCursor = false; // Hide mouse cursor
    }
    else
    {
        // Game is currently running, so pause it
        UGameplayStatics::SetGamePaused(this, true);
        SetInputMode(FInputModeGameAndUI()); // Set input mode to handle UI and game
        bShowMouseCursor = true; // Show mouse cursor
    }
}
