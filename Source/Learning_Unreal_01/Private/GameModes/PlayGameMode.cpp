#include "GameModes/PlayGameMode.h"
#include "GameStates/PlayGameState.h"

APlayGameMode::APlayGameMode()
{
	// Enables tick for this GameMode
	PrimaryActorTick.bCanEverTick = true;

	// Sets Blueprint version of PlayGameState as the default GameState
	static ConstructorHelpers::FClassFinder<APlayGameState> PlayGameStateBP(TEXT("/Game/Blueprints/GameStates/BP_PlayGameState"));
	if (PlayGameStateBP.Succeeded()) { GameStateClass = PlayGameStateBP.Class; }
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
