#pragma once

#include "CoreMinimal.h"
#include "../republic_commandoGameModeBase.h"
#include "KillAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class REPUBLIC_COMMANDO_API AKillAllGameMode : public Arepublic_commandoGameModeBase
{
	GENERATED_BODY()

public:
	virtual void PawnKilled(APawn *PawnKilled) override;

private:
	void EndGame(bool bIsWinner);
};
