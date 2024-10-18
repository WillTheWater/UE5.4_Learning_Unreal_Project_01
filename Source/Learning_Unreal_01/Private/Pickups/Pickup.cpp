#include "Pickups/Pickup.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Characters/MyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameInstance/MyGameInstance.h"

APickup::APickup()
	: Amplitude{ 0.5f }
	, Frequency{ 2.5f }
	, RotationSpeed{ 0.5f }
	, RunningTime{ 0.f }
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionShpere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	CollisionShpere->BodyInstance.SetCollisionProfileName("OverlapAllDynamic");
	RootComponent = CollisionShpere;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CollectiableMesh"));
	StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	StaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	RotationComponent = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotationComponent"));
}

void APickup::BeginPlay()
{
	Super::BeginPlay();
	CollisionShpere->OnComponentBeginOverlap.AddDynamic(this, &APickup::BeginOverlap);
}

float APickup::TransformSin() const
{
	return Amplitude * FMath::Sin(RunningTime * Frequency);
}

float APickup::TransformCos() const
{
	return Amplitude * FMath::Cos(RunningTime * Frequency);
}

float APickup::TransformRotation() const
{
	return RotationSpeed;
}

void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;
	AddActorWorldOffset(FVector(0.f, 0.f, TransformSin()));
}

void APickup::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AMyCharacter* player = CastChecked<AMyCharacter>(OtherActor))
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(1, 10.f, FColor::Cyan, "Overlapped");
		}
		// Notify the game mode that the level is finished
		UMyGameInstance* GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
		if (GameInstance)
		{
			GameInstance->PickupItem();
			Destroy();
		}
	}
}

