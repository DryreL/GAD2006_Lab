// Copyright 2022 © Gökdeniz Çetin


#include "COAMyActor.h"

// Sets default values
ACOAMyActor::ACOAMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACOAMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACOAMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

