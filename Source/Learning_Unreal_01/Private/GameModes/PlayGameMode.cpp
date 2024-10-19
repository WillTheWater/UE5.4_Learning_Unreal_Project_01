#include "GameModes/PlayGameMode.h"
#include "GameStates/PlayGameState.h"
#include "Characters/MyCharacter.h"
#include "Controllers/MyPlayerController.h"
#include "Widgets/FinishLevelUserWidget.h"
#include "HUDs/PlayModeHUD.h"
#include "Kismet/GameplayStatics.h" // For UGameplayStatucs

APlayGameMode::APlayGameMode()
{
	// Enables tick for this GameMode
	PrimaryActorTick.bCanEverTick = true;

	// Sets Blueprint version of PlayGameState as the default GameState
	static ConstructorHelpers::FClassFinder<APlayGameState> PlayGameStateBP(TEXT("/Game/Blueprints/GameStates/BP_PlayGameState"));
	if (PlayGameStateBP.Succeeded()) { GameStateClass = PlayGameStateBP.Class; }

	// Sets Blueprint version of MyCharacter as the default character to spawn
	static ConstructorHelpers::FClassFinder<AMyCharacter> MyCharacterBP(TEXT("/Game/Blueprints/Characters/BP_MyCharacter"));
	if (MyCharacterBP.Succeeded()) 
	{ 
		PlayerCharacterClass = MyCharacterBP.Class;
		DefaultPawnClass = PlayerCharacterClass; // Sets the BP_MyCharacter as the default pawn for PlayGameMode 
	}

    // Sets Blueprint version of PlayModeHUD as the default HUD
    static ConstructorHelpers::FClassFinder<APlayModeHUD> PlayModeHUDBP(TEXT("/Game/Blueprints/UserWidgets/BP_PlayModeHUD"));
    if (PlayModeHUDBP.Succeeded())
    {
        PlayModeHUDClass = PlayModeHUDBP.Class;
        HUDClass = PlayModeHUDClass; // Sets the PlayModeHUD as the default HUD for PlayGameMode 
    }

    // Sets Blueprint version of MyController as default controller
    static ConstructorHelpers::FClassFinder<AMyPlayerController> MyControllerBP(TEXT("/Game/Blueprints/Input/BP_MyController"));
    if (MyControllerBP.Succeeded())
    {
        PlayerControllerClass = MyControllerBP.Class;
    }

    // Assigning the Blueprint of the widget to FinishLevelWidgetClass
    static ConstructorHelpers::FClassFinder<UUserWidget> WidgetClass(TEXT("/Game/Blueprints/UserWidgets/BP_FinishLevelWidget"));
    if (WidgetClass.Succeeded())
    {
        FinishLevelWidgetClass = WidgetClass.Class;
    }
}

void APlayGameMode::StartPlay()
{
	Super::StartPlay();
    AMyPlayerController* MyController = CastChecked<AMyPlayerController>(GetWorld()->GetFirstPlayerController());
    if (MyController)
    {
        // Show the mouse cursor
        MyController->bShowMouseCursor = false;

        // Set input mode to Game only
        FInputModeGameOnly GameMode;
        MyController->SetInputMode(GameMode);
    }
}

void APlayGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APlayGameState* PlayState = GetGameState<APlayGameState>();
	if (PlayState) { PlayState->UpdateLevelTimer(DeltaTime); }
}

void APlayGameMode::HandleLevelComplete()
{
    // Pause the game
    UGameplayStatics::SetGamePaused(GetWorld(), true);

    // Create the finish level UI
    if (FinishLevelWidgetClass)
    {
        auto FinishLevel = CastChecked<UFinishLevelUserWidget>(CreateWidget<UUserWidget>(GetWorld(), FinishLevelWidgetClass));
        if (FinishLevel)
        {
            FinishLevel->AddToViewport();
            // Get the player controller
            AMyPlayerController* MyController = CastChecked<AMyPlayerController>(GetWorld()->GetFirstPlayerController());
            if (MyController)
            {
                // Show the mouse cursor
                MyController->bShowMouseCursor = true;

                // Set input mode to UI only
                FInputModeUIOnly InputMode; 
                //InputMode.SetWidgetToFocus(FinishLevel->TakeWidget()); 
                MyController->SetInputMode(InputMode); 
            }
        }
    }
}
