#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blaster.generated.h"

UCLASS()
class REPUBLIC_COMMANDO_API ABlaster : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABlaster();
	void PullTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent *Root;

	UPROPERTY(VisibleAnywhere);
	USkeletalMeshComponent *Mesh;

	//test

	UPROPERTY(EditAnywhere)
	UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere)
	UParticleSystem* BulletHit;

	UPROPERTY(EditAnywhere)
	float MaxRange = 100000;
};
