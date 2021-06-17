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
	void Shoot() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ComboSave();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ResetCombo();

	virtual void QAbility();

private:
	UPROPERTY(EditAnywhere)
	UAnimMontage *FireMontage;

	UPROPERTY(EditAnywhere)
	UAnimMontage *QAbilityMontage;

	UPROPERTY(EditAnywhere)
	UParticleSystem *SniperFlash;
	UPROPERTY(EditAnywhere)
	UParticleSystem *SniperTrailSmoke;

	bool IsAttacking = false;
	bool SaveAttack;
};
