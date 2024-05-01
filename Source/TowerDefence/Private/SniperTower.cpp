// Fill out your copyright notice in the Description page of Project Settings.


#include "SniperTower.h"

// Sets default values
ASniperTower::ASniperTower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASniperTower::BeginPlay()
{
	Super::BeginPlay();
	RotationSpeed = ROTATION_CONST * 7;
	LevelOfTower = 1;
	ShootingSpeed = 10;
	
}

// Called every frame
void ASniperTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

