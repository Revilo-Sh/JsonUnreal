// Fill out your copyright notice in the Description page of Project Settings.


#include "CGameSaveComponent.h"

// Sets default values for this component's properties
UCGameSaveComponent::UCGameSaveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

bool UCGameSaveComponent::SaveTransform(FTransform& saveTransform) {
	AActor* owner = GetOwner();
	saveTransform = owner->GetActorTransform();

	return true;
}

void UCGameSaveComponent::LoadTransform(const FTransform& loadTransform) {
	AActor* owner = GetOwner();
	owner->SetActorTransform(loadTransform);
}


// Called when the game starts
void UCGameSaveComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCGameSaveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

