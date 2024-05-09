// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#ifndef WORLD_FRAME_SPEED
#define WORLD_FRAME_SPEED 1.f / 60.f
#endif //WORLD_FRAME_SPEED
#define MAP_WIDTH 1792
#define MAP_HEIGHT 960

#include "CoreMinimal.h"
#include "BasicEnemy.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "AbstractBullet.generated.h"

UCLASS()
class TOWERDEFENCE_API AAbstractBullet : public AActor
{
	GENERATED_BODY()

	bool rotationIsSet;

	FTimerHandle forceTimer;
	
public:	
	// Sets default values for this actor's properties
	AAbstractBullet();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Speed")
	double forceSpeed;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Indexes")
	TArray<AActor*> allEnemies;

	void force();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	AActor* Enemy;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
	int32 Damage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
	int32 LevelOfDamage;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
