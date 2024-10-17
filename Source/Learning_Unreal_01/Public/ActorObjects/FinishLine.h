#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FinishLine.generated.h"

UCLASS()
class LEARNING_UNREAL_01_API AFinishLine : public AActor
{
	GENERATED_BODY()
	
public:	
	AFinishLine();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Trigger Box")
	class UStaticMeshComponent* Platform;

	UPROPERTY(VisibleAnywhere, Category = "Trigger Box")
	class UBoxComponent* TriggerBox;

	UFUNCTION()
	void OnOverlapTiggerBox(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
