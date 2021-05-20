

#include "Wraith.h"

// Sets default values
AWraith::AWraith()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AWraith::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AWraith::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AWraith::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AWraith::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveSide"), this, &AWraith::MoveSide);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AWraith::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookSide"), this, &AWraith::LookSide);
	PlayerInputComponent->BindAction(TEXT("JUMP"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
}

void AWraith::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AWraith::MoveSide(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AWraith::LookUp(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}

void AWraith::LookSide(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}
