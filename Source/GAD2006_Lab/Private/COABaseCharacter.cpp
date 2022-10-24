// Copyright 2022 © Gökdeniz Çetin


#include "COABaseCharacter.h"

// Sets default values
ACOABaseCharacter::ACOABaseCharacter() :
	bDead(false),
	Health(100.0f),
	MaxHealth(100.0f),
	HealingRate(5.0f),
	WalkSpeed(100.0f),
	RunSpeed(300.0f)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.f, 0.0f);
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
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

	if (!bDead) {
		Health = FMath::Min(MaxHealth, Health + HealingRate * DeltaTime);
	}
}

