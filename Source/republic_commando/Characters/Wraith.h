#pragma once

#include "CoreMinimal.h"
#include "PlayableCharacter.h"
#include "Wraith.generated.h"

/**
 * 
 */
UCLASS()
class REPUBLIC_COMMANDO_API AWraith : public APlayableCharacter
{
	GENERATED_BODY()

public:
	void Shoot();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

	virtual void QAbility();

private:
	UPROPERTY(EditAnywhere)
	UAnimMontage *FireMontage;
	UPROPERTY(EditAnywhere)
	float BasicAttackDamage = 25;

	UPROPERTY(EditAnywhere)
	UAnimMontage *QAbilityMontage;
	UPROPERTY(EditAnywhere)
	UParticleSystem *SniperFlash;
	UPROPERTY(EditAnywhere)
	UParticleSystem *SniperTrailSmoke;
	UPROPERTY(EditAnywhere)
	float SniperDamage = 0;
};
