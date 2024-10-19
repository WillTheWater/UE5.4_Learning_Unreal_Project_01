#include "Widgets/PlayerOverlay.h"
#include "Components/TextBlock.h"

void UPlayerOverlay::SetScore(int32 Score)
{
	if (ScoreText)
	{
		FText PlayerScore = FText::FromString(FString::Printf(TEXT("%d"), Score));
		ScoreText->SetText(PlayerScore);
	}
}