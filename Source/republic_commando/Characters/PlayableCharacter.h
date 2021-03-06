#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayableCharacter.generated.h"

UCLASS()
class REPUBLIC_COMMANDO_API APlayableCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayableCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintPure)
	bool IsDead() const;

	UFUNCTION(BlueprintPure)
	int32 GetAmmo() const;
	UFUNCTION(BlueprintPure)
	int32 GetMaxAmmo() const;

	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const;

	virtual void Shoot(float Damage);

	void Pause();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser) override;

	void MoveForward(float AxisValue);
	void LookUp(float AxisValue);
	void MoveSide(float AxisValue);
	void LookSide(float AxisValue);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ComboSave();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ResetCombo();

protected:
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
	float MaxHealth = 100;
	UPROPERTY(VisibleAnywhere)
	float Health;

	UPROPERTY(EditAnywhere)
	bool Dead = false;

	bool GunTrace(FHitResult &Hit, FRotator &Rotation);

	bool IsAttacking = false;
	bool SaveAttack;

	UPROPERTY(EditAnywhere)
	int32 MaxAmmo;
	int32 Ammo;
	UPROPERTY(EditAnywhere)
	UAnimMontage *ReloadAnim;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> PauseMenuClass;

	UPROPERTY(VisibleAnywhere)
	UUserWidget *PauseMenu;
};
