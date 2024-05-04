// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicEnemy.h"

// Sets default values
ABasicEnemy::ABasicEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Health = 40;
	IndI = 0;
	ValueForKilling = 3;
	MovementSpeed = 1;
}

// Called when the game starts or when spawned
void ABasicEnemy::BeginPlay()
{
	AAbstractEnemy::BeginPlay();
	Health = 25;
	IndI = 0;
	ValueForKilling = 3;
	MovementSpeed = 1;
	
}

// Called every frame
void ABasicEnemy::Tick(float DeltaTime)
{
	AAbstractEnemy::Tick(DeltaTime);

}

