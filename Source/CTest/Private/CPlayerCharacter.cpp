// Fill out your copyright notice in the Description page of Project Settings.


#include "CPlayerCharacter.h"
#include "CGameModeBase.h"

// Sets default values
ACPlayerCharacter::ACPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	ACGameModeBase* gameMode = GetWorld()->GetAuthGameMode<ACGameModeBase>();
	if (IsValid(gameMode))
	{
		bool isDefaultLocation = gameMode->GetLastSavedPlayerLocation() == FVector::ZeroVector;
		if (!isDefaultLocation) {
			TeleportTo(gameMode->GetLastSavedPlayerLocation(), GetActorRotation());
		}
	}
}

// Called every frame
void ACPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

