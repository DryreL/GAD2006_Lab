// Copyright 2022 © Gökdeniz Çetin


#include "COAAvatar.h"

// Sets default values
ACOAAvatar::ACOAAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

}

