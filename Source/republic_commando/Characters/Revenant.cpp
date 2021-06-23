#include "Revenant.h"
#include "Kismet/GameplayStatics.h"

void ARevenant::Shoot()
{
    if (IsAttacking)
        return;

    Super::Shoot(BasicAttackDamage);

    IsAttacking = true;

    PlayAnimMontage(RevolverRecoil);

    UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, GetMesh(), TEXT("FX_Gun_Barrel"));
    UGameplayStatics::SpawnSoundAttached(MuzzleSound, GetMesh(), TEXT("FX_Gun_Barrel"));
}

void ARevenant::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    // Abilities
    PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &ARevenant::Shoot);
}