#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Wraith.generated.h"

class ABlaster;

UCLASS()
class REPUBLIC_COMMANDO_API AWraith : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWraith();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

private:
	void MoveForward(float AxisValue);
	void LookUp(float AxisValue);
	void MoveSide(float AxisValue);
	void LookSide(float AxisValue);
	void Shoot();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABlaster> BlasterClass;

	UPROPERTY()
	ABlaster* Blaster;
};
