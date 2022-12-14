// Copyright 2022 © Gökdeniz Çetin

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "COAGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GAD2006_LAB_API UCOAGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(FString& Address);

};