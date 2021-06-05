#include "Wraith.h"
#include "Kismet/GameplayStatics.h"

void AWraith::Shoot()
{
    Super::Shoot();
    
    UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, GetMesh(), TEXT("Muzzle_01"));
    UGameplayStatics::SpawnSoundAttached(MuzzleSound, GetMesh(), TEXT("Muzzle_01"));
}