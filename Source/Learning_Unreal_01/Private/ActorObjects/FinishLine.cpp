#include "ActorObjects/FinishLine.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Characters/MyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h" // For ConstructorHelpers
#include "GameModes/PlayGameMode.h"

AFinishLine::AFinishLine()
{
	PrimaryActorTick.bCanEverTick = true;

	Platform = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform"));
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	RootComponent = Platform;
	TriggerBox->SetupAttachment(RootComponent);
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AFinishLine::OnOverlapTiggerBox);
}

void AFinishLine::BeginPlay()
{
	Super::BeginPlay();
}

void AFinishLine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFinishLine::OnOverlapTiggerBox(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->IsA(AMyCharacter::StaticClass()))
	{
		UE_LOG(LogTemp, Warning, TEXT("Level Completed"));
		// Notify the game mode that the level is finished
		APlayGameMode* GameMode = Cast<APlayGameMode>(UGameplayStatics::GetGameMode(this));
		if (GameMode)
		{
			GameMode->HandleLevelComplete();
		}
	}
}


