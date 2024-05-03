// Fill out your copyright notice in the Description page of Project Settings.


#include "SplashTower.h"

// Sets default values
ASplashTower::ASplashTower() 
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASplashTower::BeginPlay()
{
	Super::BeginPlay();
	RotationSpeed = ROTATION_CONST * 2;
	LevelOfTower = 1;
	CostOfTower = 60;
	ShootingSpeed = 1;
	
}

// Called every frame
void ASplashTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

