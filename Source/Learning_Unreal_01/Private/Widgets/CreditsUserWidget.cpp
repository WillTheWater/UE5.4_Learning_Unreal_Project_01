#include "Widgets/CreditsUserWidget.h"
#include "Kismet/GameplayStatics.h"

void UCreditsUserWidget::QuitGame()
{
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}
