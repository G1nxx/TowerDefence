// Fill out your copyright notice in the Description page of Project Settings.


#include "AbstractBullet.h"

// Called when the game starts or when spawned
void AAbstractBullet::BeginPlay()
{
	Super::BeginPlay();
	forceSpeed = 5;
	rotationIsSet = 0;
	Damage = 20;

	GetWorldTimerManager().SetTimer(forceTimer, this, &AAbstractBullet::force, WORLD_FRAME_SPEED, true);
}

// Called every frame
void AAbstractBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

AAbstractBullet::AAbstractBullet()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAbstractBullet::force()
{
	if (Enemy && !Enemy->IsActorBeingDestroyed())
	{
		FVector actorLocation = Enemy->GetActorLocation();
		if (actorLocation.X >= 0 && actorLocation.Y >= 0 && actorLocation.Y <= MAP_HEIGHT && actorLocation.X <= MAP_WIDTH)
		{
			FVector enemyLocation = Enemy->GetActorLocation();
			FVector thisLocation = this->GetActorLocation();

			FVector vector = enemyLocation - thisLocation;
			FRotator ThisRotation = this->GetActorRotation();
			FRotator TempRotation = ThisRotation;
			TempRotation.Yaw = UKismetMathLibrary::RInterpTo(ThisRotation, UKismetMathLibrary::FindLookAtRotation(thisLocation, enemyLocation), UGameplayStatics::GetWorldDeltaSeconds(GetWorld()), 0.01).Yaw;

			vector.Normalize();
			this->SetActorRotation(TempRotation);
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