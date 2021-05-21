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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere);
	USkeletalMeshComponent* Mesh;
};
