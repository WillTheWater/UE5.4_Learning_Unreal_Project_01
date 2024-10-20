#include "Widgets/PlayerOverlay.h"
#include "Components/TextBlock.h"
#include "GameInstance/MyGameInstance.h"

void UPlayerOverlay::SetScore()
{
	GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	int32 Score = GameInstance->GetPlayerScore();
	if (ScoreText)
	{
		FText PlayerScore = FText::FromString(FString::Printf(TEXT("%d"), Score));
		ScoreText->SetText(PlayerScore);
	}
}