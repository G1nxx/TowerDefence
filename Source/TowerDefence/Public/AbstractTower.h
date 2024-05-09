#pragma once

#ifndef WORLD_FRAME_SPEED
#define WORLD_FRAME_SPEED 1.f / 60.f
#endif //WORLD_FRAME_SPEED

#define ROTATION_CONST 57.2957795131f
#define ROTATION_ANGLE_RIGHT 0.025l
#define ROTATION_ANGLE_LEFT -0.025l

#define ROTATION_UPGRADE_CONST 1.04f
#define SHOOTING_UPGRADE_CONST 1.05f
#define UPGRADE_COST_CONST 1.67f

#include "CoreMinimal.h"
#include "BasicEnemy.h"
#include "AbstractBullet.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "AbstractTower.generated.h"

UCLASS()
class TOWERDEFENCE_API AAbstractTower : public AActor
{
	GENERATED_BODY()

	bool isShooting;

	FRotator thisRotation;

	FVector thisLocation;

	FRotator tempRotation;

	FTimerHandle timer;

	FTimerHandle rotateTimer;
	
public:	
	// Sets default values for this actor's properties
	AAbstractTower();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	double RotationSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Shooting")
	double ShootingSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Upgrading")
	int32 LevelOfTower;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Upgrading")
	int32 CostOfUpgrading;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Upgrading")
	int32 CostOfTower;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Indexes")
	ABasicEnemy* EnemyBase;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Indexes")
	TArray<AActor*> AllEnemies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnPoint")
	TSubclassOf<AActor> Bullet;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Clickked")
	void ClickedOnTower();

	UFUNCTION(BlueprintCallable, Category = "Upgrade")
	void UpdateLevel();

	void rotateRight();

	void rotateLeft();

	void rotateObject();

	void shoot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
