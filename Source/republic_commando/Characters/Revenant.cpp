#include "Revenant.h"
#include "Kismet/GameplayStatics.h"

void ARevenant::Shoot()
{
    Super::Shoot(BasicAttackDamage);

    UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, GetMesh(), TEXT("FX_Gun_Barrel"));
    UGameplayStatics::SpawnSoundAttached(MuzzleSound, GetMesh(), TEXT("FX_Gun_Barrel"));
}

void ARevenant::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    // Abilities
    PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &ARevenant::Shoot);
}