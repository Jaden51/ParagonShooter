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

	virtual void QAbility();
	virtual void QAbilityReleased();

private:
	UPROPERTY(EditAnywhere)
	UAnimationAsset *QAbilityAnimation;
};
