// Copyright 2022 © Gökdeniz Çetin

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "COABaseCharacter.generated.h"

UCLASS()
class GAD2006_LAB_API ACOABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACOABaseCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "COA")
		bool bDead;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "COA")
		float Health;

	UPROPERTY(EditAnywhere, Category = "COA")
		float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "COA")
		float HealingRate;

	UPROPERTY(EditAnywhere, Category = "COA")
		float WalkSpeed;

	UPROPERTY(EditAnywhere, Category = "COA")
		float RunSpeed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
