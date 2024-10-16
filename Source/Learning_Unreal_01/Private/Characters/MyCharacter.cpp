#include "Characters/MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
// The following are all need for use of the EnhancedInput Sysytem
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
// ---------------------------------------------------------------


AMyCharacter::AMyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// Creates the SpringArm and Attaches it to the root component
	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera SpringArm"));
	CameraSpringArm->SetupAttachment(RootComponent);

	// Creates the SpringArm and Attaches it to the root component
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	PlayerCamera->SetupAttachment(CameraSpringArm);
}

void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	// This adds the Input Mapping Context to the Character Blueprint
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			// The IMC Blueprint is set in the editor via the Character Blueprint
			Subsystem->AddMappingContext(MyCharacterContext, 0);
		}
	}
}

void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MoveVector = Value.Get<FVector2D>();

	if (Controller)
	{
		AddMovementInput(GetActorForwardVector(), MoveVector.Y);
		AddMovementInput(GetActorRightVector(), MoveVector.X);
	}
}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// This casts the default player input to an Enhanced Input Component
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Binding the Move function
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyCharacter::Move);
	}
}

