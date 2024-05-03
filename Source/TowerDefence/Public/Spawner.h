// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TimerManager.h"
#include "BasicEnemy.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class TOWERDEFENCE_API ASpawner : public AActor
{
	GENERATED_BODY()

	FTimerHandle timer;

	FTimerHandle timerWave;

	void newWave();
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

	UFUNCTION(BlueprintCallable, Category = "SpawnPoint")
	void SpawnEnemies();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnPoint")
	int32 EnemiesCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UTimer")
	double SpawnTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnPoint")
	TSubclassOf<AActor> EnemyActor;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
