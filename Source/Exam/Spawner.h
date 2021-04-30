// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class EXAM_API ASpawner : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = Spawning)
	TSubclassOf<AActor> ActorToSpawn;

	UPROPERTY(EditDefaultsOnly, Category = Spawning)
	float TimeBeforeRespawn;

public:	
	// Sets default values for this actor's properties
	ASpawner();
	bool isAmmo = false;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Spawn();



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
