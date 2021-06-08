#include "KillAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"
#include "../Characters/ShooterController.h"
#include "../AI/AIControl.h"

void AKillAllGameMode::BeginPlay()
{
    Super::BeginPlay();
    TArray<AActor*> PlayerStartActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), PlayerStartActors);

    for (AActor* TActor: PlayerStartActors)
    {
        APlayerStart *TPlayerStart = Cast<APlayerStart>(TActor);

        if (TPlayerStart != nullptr)
        {
            SpawnTransform = TPlayerStart->GetActorTransform();
            GameInst = Cast<UShooterGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
            ClassToSpawn = GameInst->GetPlayerClass();
            Cast<AShooterController>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->SpawnCharacter(ClassToSpawn, SpawnTransform);
        }
    }
}

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