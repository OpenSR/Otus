#include "Otus/Public/Character/PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PluginWeaponActor.h"
#include "TestWeaponActor.h"

APlayerCharacter::APlayerCharacter()
{
	USpringArmComponent* SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 300.0f;
	SpringArm->bUsePawnControlRotation = true;

	UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Move bind
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	// Weapon bind
	PlayerInputComponent->BindAction("SpawnModuleWeapon", IE_Pressed, this, &APlayerCharacter::SpawnModuleWeapon);
	PlayerInputComponent->BindAction("SpawnPluginWeapon", IE_Pressed, this, &APlayerCharacter::SpawnPluginWeapon);
}

void APlayerCharacter::MoveForward(float Value)
{
	if (Controller && Value != 0.0f)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void APlayerCharacter::MoveRight(float Value)
{
	if (Controller && Value != 0.0f)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void APlayerCharacter::SpawnModuleWeapon()
{
	FVector SpawnLocation = GetActorLocation() + GetActorForwardVector() * 200.f;
	GetWorld()->SpawnActor<ATestWeaponActor>(ATestWeaponActor::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
}

void APlayerCharacter::SpawnPluginWeapon()
{
	FVector SpawnLocation = GetActorLocation() + GetActorForwardVector() * 200.f;
	GetWorld()->SpawnActor<APluginWeaponActor>(APluginWeaponActor::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
}