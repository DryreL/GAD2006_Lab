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

	UPROPERTY(EditAnywhere, Category = "COA")
		float Stamina;

	UPROPERTY(EditAnywhere, Category = "COA")
		float MaxStamina;

	UPROPERTY(EditAnywhere, Category = "COA")
		float StaminaGainRate;

	UPROPERTY(EditAnywhere, Category = "COA")
		float StaminaDrainRate;

	UPROPERTY(EditAnywhere, Category = "COA")
		bool bStaminaDrained;

	UPROPERTY(EditAnywhere, Category = "COA")
		bool bRunning;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COA")
		bool bAttacking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COA")
		bool bDamaged;

	UPROPERTY(EditAnywhere, Category = "COA")
		float MovementScale;

	UFUNCTION(BlueprintImplementableEvent)
		float ModifyDamage(float IncomingDamage);

	UFUNCTION(BlueprintImplementableEvent)
		void PlayerDied();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

private:
};
