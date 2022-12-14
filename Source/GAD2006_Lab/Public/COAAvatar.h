// Copyright 2022 © Gökdeniz Çetin

#pragma once

#include "CoreMinimal.h"
#include "COABaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "COAAvatar.generated.h"

UCLASS()
class GAD2006_LAB_API ACOAAvatar : public ACOABaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACOAAvatar();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "COA")
	UCameraComponent* mCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "COA")
	USpringArmComponent* mSpringArm;

	UPROPERTY(EditAnywhere, Category = "COA")
		float RunSpeed;

	UPROPERTY(EditAnywhere, Replicated, BlueprintReadOnly, Category = "COA")
		float Stamina;

	UPROPERTY(EditAnywhere, Category = "COA")
		float MaxStamina;

	UPROPERTY(EditAnywhere, ReplicatedUsing = OnRep_MaxWalkSpeed, BlueprintReadOnly, Category = "COA")
		float MaxWalkSpeed;

	UPROPERTY(EditAnywhere, Category = "COA")
		float StaminaGainRate;

	UPROPERTY(EditAnywhere, Category = "COA")
		float StaminaDrainRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "COA")
		bool bStaminaDrained;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COA")
		float MovementScale;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void GetLifetimeReplicatedProps(TArray < class FLifetimeProperty >& OutLifetimeProps) const override;

private:
	void MoveForward(float value);
	void MoveRight(float value);
	void RunPressed();
	void RunReleased();
	void UpdateMovementParams();

	UFUNCTION(Server, Unreliable)
		void ChangeRunStateServer(bool pressed);

	UFUNCTION()
		void OnRep_MaxWalkSpeed();
};
