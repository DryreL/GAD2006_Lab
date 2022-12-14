// Copyright 2022 © Gökdeniz Çetin

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "COACharAnimInstance.generated.h"

UENUM(BlueprintType)
enum class ECharAnimState : uint8
{
	CAS_UNKNOWN UMETA(DisplayName = "Unknown"),
	CAS_IDLE UMETA(DisplayName = "Idle"),
	CAS_RUN UMETA(DisplayName = "Run"),
	CAS_ATTACK UMETA(DisplayName = "Attack"),
	CAS_DAMAGE UMETA(DisplayName = "Damage"),
	CAS_DEATH UMETA(DisplayName = "Death"),
};

/**
 * 
 */
UCLASS()
class GAD2006_LAB_API UCOACharAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "COA")
		ECharAnimState AnimState;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "COA")
		void ChangeAnimState(ECharAnimState newstate);
};
