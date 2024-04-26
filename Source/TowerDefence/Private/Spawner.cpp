// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"

void ASpawner::newWave()
{
	EnemiesCount = 30;

	GetWorldTimerManager().SetTimer(timer, this, &ASpawner::SpawnEnemies, 10, false);
}

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASpawner::SpawnEnemies()
{   
	if (EnemiesCount--) {
		GetWorld()->SpawnActor<AActor>(EnemiesActor, this->GetActorTransform());
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Enemy spawned"));
		GetWorldTimerManager().SetTimer(timer, this, &ASpawner::SpawnEnemies, SpawnTimer, false);
	}
	//UE_LOG(LogTemp, Warning, TEXT(""));
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(timer, this, &ASpawner::SpawnEnemies, SpawnTimer, false);

	GetWorldTimerManager().SetTimer(timerWave, this, &ASpawner::SpawnEnemies, 10, false);

}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

