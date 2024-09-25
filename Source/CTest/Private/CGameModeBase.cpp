// Fill out your copyright notice in the Description page of Project Settings.


#include "CGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "CPlayerCharacter.h"
#include "CSaveGame.h"
#include "EngineUtils.h"
#include "CGameSaveComponent.h"

void ACGameModeBase::BeginPlay() {
	Super::BeginPlay();

	USaveGame* loadsave = UGameplayStatics::LoadGameFromSlot(TEXT("SINGLEPLAYER"), 0);
	UCSaveGame* mySave = Cast<UCSaveGame>(loadsave);

	if (IsValid(mySave)) {
		// Copy HighScore
		Highscore = mySave->Highscore;

		if (!mySave->SaveTransformByName.IsEmpty())
		{
			for (TObjectIterator<UCGameSaveComponent> savedTransforms; savedTransforms; ++savedTransforms)
			{
				// Don't load if object is not from a game/PIE world
				if (!IsValid(*savedTransforms) || savedTransforms->GetWorld() != GetWorld()) { continue; }
				EWorldType::Type componentWorldType = (*savedTransforms)->GetWorld()->WorldType;
				if (!(componentWorldType == EWorldType::PIE || componentWorldType == EWorldType::Game)) { continue; }

				AActor* saveOwner = (*savedTransforms)->GetOwner();
				FString ownerName = saveOwner->GetName();
				FTransform* savedTransform = mySave->SaveTransformByName.Find(ownerName);
				if (savedTransform != nullptr)
				{
					(*savedTransforms)->LoadTransform(mySave->SaveTransformByName[saveOwner->GetName()]);
				}
			}
		}

		// Set Player To the Last Save Player Pos
		LastPlayerSavedLocation = mySave->LastPlayerLocation;
	}


}

void ACGameModeBase::Tick(float DeltaSeconds) {
	
}

void ACGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	// Create Copy Of Save Data
	USaveGame* newSave = UGameplayStatics::CreateSaveGameObject(UCSaveGame::StaticClass());

	UCSaveGame* mySave = Cast<UCSaveGame>(newSave);
	if (IsValid(mySave)) {
		// Make The Best Hight Score To the Save data
		mySave->Highscore = Highscore;

		 //Saving the last Pos of the Player

		for (TActorIterator<ACPlayerCharacter> player(GetWorld()); player; ++player)
		{
			// Skip Invalid players
			if (!IsValid(*player)) { continue; }
			mySave->LastPlayerLocation = player->GetActorLocation();
			break;
		}

		for (TObjectIterator<UCGameSaveComponent> savedTransforms; savedTransforms; ++savedTransforms)
		{
			// Skip invalid objects
			if (!IsValid(*savedTransforms) || savedTransforms->GetWorld() != GetWorld()) { continue; }
			// Don't load if object is not from a game world
			AActor* saveOwner = savedTransforms->GetOwner();
			EWorldType::Type ownerWorldType = saveOwner->GetWorld()->WorldType;
			if (!(ownerWorldType == EWorldType::PIE || ownerWorldType == EWorldType::Game)) { continue; }

			// Associate name with transform information
			FString ownerName = saveOwner->GetName();
			FTransform newSaveTransform;
			savedTransforms->SaveTransform(newSaveTransform);

			mySave->SaveTransformByName.FindOrAdd(saveOwner->GetName(), newSaveTransform);
		}
		// Save Slot To Where Single Player is the name and 0 is the slot index
		UGameplayStatics::SaveGameToSlot(mySave, TEXT("SINGLEPLAYER"), 0);
	}
	// Class the Endplay Super Class
	Super::EndPlay(EndPlayReason);
}

void ACGameModeBase::ReportScore(int newScore) {
	if (newScore > Highscore) {
		Highscore = newScore;
	}
}

FVector ACGameModeBase::GetLastSavedPlayerLocation() {
	return LastPlayerSavedLocation;
}
