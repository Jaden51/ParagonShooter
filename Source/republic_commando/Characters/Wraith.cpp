#include "Wraith.h"
#include "Kismet/GameplayStatics.h"
#include "Animation/AnimInstance.h"

void AWraith::Shoot()
{
    if (IsAttacking)
        return;

    Super::Shoot();

    IsAttacking = true;

    SwitchCase();

    UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, GetMesh(), TEXT("Muzzle_01"));
    UGameplayStatics::SpawnSoundAttached(MuzzleSound, GetMesh(), TEXT("Muzzle_01"));
}

void AWraith::ComboSave_Implementation()
{
    if (SaveAttack)
    {
        SaveAttack = false;
        SwitchCase();
    }
}

void AWraith::ResetCombo_Implementation()
{
    AttackCount = 0;
    SaveAttack = false;
    IsAttacking = false;
}

void AWraith::SwitchCase()
{
    switch (AttackCount)
    {
    case 0:
        AttackCount = 1;
        PlayAnimMontage(FireMontage);
        break;

    default:
        AttackCount = 0;
        PlayAnimMontage(FireMontage);
        break;
    }
}

void AWraith::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    // Abilities
    PlayerInputComponent->BindAction(TEXT("QAbility"), EInputEvent::IE_Pressed, this, &AWraith::QAbility);
    PlayerInputComponent->BindAction(TEXT("QAbility"), EInputEvent::IE_Released, this, &AWraith::QAbility);
}

void AWraith::QAbility()
{
    UE_LOG(LogTemp, Warning, TEXT("Q"));
}