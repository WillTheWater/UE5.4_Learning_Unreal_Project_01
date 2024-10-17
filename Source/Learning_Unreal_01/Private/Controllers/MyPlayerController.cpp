#include "Controllers/MyPlayerController.h"
#include "Kismet/GameplayStatics.h" // For UGameplayStatucs
#include "GameFramework/Pawn.h"
#include "Characters/MyCharacter.h"
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
        // Binding the Move function
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyPlayerController::Move);
		// Binding the PauseGame function
		EnhancedInputComponent->BindAction(PauseAction, ETriggerEvent::Started, this, &AMyPlayerController::PauseGame);
	}
    APawn* ControlledPawn = GetPawn();
    ControlledCharacter = CastChecked<AMyCharacter>(ControlledPawn); 
}

void AMyPlayerController::Move(const FInputActionValue& Value)
{
    if (ControlledCharacter && InputComponent)
    {
        FVector2D MoveVector = Value.Get<FVector2D>();

        // Apply movement input to the character
        ControlledCharacter->AddMovementInput(ControlledCharacter->GetActorForwardVector(), MoveVector.Y);
        ControlledCharacter->AddMovementInput(ControlledCharacter->GetActorRightVector(), MoveVector.X);
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
