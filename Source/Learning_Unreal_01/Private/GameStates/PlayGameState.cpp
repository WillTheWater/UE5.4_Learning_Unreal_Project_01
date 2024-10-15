#include "GameStates/PlayGameState.h"
#include "Kismet/GameplayStatics.h" // For UGameplayStatucs

APlayGameState::APlayGameState()
	: LevelTimer{ 0.f }
	, bIsPaused{ false }
{
}

void APlayGameState::BeginPlay()
{
	Super::BeginPlay();

	// Reset LevelTimer
	LevelTimer = 0.f;
}

void APlayGameState::UpdateLevelTimer(float DeltaTime)
{
	if (!bIsPaused) { LevelTimer += DeltaTime; }
}

void APlayGameState::TogglePause()
{
	if (!bIsPaused)
	{
		UGameplayStatics::SetGamePaused(GetWorld(), true);
		bIsPaused = true;
	}
	else
	{
		UGameplayStatics::SetGamePaused(GetWorld(), false);
		bIsPaused = false;
	}
}
