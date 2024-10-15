#include "GameModes/PlayGameMode.h"
#include "GameStates/PlayGameState.h"
#include "Characters/MyCharacter.h"
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
}

void APlayGameMode::StartPlay()
{
	Super::StartPlay();
}

void APlayGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APlayGameState* PlayState = GetGameState<APlayGameState>();
	if (PlayState) { PlayState->UpdateLevelTimer(DeltaTime); }
}
