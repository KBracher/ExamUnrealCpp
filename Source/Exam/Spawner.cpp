// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"
#include <Exam/Ammo.h>

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpawner::Spawn()
{	
	FVector Location;
	FRotator Rotation;
	FActorSpawnParameters SpawnParams;

	Location = FVector(this->GetActorLocation().X, this->GetActorLocation().Y, this->GetActorLocation().Z + 60);
	Rotation = FRotator(0, 0, 0);
	AActor* actor = GetWorld()->SpawnActor<AActor>(ActorToSpawn, Location, Rotation, SpawnParams);
	AAmmo* ammo = Cast<AAmmo>(actor);
	ammo->Spawner = this;
}
	
	

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!isAmmo) {
		isAmmo = true;
		FTimerHandle    handle;
		GetWorldTimerManager().SetTimer(handle, [this]() {
			Spawn();
			}, TimeBeforeRespawn, false);
		
	}


	
}

