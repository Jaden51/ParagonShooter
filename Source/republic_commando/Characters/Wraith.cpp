#include "Wraith.h"
#include "Kismet/GameplayStatics.h"

void AWraith::Shoot()
{
    Super::Shoot();
    
    UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, GetMesh(), TEXT("Muzzle_01"));
    UGameplayStatics::SpawnSoundAttached(MuzzleSound, GetMesh(), TEXT("Muzzle_01"));
}

void AWraith::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    // Abilities
    PlayerInputComponent->BindAction(TEXT("QAbility"), EInputEvent::IE_Pressed, this, &AWraith::QAbility);
    PlayerInputComponent->BindAction(TEXT("QAbility"), EInputEvent::IE_Released, this, &AWraith::QAbilityReleased);
}

void AWraith::QAbility()
{
    GetMesh()->PlayAnimation(QAbilityAnimation, false);
}