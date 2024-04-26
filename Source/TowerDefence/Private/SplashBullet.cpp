// Fill out your copyright notice in the Description page of Project Settings.


#include "SplashBullet.h"

// Sets default values
ASplashBullet::ASplashBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASplashBullet::BeginPlay()
{
	forceSpeed = 0.5;
	damage = 10;
	Super::BeginPlay();
	
}

// Called every frame
void ASplashBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

