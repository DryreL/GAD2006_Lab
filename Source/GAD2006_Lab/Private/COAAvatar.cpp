// Copyright 2022 © Gökdeniz Çetin


#include "COAAvatar.h"

// Sets default values
ACOAAvatar::ACOAAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	mSpringArm->SetupAttachment(RootComponent);
	mSpringArm->TargetArmLength = 300.0f;

	mCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	mCamera->SetupAttachment(mSpringArm, USpringArmComponent::SocketName);

	mCamera->bUsePawnControlRotation = false;
	mSpringArm->bUsePawnControlRotation = true;
	bUseControllerRotationYaw = false;
}

// Called to bind functionality to input
void ACOAAvatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Turn", this, &ACharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &ACharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACOAAvatar::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACOAAvatar::MoveRight);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ACOAAvatar::RunPressed);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &ACOAAvatar::RunReleased);

	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &ACOAAvatar::AttackPressed);
	PlayerInputComponent->BindAction("Attack", IE_Released, this, &ACOAAvatar::AttackReleased);
}

void ACOAAvatar::MoveForward(float value)
{
	FRotator Rotation = GetController()->GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
	FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(ForwardDirection, value);
}

void ACOAAvatar::MoveRight(float value)
{
	FRotator Rotation = GetController()->GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
	FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(RightDirection, value);
}

void ACOAAvatar::RunPressed()
{
	//GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
	if (!bStaminaDrained)
	{
		bRunning = true;
	}
}

void ACOAAvatar::RunReleased()
{
	//GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	bRunning = false;
}

void ACOAAvatar::AttackPressed()
{
	if (!(GetCharacterMovement()->MovementMode == EMovementMode::MOVE_Flying))
	{
		bAttacking = true;
	}
}

void ACOAAvatar::AttackReleased()
{
	bAttacking = false;

}

// Called when the game starts or when spawned
void ACOAAvatar::BeginPlay()
{
	Super::BeginPlay();
}

void ACOAAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	float currentSpeed = WalkSpeed;

	if (!bRunning || GetCharacterMovement()->GetLastUpdateVelocity().IsNearlyZero())
	{
		if (GetCharacterMovement()->MovementMode == EMovementMode::MOVE_Walking)
		{
			//Walking or Waiting
			Stamina += DeltaTime * StaminaGainRate;

			if (bStaminaDrained && Stamina >= MaxStamina)
				bStaminaDrained = false;
		}
	}
	else
	{
		//Running
		if (!bStaminaDrained && GetCharacterMovement()->MovementMode == EMovementMode::MOVE_Walking && !GetCharacterMovement()->GetLastUpdateVelocity().IsNearlyZero())
		{
			Stamina -= DeltaTime * StaminaDrainRate;
			currentSpeed = RunSpeed;

			if (Stamina <= 0.0f)
				bStaminaDrained = true;
		}
	}

	Stamina = FMath::Clamp(Stamina, 0.0f, MaxStamina);

	//Set Player Speed
	GetCharacterMovement()->MaxWalkSpeed = currentSpeed;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-10, 1.f, FColor::Purple, FString::Printf(TEXT("Are you tired?: %d"), bStaminaDrained, Stamina));
		GEngine->AddOnScreenDebugMessage(-20, 1.f, FColor::Orange, FString::Printf(TEXT("Stamina: %f"), Stamina));
	}

	if (GetCharacterMovement()->MovementMode == EMovementMode::MOVE_Walking)
	{

	}

	if (bAttacking == true && !(GetCharacterMovement()->MovementMode == EMovementMode::MOVE_Falling))
	{
		GetCharacterMovement()->Deactivate();
		GetCharacterMovement()->bOrientRotationToMovement = false;
	}
	else
	{
		GetCharacterMovement()->Activate();
		GetCharacterMovement()->bOrientRotationToMovement = true;
	}
}
