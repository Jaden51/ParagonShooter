#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Wraith.generated.h"

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
	UFUNCTION(BlueprintPure)
	bool IsDead() const;

	void Shoot();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser) override;

private:
	void MoveForward(float AxisValue);
	void LookUp(float AxisValue);
	void MoveSide(float AxisValue);
	void LookSide(float AxisValue);

	UPROPERTY(EditAnywhere)
	UParticleSystem *MuzzleFlash;

	UPROPERTY(EditAnywhere)
	USoundBase *MuzzleSound;

	UPROPERTY(EditAnywhere)
	UParticleSystem *BulletHit;

	UPROPERTY(EditAnywhere)
	USoundBase *ImpactSound;

	UPROPERTY(EditAnywhere)
	float MaxRange = 100000;

	UPROPERTY(EditAnywhere)
	float Damage = 10;

	UPROPERTY(EditAnywhere)
	float MaxHealth = 100;

	UPROPERTY(VisibleAnywhere)
	float Health;

	UPROPERTY(EditAnywhere)
	bool Dead = false;

	bool GunTrace(FHitResult &Hit, FRotator &Rotation);
};
