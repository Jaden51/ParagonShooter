#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "republic_commandoGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class REPUBLIC_COMMANDO_API Arepublic_commandoGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void PawnKilled(APawn* PawnKilled);
	
};
