#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KillBox.generated.h"

UCLASS()
class LEARNING_UNREAL_01_API AKillBox : public AActor
{
	GENERATED_BODY()

public:
	AKillBox();

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UBoxComponent* KillBoxComponent;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	virtual void BeginPlay() override;

};