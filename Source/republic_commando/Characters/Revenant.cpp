#include "Revenant.h"
#include "Kismet/GameplayStatics.h"

void ARevenant::Shoot()
{
    Super::Shoot();

    UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, GetMesh(), TEXT("Muzzle_02"));
    UGameplayStatics::SpawnSoundAttached(MuzzleSound, GetMesh(), TEXT("Muzzle_02"));
}