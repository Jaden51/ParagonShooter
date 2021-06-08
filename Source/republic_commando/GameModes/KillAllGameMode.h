#pragma once

#include "CoreMinimal.h"
#include "../republic_commandoGameModeBase.h"
#include "ShooterGameInstance.h"
#include "KillAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class REPUBLIC_COMMANDO_API AKillAllGameMode : public Arepublic_commandoGameModeBase
{
	GENERATED_BODY()

public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PawnKilled(APawn *PawnKilled) override;

	void EndGame(bool bIsWinner);

private:
	FTransform SpawnTransform;

	UShooterGameInstance *GameInst;

	TSubclassOf<ACharacter> ClassToSpawn;
};
