#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "PauseMenu.generated.h"

/**
 * 
 */
UCLASS()
class REPUBLIC_COMMANDO_API UPauseMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	void NativeConstruct() override;

	UFUNCTION()
	void ResumeBtnClicked();

	UFUNCTION()
	void OptionsBtnClicked();

	UFUNCTION()
	void QuitBtnClicked();

	void RemoveHUD();

private:
	void UpdateState();

	UPROPERTY(meta = (BindWidget))
	UButton *ResumeBtn;

	UPROPERTY(meta = (BindWidget))
	UButton *OptionsBtn;

	UPROPERTY(meta = (BindWidget))
	UButton *QuitBtn;
};
