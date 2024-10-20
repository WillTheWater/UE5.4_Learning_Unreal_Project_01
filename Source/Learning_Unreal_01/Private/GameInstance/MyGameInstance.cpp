#include "GameInstance/MyGameInstance.h"

void UMyGameInstance::Init()
{
    Super::Init();
    if (GEngine) { UE_LOG(LogTemp, Warning, TEXT("My Init Game Instance")); }
    if (GEngine) { UE_LOG(LogTemp, Warning, TEXT("Player Score: %d"), PlayerScore); }
    if (GEngine) { UE_LOG(LogTemp, Warning, TEXT("Player Level: %d"), PlayerLevel); }
    if (GEngine) { UE_LOG(LogTemp, Warning, TEXT("Graphics Quality: %d"), GraphicsQuality); }
    PickupStates;
}

void UMyGameInstance::OnStart()
{
    Super::OnStart();
    CurrentLevel = ELevels::MainMenu;
}

void UMyGameInstance::StartGameInstance()
{
    Super::StartGameInstance();
}

void UMyGameInstance::PickupItem(int32 PickupID)
{
    PickupStates.Add(PickupID, true);  // Mark as collected
    PlayerScore++;
    UE_LOG(LogTemp, Warning, TEXT("PickupID %d has been collected"), PickupID);
}

bool UMyGameInstance::IsPickupCollected(int32 PickupID) const
{
    const bool* Collected = PickupStates.Find(PickupID);
    if (!Collected)
    {
        UE_LOG(LogTemp, Warning, TEXT("PickupID %d not found in PickupStates"), PickupID);
        return false;
    }
    UE_LOG(LogTemp, Warning, TEXT("PickupID %d collected state: %s"), PickupID, *Collected ? TEXT("True") : TEXT("False"));
    return *Collected;
}

void UMyGameInstance::SetPlayerScore(int32 NewScore)
{
    PlayerScore = NewScore;
}

void UMyGameInstance::SetPlayerLevel(int32 NewLevel)
{
    PlayerLevel = NewLevel;
}

void UMyGameInstance::SetGraphicsQuality(int32 NewQuality)
{
    GraphicsQuality = NewQuality;
}
