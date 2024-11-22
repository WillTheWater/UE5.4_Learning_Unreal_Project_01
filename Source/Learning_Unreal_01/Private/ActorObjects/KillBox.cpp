#include "ActorObjects/KillBox.h"
#include "Components/BoxComponent.h"
#include "Characters/MyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h" // For ConstructorHelpers
#include "Controllers/MyPlayerController.h"
#include "GameModes/PlayGameMode.h"

AKillBox::AKillBox()
{
    PrimaryActorTick.bCanEverTick = false;

    KillBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("KillBoxComponent"));
    RootComponent = KillBoxComponent;

    KillBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AKillBox::OnBeginOverlap);
}

void AKillBox::BeginPlay()
{
	Super::BeginPlay();
}

void AKillBox::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    AMyCharacter* PlayerCharacter = CastChecked<AMyCharacter>(OtherActor);
    if (OtherActor && OtherActor->IsA(AMyCharacter::StaticClass()))
    {
        AMyPlayerController* PlayerController = CastChecked<AMyPlayerController>(PlayerCharacter->GetController());
        if (PlayerController) 
        {
            APlayGameMode* GameMode = CastChecked<APlayGameMode>(GetWorld()->GetAuthGameMode());
            if (GameMode)
            {
                GameMode->HandleLevelComplete();
            }
        }
    }
}