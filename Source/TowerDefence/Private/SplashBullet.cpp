// Fill out your copyright notice in the Description page of Project Settings.


#include "SplashBullet.h"

// Sets default values
ASplashBullet::ASplashBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	forceSpeed = 2;
	Damage = 10;

}

// Called when the game starts or when spawned
void ASplashBullet::BeginPlay()
{
	Super::BeginPlay();
	forceSpeed = 3;
	Damage = 25;
	
}

// Called every frame
void ASplashBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

