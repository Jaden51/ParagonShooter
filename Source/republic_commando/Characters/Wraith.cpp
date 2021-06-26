#include "Wraith.h"
#include "Kismet/GameplayStatics.h"

void AWraith::Shoot()
{
    if (Ammo != 0)
    {
        if (IsAttacking)
            return;

        Super::Shoot(BasicAttackDamage);

        IsAttacking = true;

        PlayAnimMontage(FireMontage, 2);

        UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, GetMesh(), TEXT("Muzzle_01"));
        UGameplayStatics::SpawnSoundAttached(MuzzleSound, GetMesh(), TEXT("Muzzle_01"));

        Ammo--;
    }
}

void AWraith::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    // Abilities
    PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &AWraith::Shoot);
    PlayerInputComponent->BindAction(TEXT("QAbility"), EInputEvent::IE_Pressed, this, &AWraith::QAbility);
    PlayerInputComponent->BindAction(TEXT("Reload"), EInputEvent::IE_Pressed, this, &AWraith::Reload);
}

void AWraith::QAbility()
{
    if (IsAttacking)
        return;

    Super::Shoot(SniperDamage);

    IsAttacking = true;

    PlayAnimMontage(QAbilityMontage, 0.75);

    UGameplayStatics::SpawnEmitterAttached(SniperFlash, GetMesh(), TEXT("Muzzle_01"));
    UGameplayStatics::SpawnEmitterAttached(SniperTrailSmoke, GetMesh(), TEXT("Muzzle_01"));
    UGameplayStatics::SpawnSoundAttached(MuzzleSound, GetMesh(), TEXT("Muzzle_01"));
}

void AWraith::Reload()
{
    Ammo = 10;
}