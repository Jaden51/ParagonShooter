#include "ShooterGameInstance.h"

void UShooterGameInstance::SetPlayerClass_Implementation(TSubclassOf<APlayableCharacter> CharacterClass)
{
    SelectedClass = CharacterClass;
}

TSubclassOf<APlayableCharacter> UShooterGameInstance::GetPlayerClass()
{
    return SelectedClass;
}