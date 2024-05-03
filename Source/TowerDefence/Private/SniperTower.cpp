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
	RotationSpeed = ROTATION_CONST / 2;
	LevelOfTower = 1;
	CostOfTower = 80;
	CostOfUpgrading = 50;
	ShootingSpeed = 3;
	
}

// Called every frame
void ASniperTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

