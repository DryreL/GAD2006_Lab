// Copyright 2022 © Gökdeniz Çetin


#include "COABaseCharacter.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ACOABaseCharacter::ACOABaseCharacter() :
	bDead(false),
	Health(100.0f),
	MaxHealth(100.0f),
	HealingRate(5.0f),
	WalkSpeed(300.0f),
	AttackStartupTime(0.5f),
	bRunning(false)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.f, 0.0f);
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;

	bReplicates = true;
}

// Called when the game starts or when spawned
void ACOABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACOABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bDead) 
	{
		Health = FMath::Min(MaxHealth, Health + HealingRate * DeltaTime);
	}
}

float ACOABaseCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (bDead) return 0.0f;
	DamageAmount = ModifyDamage(DamageAmount);
	Health -= DamageAmount;

	//GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::White, FString::Printf(TEXT("Health: %f"), Health));

	if (Health <= 0.f)
	{
		bDead = true;
		APlayerController* PlayerController = Cast<APlayerController>(GetController());
		if (PlayerController != nullptr)
		{
			DisableInput(PlayerController);
		}
		OnCharacterDied();
		GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::Red, FString::Printf(TEXT("Player died!")));
	}

	return 0.0f;
}

void ACOABaseCharacter::ChangeAnimState_Implementation(ECharAnimState NewState)
{
	AnimState = NewState;
	if (NewState == ECharAnimState::CAS_ATTACK)
	{
		if (HasAuthority())
		{
		// Start Time
		GWorld->GetTimerManager().SetTimer(AttackTimer, this, &ACOABaseCharacter::OnAttack, AttackStartupTime, false);
		}
	}
	else
	{
		// Clear Time
		GWorld->GetTimerManager().ClearTimer(AttackTimer);
	}
}

void ACOABaseCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACOABaseCharacter, Health);
}
