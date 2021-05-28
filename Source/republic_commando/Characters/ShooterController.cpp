#include "ShooterController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterController::BeginPlay()
{
    Super::BeginPlay();

    HUD = CreateWidget(this, HUDClass);
    if (HUD != nullptr)
    {
        HUD->AddToViewport();
    }
}

void AShooterController::GameHasEnded(class AActor *EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    HUD->RemoveFromViewport();

    if (bIsWinner)
    {
        UUserWidget *WinScreen = CreateWidget(this, WinScreenClass);
        if (WinScreen != nullptr)
        {
            WinScreen->AddToViewport();
        }
    }
    else
    {
        UUserWidget *LoseScreen = CreateWidget(this, LoseScreenClass);
        if (LoseScreen != nullptr)
        {
            LoseScreen->AddToViewport();
        }
    }

    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}
