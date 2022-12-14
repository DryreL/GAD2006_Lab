// Copyright 2022 © Gökdeniz Çetin

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "COACharAnimInstance.h"
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

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "COA")
		float Health;

	UPROPERTY(EditAnywhere, Category = "COA")
		float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "COA")
		float HealingRate;

	UPROPERTY(EditAnywhere, Category = "COA")
		float WalkSpeed;

	UPROPERTY(EditAnywhere, Category = "COA")
		bool bRunning;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COA")
		float AttackStartupTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "COA")
		ECharAnimState AnimState;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "COA")
		void ChangeAnimState(ECharAnimState NewState);

	UFUNCTION(BlueprintImplementableEvent, Category = "COA")
		float ModifyDamage(float IncomingDamage);

	UFUNCTION(BlueprintImplementableEvent, Category = "COA")
		void OnCharacterDied();

	UFUNCTION(BlueprintImplementableEvent, Category = "COA")
		void OnAttack();

	UFUNCTION(BlueprintPure, Category = "COA")
		float GetHealth() { return  Health; };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	virtual void GetLifetimeReplicatedProps(TArray < class FLifetimeProperty >& OutLifetimeProps) const override;

private:
	FTimerHandle AttackTimer;
};
