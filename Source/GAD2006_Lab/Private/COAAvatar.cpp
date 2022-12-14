// Copyright 2022 © Gökdeniz Çetin


#include "COAAvatar.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ACOAAvatar::ACOAAvatar() :
	RunSpeed(600.0f),
	Stamina(100.0f),
	MaxStamina(100.0f),
	StaminaGainRate(35.0f),
	StaminaDrainRate(15.0f),
	bStaminaDrained(false),
	MovementScale(1.0f)
{
	mSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	mSpringArm->SetupAttachment(RootComponent);
	mSpringArm->TargetArmLength = 300.0f;

	mCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	mCamera->SetupAttachment(mSpringArm, USpringArmComponent::SocketName);

	mCamera->bUsePawnControlRotation = false;
	mSpringArm->bUsePawnControlRotation = true;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->JumpZVelocity = 600.0f;

	bReplicates = true;
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

	if (GetCharacterMovement()->MovementMode == EMovementMode::MOVE_Walking)
	{

		if (bRunning && !bStaminaDrained)
		{
			//Walking or Waiting
			Stamina = FMath::Max(0.0f, Stamina - StaminaDrainRate * DeltaTime);

			if (Stamina == 0.0f)
			{
				bStaminaDrained = true;
				UpdateMovementParams();
			}
		}
		else
		{
			Stamina = FMath::Min(MaxStamina, Stamina + StaminaGainRate * DeltaTime);
			if (Stamina >= MaxStamina)
			{
				bStaminaDrained = false;
				UpdateMovementParams();
			}
		}

	}

	//Set Player Speed
	//GetCharacterMovement()->MaxWalkSpeed = currentSpeed;
	GEngine->AddOnScreenDebugMessage(0, DeltaTime * 2.0f, FColor::Yellow, FString::Printf(TEXT("SERVER: Are you tired?: %d - Stamina: %f"), bStaminaDrained, Stamina));
}

//Called to bind functionality input
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
}

void ACOAAvatar::MoveForward(float value)
{
	FRotator Rotation = GetController()->GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
	FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(ForwardDirection, value * MovementScale);

}

void ACOAAvatar::MoveRight(float value)
{
	FRotator Rotation = GetController()->GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
	FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(RightDirection, value * MovementScale);

}

void ACOAAvatar::UpdateMovementParams()
{
	MaxWalkSpeed = bRunning && !bStaminaDrained ? RunSpeed : WalkSpeed;
	OnRep_MaxWalkSpeed();
}

void ACOAAvatar::OnRep_MaxWalkSpeed()
{
	GetCharacterMovement()->MaxWalkSpeed = MaxWalkSpeed;
}

void ACOAAvatar::RunPressed()
{
	/*
	bRunning = true;
	UpdateMovementParams();
	//GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
	*/

	ChangeRunStateServer(true);
}

void ACOAAvatar::RunReleased()
{
	/*
	//GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	bRunning = false;
	UpdateMovementParams();
	*/

	ChangeRunStateServer(false);
}

void ACOAAvatar::ChangeRunStateServer_Implementation(bool pressed)
{
	bRunning = pressed;
	UpdateMovementParams();
}

void ACOAAvatar::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACOAAvatar, Stamina);
	DOREPLIFETIME(ACOAAvatar, MaxWalkSpeed);
}