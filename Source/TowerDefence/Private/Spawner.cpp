// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"

void ASpawner::newWave()
{

	EnemiesCount = 10;
	GetWorldTimerManager().SetTimer(timer, this, &ASpawner::SpawnEnemies, SpawnTimer, false);
	GetWorldTimerManager().SetTimer(timerWave, this, &ASpawner::newWave, 10, false);

	++waveCount;
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
		switch (thisWay)
		{
		case first:
			if (waveCount % 5 != 0 || waveCount % 7 != 0 || waveCount % 4 == 0)
			{
				AActor* tempEnemy = GetWorld()->SpawnActor<AActor>(EnemyActor, this->GetActorTransform());
				AAbstractEnemy* enemy = Cast<AAbstractEnemy>(tempEnemy);
				enemy->Health *= std::powl(1.02, waveCount);
				enemy->ControlPoints = this->FirstLevelFirstWayControlPoints;
				enemy->RotatePoints = this->FirstLevelFirstWayRotatePoints;
				enemy->setIsMoving(true);
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Enemy Spawned First"));
			}
			else
			{
				EnemiesCount = 0;
			}
			break;
		case second:
			if (waveCount % 5 == 0 || waveCount % 7 == 0)
			{
				AActor* tempEnemy = GetWorld()->SpawnActor<AActor>(EnemyActor, this->GetActorTransform());
				AAbstractEnemy* enemy = Cast<AAbstractEnemy>(tempEnemy);
				enemy->Health *= std::powl(1.02, waveCount);
				enemy->ControlPoints = this->FirstLevelSecondWayControlPoints;
				enemy->RotatePoints = this->FirstLevelSecondWayRotatePoints;
				enemy->setIsMoving(true);
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Enemy Spawned Second"));
			}
			else
			{
				EnemiesCount = 0;
			}
			break;
		default:
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Default"));
			break;
		}


		GetWorldTimerManager().SetTimer(timer, this, &ASpawner::SpawnEnemies, SpawnTimer, false);
	}
	//UE_LOG(LogTemp, Warning, TEXT(""));
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();

	waveCount = 1;

	ThisPosition = this->GetActorLocation();
	ThisRotation = this->GetActorRotation();
	FirstLevelFirstWayControlPoints.Add(FVector(ThisPosition.X, ThisPosition.Y + 21 * SIZE_OF_TITLE, ThisPosition.Z));
	FirstLevelFirstWayControlPoints.Add(FVector(ThisPosition.X + 39 * SIZE_OF_TITLE, ThisPosition.Y + 22 * SIZE_OF_TITLE, ThisPosition.Z));
	FirstLevelFirstWayControlPoints.Add(FVector(ThisPosition.X + 40 * SIZE_OF_TITLE, ThisPosition.Y + 7 * SIZE_OF_TITLE, ThisPosition.Z));
	FirstLevelFirstWayControlPoints.Add(FVector(ThisPosition.X + 13 * SIZE_OF_TITLE, ThisPosition.Y + 6 * SIZE_OF_TITLE, ThisPosition.Z));
	FirstLevelFirstWayControlPoints.Add(FVector(ThisPosition.X + 12 * SIZE_OF_TITLE, ThisPosition.Y + 16 * SIZE_OF_TITLE, ThisPosition.Z));

	FirstLevelFirstWayRotatePoints.Add(FVector(ThisPosition.X + SIZE_OF_TITLE, ThisPosition.Y + 21 * SIZE_OF_TITLE, ThisPosition.Z));
	FirstLevelFirstWayRotatePoints.Add(FVector(ThisPosition.X + 39 * SIZE_OF_TITLE, ThisPosition.Y + 21 * SIZE_OF_TITLE, ThisPosition.Z));
	FirstLevelFirstWayRotatePoints.Add(FVector(ThisPosition.X + 39 * SIZE_OF_TITLE, ThisPosition.Y + 7 * SIZE_OF_TITLE, ThisPosition.Z));
	FirstLevelFirstWayRotatePoints.Add(FVector(ThisPosition.X + 13 * SIZE_OF_TITLE, ThisPosition.Y + 7 * SIZE_OF_TITLE, ThisPosition.Z));
	FirstLevelFirstWayRotatePoints.Add(FVector(ThisPosition.X + 12 * SIZE_OF_TITLE, ThisPosition.Y + 16 * SIZE_OF_TITLE, ThisPosition.Z));


	FirstLevelSecondWayControlPoints.Add(FVector(ThisPosition.X, ThisPosition.Y - 25 * SIZE_OF_TITLE, ThisPosition.Z));
	FirstLevelSecondWayControlPoints.Add(FVector(ThisPosition.X - 11 * SIZE_OF_TITLE, ThisPosition.Y - 26 * SIZE_OF_TITLE, ThisPosition.Z));
	FirstLevelSecondWayControlPoints.Add(FVector(ThisPosition.X - 12 * SIZE_OF_TITLE, ThisPosition.Y - 16 * SIZE_OF_TITLE, ThisPosition.Z));

	FirstLevelSecondWayRotatePoints.Add(FVector(ThisPosition.X - SIZE_OF_TITLE, ThisPosition.Y - 25 * SIZE_OF_TITLE, ThisPosition.Z));
	FirstLevelSecondWayRotatePoints.Add(FVector(ThisPosition.X - 11 * SIZE_OF_TITLE, ThisPosition.Y - 25 * SIZE_OF_TITLE, ThisPosition.Z));
	FirstLevelSecondWayRotatePoints.Add(FVector(ThisPosition.X - 12 * SIZE_OF_TITLE, ThisPosition.Y - 16 * SIZE_OF_TITLE, ThisPosition.Z));

	newWave();
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

