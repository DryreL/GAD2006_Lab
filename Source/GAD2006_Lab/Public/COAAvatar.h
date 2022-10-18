// Copyright 2022 © Gökdeniz Çetin

#pragma once

#include "CoreMinimal.h"
#include "COABaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "COAAvatar.generated.h"

UCLASS()
class GAD2006_LAB_API ACOAAvatar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACOAAvatar();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "COA")
	UCameraComponent* mCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "COA")
	USpringArmComponent* mSpringArm;

	/*
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "COA")
	float WalkSpeed = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "COA")
	float RunSpeed = 300.0f;
	*/

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float value);
	void MoveRight(float value);
	void RunPressed();
	void RunReleased();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
