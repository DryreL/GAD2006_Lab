// Copyright 2022 © Gökdeniz Çetin


#include "COAGameInstance.h"

/*
void UCOAGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance:Init"));
}
*/

void UCOAGameInstance::Host()
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Green, TEXT("Hosting"));

	GWorld->ServerTravel("/Game/Blueprint/Multiplayer/MAP_Multiplayer?listen");
}

void UCOAGameInstance::Join(FString& Address)
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Green, FString::Printf(TEXT("Joining %s"),*Address));

	GWorld->GetFirstPlayerController()->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}