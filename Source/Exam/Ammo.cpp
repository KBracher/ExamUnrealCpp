// Fill out your copyright notice in the Description page of Project Settings.


#include "Ammo.h"
#include <Exam/ExamCharacter.h>
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

// Sets default values
AAmmo::AAmmo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyCharacter = Cast<AExamCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

// Called when the game starts or when spawned
void AAmmo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAmmo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MyCharacter) {
		float Dirx = MyCharacter->GetActorLocation().X - this->GetActorLocation().X;
		float DirY = MyCharacter->GetActorLocation().Y - this->GetActorLocation().Y;

		FVector dir = FVector(Dirx, DirY, 0.0f);

		if (abs(dir.X) + abs(dir.Y) <= 40) {
			MyCharacter->nbBalle += nbAmmo;
			Spawner->isAmmo = false;
			this->Destroy();
		}
	}
}

