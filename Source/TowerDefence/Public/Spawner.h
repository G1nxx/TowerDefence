#pragma once

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

	FVector ThisPosition;

	FRotator ThisRotation;

	TArray<FVector> FirstLevelFirstWayControlPoints;
	TArray<FVector> FirstLevelFirstWayRotatePoints;

	TArray<FVector> FirstLevelSecondWayControlPoints;
	TArray<FVector> FirstLevelSecondWayRotatePoints;

	void newWave();
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

	UFUNCTION(BlueprintCallable, Category = "SpawnPoint")
	void SpawnEnemies();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnPoint")
	int32 EnemiesCount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "WaveCount")
	int32 waveCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Way")
	TEnumAsByte<Way> thisWay;

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