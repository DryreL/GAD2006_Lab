// Copyright 2022 © Gökdeniz Çetin

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "COAMyActor.generated.h"

UCLASS()
class GAD2006_LAB_API ACOAMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACOAMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	int Count;
};
