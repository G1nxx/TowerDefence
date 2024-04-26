// Fill out your copyright notice in the Description page of Project Settings.


#include "AbstractBullet.h"

// Called when the game starts or when spawned
void AAbstractBullet::BeginPlay()
{
	Super::BeginPlay();
	forceSpeed = 5;
	rotationIsSet = 0;
	damage = 20;
}

// Called every frame
void AAbstractBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	force();
}

AAbstractBullet::AAbstractBullet()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAbstractBullet::force()
{
	if (enemy && !enemy->IsActorBeingDestroyed())
	{
		FVector actorLocation = enemy->GetActorLocation();
		if (actorLocation.X > 0 && actorLocation.Y > 0)
		{
			enemy->GetActorLocation();
			FVector vector = enemy->GetActorLocation() - this->GetActorLocation();
			vector.Normalize();
			this->SetActorLocation(this->GetActorLocation() + vector * forceSpeed);
		}
		else
		{
			this->Destroy();
		}
	}
	else
	{
		this->Destroy();
	}
}