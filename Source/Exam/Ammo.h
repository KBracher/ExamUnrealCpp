// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Exam/ExamCharacter.h>
#include <Exam/Spawner.h>
#include "Ammo.generated.h"

UCLASS()
class EXAM_API AAmmo : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = properties)
	float nbAmmo;
	
public:	
	// Sets default values for this actor's properties
	AAmmo();
	AExamCharacter* MyCharacter;
	ASpawner* Spawner;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
