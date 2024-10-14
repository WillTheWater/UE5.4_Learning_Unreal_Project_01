#include "GameInstance/MyGameInstance.h"

void UMyGameInstance::Init()
{
    Super::Init();

    if (GEngine) { UE_LOG(LogTemp, Warning, TEXT("My Init Game Instance")); }
    if (GEngine) { UE_LOG(LogTemp, Warning, TEXT("Player Score: %d"), PlayerScore); }
    if (GEngine) { UE_LOG(LogTemp, Warning, TEXT("Player Level: %d"), PlayerLevel); }
    if (GEngine) { UE_LOG(LogTemp, Warning, TEXT("Graphics Quality: %d"), GraphicsQuality); }
}

void UMyGameInstance::OnStart()
{
    Super::OnStart();

    if (GEngine) { UE_LOG(LogTemp, Warning, TEXT("My On Start")); }
}

void UMyGameInstance::StartGameInstance()
{
    Super::StartGameInstance();
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
