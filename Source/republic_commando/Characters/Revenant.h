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
	void Shoot() override;
};
