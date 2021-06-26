#include "PlayableCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "Blueprint/UserWidget.h"
#include "../republic_commandoGameModeBase.h"

// Sets default values
APlayableCharacter::APlayableCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayableCharacter::BeginPlay()
{
	Super::BeginPlay();

	APlayerController *PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	PlayerController->SetInputMode(FInputModeGameOnly());
	Health = MaxHealth;
}

// Called every frame
void APlayableCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayableCharacter::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Mobility
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayableCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveSide"), this, &APlayableCharacter::MoveSide);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APlayableCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookSide"), this, &APlayableCharacter::LookSide);

	// Basic actions
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Pause"), EInputEvent::IE_Pressed, this, &APlayableCharacter::Pause);
}

void APlayableCharacter::Pause()
{
	PauseMenu = CreateWidget(Cast<APlayerController>(GetController()), PauseMenuClass);
	if (PauseMenu != nullptr)
	{
		APlayerController *PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		PlayerController->SetShowMouseCursor(true);
		PlayerController->SetInputMode(FInputModeUIOnly());
		PauseMenu->AddToViewport();
		UGameplayStatics::SetGamePaused(GetWorld(), true);
	}
}

void APlayableCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void APlayableCharacter::MoveSide(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void APlayableCharacter::LookUp(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}

void APlayableCharacter::LookSide(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}

void APlayableCharacter::Shoot(float Damage)
{
	if (GetController() == nullptr)
		return;

	FHitResult Hit;
	FRotator Rotation;

	if (GunTrace(Hit, Rotation))
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), BulletHit, Hit.Location, Rotation * -1);
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), ImpactSound, Hit.Location);

		if (Hit.GetActor() != nullptr)
		{
			FPointDamageEvent DamageEvent = FPointDamageEvent(Damage, Hit, Rotation.Vector() * -1, nullptr);
			Hit.GetActor()->TakeDamage(Damage, DamageEvent, GetController(), this);
		}
	}
}

float APlayableCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser)
{
	float DamageApplied = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	if (Health - DamageApplied <= 0)
	{
		Health = 0;
		Dead = true;
	}
	else
	{
		Health -= DamageApplied;
	}

	if (IsDead())
	{
		Arepublic_commandoGameModeBase *GameMode = GetWorld()->GetAuthGameMode<Arepublic_commandoGameModeBase>();
		if (GameMode != nullptr)
		{
			GameMode->PawnKilled(this);
		}
		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	return DamageApplied;
}

bool APlayableCharacter::IsDead() const
{
	return Dead;
}

bool APlayableCharacter::GunTrace(FHitResult &Hit, FRotator &Rotation)
{
	FVector Location;
	GetController()->GetPlayerViewPoint(Location, Rotation);

	FVector End = Location + Rotation.Vector() * MaxRange;

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	return GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1, Params);
}

float APlayableCharacter::GetHealthPercent() const
{
	return Health / MaxHealth;
}

void APlayableCharacter::ComboSave_Implementation()
{
    if (SaveAttack)
    {
        SaveAttack = false;
    }
}

void APlayableCharacter::ResetCombo_Implementation()
{
    SaveAttack = false;
    IsAttacking = false;
}

int32 APlayableCharacter::GetAmmo() const
{
	return Ammo;
}