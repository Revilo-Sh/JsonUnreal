// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpActor.h"

#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h" // The Player Ref

// Sets default values
APickUpActor::APickUpActor() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Create a default instance of our pickup mesh
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));

	// Make it that the Pick Up Mesh Can be Overlap By other Actors
	PickupMesh->SetCollisionProfileName(FName(TEXT("OverlapAll")));

	// Set the PickupMesh as the root component
	RootComponent = PickupMesh;

}

// Called when the game starts or when spawned
void APickUpActor::BeginPlay() {
	Super::BeginPlay();
	
}

void APickUpActor::NotifyActorBeginOverlap(AActor* OtherActor) {

	Super::NotifyActorBeginOverlap(OtherActor);
	
	// Cast to the Player
	ACharacter* player = Cast<ACharacter>(OtherActor);

	// Check to See If it is the Player
	if (IsValid(player)) {
		Destroy();
	}
}

// Called every frame
void APickUpActor::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	// This was "Get Game Time in Seconds" in Blueprints
	float GameSeconds = GetWorld()->GetTimeSeconds();

	float AngleInRadians = FMath::DegreesToRadians(GameSeconds) * RotationSpeed; // The Speed Of the Spin based On a Number

	// Rotates On Axis and Angle in Blueprints
	FRotator NewRoataion = FRotator(FQuat(FVector(0.0f, 0.0f, 1.0f), AngleInRadians));

	SetActorRotation(NewRoataion);

}

