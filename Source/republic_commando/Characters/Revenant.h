#pragma once

#include "CoreMinimal.h"
#include "PlayableCharacter.h"
#include "Revenant.generated.h"

/**
 * 
 */
UCLASS()
class REPUBLIC_COMMANDO_API ARevenant : public APlayableCharacter
{
	GENERATED_BODY()

public:
	void Shoot();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere)
	float BasicAttackDamage = 50;
};
