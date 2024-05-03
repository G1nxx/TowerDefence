// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicBullet.h"

// Sets default values
ABasicBullet::ABasicBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	forceSpeed = 5;
	damage = 15;
}

// Called when the game starts or when spawned
void ABasicBullet::BeginPlay()
{
	Super::BeginPlay();
	forceSpeed = 5;
	damage = 15;
	
}

// Called every frame
void ABasicBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

