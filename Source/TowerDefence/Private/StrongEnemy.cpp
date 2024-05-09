// Fill out your copyright notice in the Description page of Project Settings.


#include "StrongEnemy.h"

// Sets default values
AStrongEnemy::AStrongEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Health = 100;
	indI = 0;
	ValueForKilling = 5;
	MovementSpeed = 0.75;
}

// Called when the game starts or when spawned
void AStrongEnemy::BeginPlay()
{
	Super::BeginPlay();
	Health = 60;
	indI = 0;
	ValueForKilling = 5;
	MovementSpeed = 0.75;
	
}

// Called every frame
void AStrongEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

