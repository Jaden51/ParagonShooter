#include "Revenant.h"
#include "Kismet/GameplayStatics.h"

void ARevenant::Shoot()
{
    Super::Shoot();

    UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, GetMesh(), TEXT("FX_Gun_Barrel"));
    UGameplayStatics::SpawnSoundAttached(MuzzleSound, GetMesh(), TEXT("FX_Gun_Barrel"));
}