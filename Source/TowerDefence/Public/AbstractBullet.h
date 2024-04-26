// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicEnemy.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "AbstractBullet.generated.h"

UCLASS()
class TOWERDEFENCE_API AAbstractBullet : public AActor
{
	GENERATED_BODY()

	bool rotationIsSet;
	
public:	
	// Sets default values for this actor's properties
	AAbstractBullet();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Speed")
	double forceSpeed;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Indexes")
	TArray<AActor*> AllEnemies;

	void force();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	AActor* enemy;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
	int32 damage;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
