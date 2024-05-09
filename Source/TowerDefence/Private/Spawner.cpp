// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"

void ASpawner::newWave()
{
	if ( ThisWay == first)
	{
		if (WaveCount % BASIC_ENEMY_MEDIUM_WAVE_CONST == 0 && ThisWay % (BASIC_ENEMY_MEDIUM_WAVE_CONST * 3) != 0) { EnemiesCount = MEDIUM_WAVE; }
		else if (WaveCount % BASIC_ENEMY_HUGE_WAVE_CONST == 0) { EnemiesCount = HUGE_WAVE; }
		else { EnemiesCount = SMALL_WAVE; }
	}
	else if (ThisWay == second)
	{
		if (WaveCount % STRONG_ENEMY_HUGE_WAVE_CONST == 0 && WaveCount > STRONG_ENEMY_FIRST_HUGE_WAVE_CONST) { EnemiesCount = (HUGE_WAVE + MEDIUM_WAVE) / 2; }
		else { EnemiesCount = SMALL_WAVE; }
	}
	GetWorldTimerManager().SetTimer(timer, this, &ASpawner::SpawnEnemies, SpawnTimer, false);
	GetWorldTimerManager().SetTimer(timerWave, this, &ASpawner::newWave, 15, false);

	++WaveCount;
	NewWave();
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
		switch (ThisWay)
		{
		case first:
			if (WaveCount % WAVE_CONST_5 != 0 || WaveCount % WAVE_CONST_7 != 0 || WaveCount % WAVE_NOT_FOR_FIRST == 0)
			{
				AActor* tempEnemy = GetWorld()->SpawnActor<AActor>(EnemyActor, this->GetActorTransform());
				AAbstractEnemy* enemy = Cast<AAbstractEnemy>(tempEnemy);
				enemy->Health *= std::powl(HEALTH_ENHANCER, WaveCount);
				enemy->controlPoints = this->firstLevelFirstWayControlPoints;
				enemy->rotatePoints = this->firstLevelFirstWayRotatePoints;
				enemy->setIsMoving(true);
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Enemy Spawned First"));
			}
			else
			{
				EnemiesCount = 0;
			}
			break;
		case second:
			if ((WaveCount % WAVE_CONST_5 == 0 || WaveCount % WAVE_CONST_7 == 0) && WaveCount > FIRST_WAVE_FOR_SECOND)
			{
				AActor* tempEnemy = GetWorld()->SpawnActor<AActor>(EnemyActor, this->GetActorTransform());
				AAbstractEnemy* enemy = Cast<AAbstractEnemy>(tempEnemy);
				enemy->Health *= std::powl(HEALTH_ENHANCER, WaveCount);
				enemy->controlPoints = this->firstLevelSecondWayControlPoints;
				enemy->rotatePoints = this->firstLevelSecondWayRotatePoints;
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

	WaveCount = 1;

	thisPosition = this->GetActorLocation();
	thisRotation = this->GetActorRotation();
	firstLevelFirstWayControlPoints.Add(FVector(thisPosition.X, thisPosition.Y + 21 * SIZE_OF_TITLE, thisPosition.Z));
	firstLevelFirstWayControlPoints.Add(FVector(thisPosition.X + 39 * SIZE_OF_TITLE, thisPosition.Y + 22 * SIZE_OF_TITLE, thisPosition.Z));
	firstLevelFirstWayControlPoints.Add(FVector(thisPosition.X + 40 * SIZE_OF_TITLE, thisPosition.Y + 7 * SIZE_OF_TITLE, thisPosition.Z));
	firstLevelFirstWayControlPoints.Add(FVector(thisPosition.X + 13 * SIZE_OF_TITLE, thisPosition.Y + 6 * SIZE_OF_TITLE, thisPosition.Z));
	firstLevelFirstWayControlPoints.Add(FVector(thisPosition.X + 12 * SIZE_OF_TITLE, thisPosition.Y + 16 * SIZE_OF_TITLE, thisPosition.Z));

	firstLevelFirstWayRotatePoints.Add(FVector(thisPosition.X + SIZE_OF_TITLE, thisPosition.Y + 21 * SIZE_OF_TITLE, thisPosition.Z));
	firstLevelFirstWayRotatePoints.Add(FVector(thisPosition.X + 39 * SIZE_OF_TITLE, thisPosition.Y + 21 * SIZE_OF_TITLE, thisPosition.Z));
	firstLevelFirstWayRotatePoints.Add(FVector(thisPosition.X + 39 * SIZE_OF_TITLE, thisPosition.Y + 7 * SIZE_OF_TITLE, thisPosition.Z));
	firstLevelFirstWayRotatePoints.Add(FVector(thisPosition.X + 13 * SIZE_OF_TITLE, thisPosition.Y + 7 * SIZE_OF_TITLE, thisPosition.Z));
	firstLevelFirstWayRotatePoints.Add(FVector(thisPosition.X + 12 * SIZE_OF_TITLE, thisPosition.Y + 16 * SIZE_OF_TITLE, thisPosition.Z));


	firstLevelSecondWayControlPoints.Add(FVector(thisPosition.X, thisPosition.Y - 25 * SIZE_OF_TITLE, thisPosition.Z));
	firstLevelSecondWayControlPoints.Add(FVector(thisPosition.X - 11 * SIZE_OF_TITLE, thisPosition.Y - 26 * SIZE_OF_TITLE, thisPosition.Z));
	firstLevelSecondWayControlPoints.Add(FVector(thisPosition.X - 12 * SIZE_OF_TITLE, thisPosition.Y - 16 * SIZE_OF_TITLE, thisPosition.Z));

	firstLevelSecondWayRotatePoints.Add(FVector(thisPosition.X - SIZE_OF_TITLE, thisPosition.Y - 25 * SIZE_OF_TITLE, thisPosition.Z));
	firstLevelSecondWayRotatePoints.Add(FVector(thisPosition.X - 11 * SIZE_OF_TITLE, thisPosition.Y - 25 * SIZE_OF_TITLE, thisPosition.Z));
	firstLevelSecondWayRotatePoints.Add(FVector(thisPosition.X - 12 * SIZE_OF_TITLE, thisPosition.Y - 16 * SIZE_OF_TITLE, thisPosition.Z));

	GetWorldTimerManager().SetTimer(timerWave, this, &ASpawner::newWave, 10, false);
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

