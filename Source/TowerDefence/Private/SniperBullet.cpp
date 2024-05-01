// Fill out your copyright notice in the Description page of Project Settings.


#include "SniperBullet.h"

// Sets default values
ASniperBullet::ASniperBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASniperBullet::BeginPlay()
{
	Super::BeginPlay();
	forceSpeed = 30;
	damage = 80;
	
}

// Called every frame
void ASniperBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

