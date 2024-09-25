// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "CSaveGame.generated.h"

UCLASS()
class CTEST_API UCSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	int Highscore = 0;

	// Add A baribale for storing the players last Pos
	UPROPERTY()
	FVector LastPlayerLocation = FVector::ZeroVector;
	
	// Map of Transform
	UPROPERTY()
	TMap<FString, FTransform> SaveTransformByName;

};
