// Fill out your copyright notice in the Description page of Project Settings.


#include "CGameSaveTransformComponent.h"


// Sets default values
ACGameSaveTransformComponent::ACGameSaveTransformComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

bool ACGameSaveTransformComponent::SaveTransform(FTransform& saveTransform)
{
	AActor* owner = GetOwner();
	saveTransform = owner->GetActorTransform();

	return true;
}

void ACGameSaveTransformComponent::LoadTransform(const FTransform& loadTransform)
{
	AActor* owner = GetOwner();
	owner->SetActorTransform(loadTransform);
}



// Called when the game starts or when spawned
void ACGameSaveTransformComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACGameSaveTransformComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

