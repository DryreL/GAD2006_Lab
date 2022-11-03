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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "COA")
	UCameraComponent* mCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "COA")
	USpringArmComponent* mSpringArm;

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

private:
	void MoveForward(float value);
	void MoveRight(float value);
	void RunPressed();
	void RunReleased();
	void UpdateMovementParams();
};
