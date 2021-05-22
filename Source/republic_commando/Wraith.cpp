#include "Wraith.h"
#include "Blaster.h"

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

	Blaster = GetWorld()->SpawnActor<ABlaster>(BlasterClass);
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	Blaster->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	Blaster->SetOwner(this);
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

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &AWraith::Shoot);
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

void AWraith::Shoot()
{
	Blaster->PullTrigger();
}
