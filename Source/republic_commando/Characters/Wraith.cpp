#include "Wraith.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "../republic_commandoGameModeBase.h"

// Sets default values
AWraith::AWraith()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AWraith::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
}

// Called every frame
void AWraith::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AWraith::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AWraith::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveSide"), this, &AWraith::MoveSide);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AWraith::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookSide"), this, &AWraith::LookSide);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &AWraith::Shoot);
}

void AWraith::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AWraith::MoveSide(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AWraith::LookUp(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}

void AWraith::LookSide(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}

void AWraith::Shoot()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, GetMesh(), TEXT("Muzzle_01"));
	UGameplayStatics::SpawnSoundAttached(MuzzleSound, GetMesh(), TEXT("Muzzle_01"));

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
			FPointDamageEvent DamageEvent(Damage, Hit, Rotation.Vector() * -1, nullptr);
			Hit.GetActor()->TakeDamage(Damage, DamageEvent, GetController(), this);
		}
	}
}

float AWraith::TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser)
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

bool AWraith::IsDead() const
{
	return Dead;
}

bool AWraith::GunTrace(FHitResult &Hit, FRotator &Rotation)
{
	FVector Location;
	GetController()->GetPlayerViewPoint(Location, Rotation);

	FVector End = Location + Rotation.Vector() * MaxRange;

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	return GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1, Params);
}

float AWraith::GetHealthPercent() const
{
	return Health / MaxHealth;
}
