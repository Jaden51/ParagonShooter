#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "../Characters/PlayableCharacter.h"
#include "ShooterGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class REPUBLIC_COMMANDO_API UShooterGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetPlayerClass(TSubclassOf<APlayableCharacter> CharacterClass);

	UFUNCTION(BlueprintCallable)
	TSubclassOf<APlayableCharacter> GetPlayerClass();

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<APlayableCharacter> SelectedClass;
};
