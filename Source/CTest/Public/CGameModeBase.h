// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CGameModeBase.generated.h"

UCLASS()
class CTEST_API ACGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	float TimeElapsed = 0.0f;
	int Highscore = 0;

public:
	//// Stores the player location for saving
	FVector LastPlayerSavedLocation = FVector::ZeroVector;


	//// Run On the Start Of the Level
    virtual void BeginPlay() override;

	//// Run Evey Tick of a Second
	virtual void Tick(float DeltaSeconds) override;

	//// Ends the Game When Run
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	void ReportScore(int newScore);


	// Returns a copy of the player last saved location
	FVector GetLastSavedPlayerLocation();

};
