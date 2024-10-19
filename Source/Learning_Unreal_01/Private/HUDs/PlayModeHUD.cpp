#include "HUDs/PlayModeHUD.h"
#include "Widgets/PlayerOverlay.h"
#include "Kismet/GameplayStatics.h"

APlayModeHUD::APlayModeHUD()
{
	static ConstructorHelpers::FClassFinder<UPlayerOverlay> PlayerOverlayBP(TEXT("/Game/Blueprints/UserWidgets/BP_PlayerOverlay"));
	if (PlayerOverlayBP.Succeeded())
	{
		PlayerOverlayClass = PlayerOverlayBP.Class;
	}
}

void APlayModeHUD::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* Controller = World->GetFirstPlayerController();
		if (Controller && PlayerOverlayClass)
		{
			Overlay = CreateWidget<UPlayerOverlay>(Controller, PlayerOverlayClass);
			Overlay->AddToViewport();
		}
	}
}
