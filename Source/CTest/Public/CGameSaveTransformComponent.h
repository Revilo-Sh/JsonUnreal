// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CGameSaveTransformComponent.generated.h"

UCLASS()
class CTEST_API ACGameSaveTransformComponent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACGameSaveTransformComponent();
	bool SaveTransform(FTransform &saveTransform);
	void LoadTransform(const FTransform &loadTransform);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
