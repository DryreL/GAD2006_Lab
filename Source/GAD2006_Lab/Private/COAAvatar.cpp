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

// Called when the game starts or when spawned
void ACOAAvatar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACOAAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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
	GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
}

void ACOAAvatar::RunReleased()
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}