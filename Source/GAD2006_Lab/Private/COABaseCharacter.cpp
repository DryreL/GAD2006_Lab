// Copyright 2022 © Gökdeniz Çetin


#include "COABaseCharacter.h"

// Sets default values
ACOABaseCharacter::ACOABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

}

