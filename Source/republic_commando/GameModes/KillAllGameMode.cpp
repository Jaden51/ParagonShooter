#include "KillAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "../AI/AIControl.h"

void AKillAllGameMode::PawnKilled(APawn *PawnKilled)
{
    Super::PawnKilled(PawnKilled);

    APlayerController *PlayerController = Cast<APlayerController>(PawnKilled->GetController());
    if (PlayerController != nullptr)
    {
        EndGame(false);
    }

    for (AAIControl* Controller : TActorRange<AAIControl>(GetWorld()))
    {
        if (!Controller->IsDead())
        {
            return;
        }
    }

    EndGame(true);
}

void AKillAllGameMode::EndGame(bool bIsWinner)
{
    for (AController *Controller : TActorRange<AController>(GetWorld()))
    {
        bool bIsPlayerWinner = Controller->IsPlayerController() == bIsWinner;
        Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
    }
}