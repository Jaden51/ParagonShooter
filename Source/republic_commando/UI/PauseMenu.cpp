#include "PauseMenu.h"
#include "Kismet/GameplayStatics.h"
#include "../Characters/ShooterController.h"

void UPauseMenu::NativeConstruct()
{
    Super::NativeConstruct();

    ResumeBtn->OnClicked.AddDynamic(this, &UPauseMenu::ResumeBtnClicked);
    OptionsBtn->OnClicked.AddDynamic(this, &UPauseMenu::OptionsBtnClicked);
    QuitBtn->OnClicked.AddDynamic(this, &UPauseMenu::QuitBtnClicked);
}

void UPauseMenu::ResumeBtnClicked()
{
    APlayerController *PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (PlayerController == nullptr)
        return;
    PlayerController->SetInputMode(FInputModeGameOnly());
    PlayerController->SetShowMouseCursor(false);
    UpdateState();
}

void UPauseMenu::OptionsBtnClicked()
{
}

void UPauseMenu::QuitBtnClicked()
{
    APlayerController *PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (PlayerController == nullptr)
        return;
    PlayerController->SetShowMouseCursor(true);
    RemoveHUD();
    UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainMenu"));
    UpdateState();
}

void UPauseMenu::RemoveHUD()
{
    AShooterController *ShooterController = Cast<AShooterController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
    ShooterController->RemoveHUD();
}

void UPauseMenu::UpdateState()
{
    RemoveFromParent();
    UGameplayStatics::SetGamePaused(GetWorld(), false);
}