#pragma once

#define SMALL_WAVE 10
#define MEDIUM_WAVE 20
#define HUGE_WAVE 30
#define BASIC_ENEMY_MEDIUM_WAVE_CONST 8
#define BASIC_ENEMY_HUGE_WAVE_CONST 9
#define STRONG_ENEMY_HUGE_WAVE_CONST 19
#define STRONG_ENEMY_FIRST_HUGE_WAVE_CONST 40
#define WAVE_CONST_5 5
#define WAVE_CONST_7 7
#define WAVE_NOT_FOR_FIRST 4
#define FIRST_WAVE_FOR_SECOND 15
#define HEALTH_ENHANCER 1.065f

#include <type_traits>
#include "CoreMinimal.h"
#include "TimerManager.h"
#include "BasicEnemy.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"



UENUM(BlueprintType)
enum Way
{
	first UMETA(DisplayName = "first"),
	second UMETA(DisplayName = "second"),
	third UMETA(DisplayName = "third"),
	fourt UMETA(DisplayName = "fourth")
};

UCLASS()
class TOWERDEFENCE_API ASpawner : public AActor
{
	GENERATED_BODY()

	FTimerHandle timer;

	FTimerHandle timerWave;

	FVector thisPosition;

	FRotator thisRotation;

	TArray<FVector> firstLevelFirstWayControlPoints;
	TArray<FVector> firstLevelFirstWayRotatePoints;

	TArray<FVector> firstLevelSecondWayControlPoints;
	TArray<FVector> firstLevelSecondWayRotatePoints;

	void newWave();
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

	UFUNCTION(BlueprintCallable, Category = "Spawn")
	void SpawnEnemies();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	int32 EnemiesCount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "WaveCount")
	int32 WaveCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Way")
	TEnumAsByte<Way> ThisWay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer")
	double SpawnTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnPoint")
	TSubclassOf<AActor> EnemyActor;

	UFUNCTION(BlueprintImplementableEvent, Category = "Spawn")
	void NewWave();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};