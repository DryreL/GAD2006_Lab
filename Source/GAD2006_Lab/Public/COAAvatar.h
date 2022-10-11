// Copyright 2022 © Gökdeniz Çetin

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "COAAvatar.generated.h"

UCLASS()
class GAD2006_LAB_API ACOAAvatar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACOAAvatar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
