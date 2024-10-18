#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class LEARNING_UNREAL_01_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	APickup();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, Category = "Collectiables")
	class USphereComponent* CollisionShpere;

	UPROPERTY(VisibleDefaultsOnly, Category = "Collectiables")
	class UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleDefaultsOnly, Category = "Collectiables")
	class URotatingMovementComponent* RotationComponent;

	UFUNCTION(BlueprintPure)
	float TransformSin() const;

	UFUNCTION(BlueprintPure)
	float TransformCos() const;

	UFUNCTION(BlueprintPure)
	float TransformRotation() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hover Parameters")
	float Amplitude;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hover Parameters")
	float Frequency;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hover Parameters")
	float RotationSpeed;

private:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime;
};
