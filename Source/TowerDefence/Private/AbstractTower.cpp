// Fill out your copyright notice in the Description page of Project Settings.


#include "AbstractTower.h"

// Sets default values
AAbstractTower::AAbstractTower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAbstractTower::BeginPlay()
{
	thisRotation = this->GetActorRotation();
	thisLocation = this->GetActorLocation();
	ShootingSpeed = 0.4;
	RotationSpeed = 0;
	CostOfUpgrading = 20;
	LevelOfTower = 1;
	isShooting = false;


	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(timer, this, &AAbstractTower::shoot, ShootingSpeed, false); 
	GetWorldTimerManager().SetTimer(rotateTimer, this, &AAbstractTower::rotateObject, WORLD_FRAME_SPEED, true);
	
}

// Called every frame
void AAbstractTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAbstractTower::UpdateLevel()
{
	this->RotationSpeed *= ROTATION_UPGRADE_CONST;
	this->ShootingSpeed /= SHOOTING_UPGRADE_CONST;
	this->CostOfUpgrading *= UPGRADE_COST_CONST;
	LevelOfTower++;
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Enemy Destroyed"));
}

void AAbstractTower::rotateRight() {
	if (abs(tempRotation.Yaw - thisRotation.Yaw) > ROTATION_CONST * ROTATION_ANGLE_RIGHT)
	{
		thisRotation.Yaw -= RotationSpeed * ROTATION_ANGLE_RIGHT;
		SetActorRotation(thisRotation);
		isShooting = false;
	}
	else
	{
		isShooting = true;
	}
}


void AAbstractTower::rotateLeft() {
	if (abs(tempRotation.Yaw - thisRotation.Yaw) > -ROTATION_CONST * ROTATION_ANGLE_LEFT)
	{
		thisRotation.Yaw -= RotationSpeed * ROTATION_ANGLE_LEFT;
		SetActorRotation(thisRotation);
		isShooting = false;
	}
	else
	{
		isShooting = true;
	}
}

void AAbstractTower::rotateObject()
{
	if (AllEnemies.Num() > 0)
	{
		FVector EnemyLocation = AllEnemies[0]->GetActorLocation();

		if (EnemyLocation.X > 0 && EnemyLocation.Y > 0)
		{
			tempRotation = thisRotation;
			tempRotation.Yaw = UKismetMathLibrary::RInterpTo(thisRotation, UKismetMathLibrary::FindLookAtRotation(thisLocation, EnemyLocation), UGameplayStatics::GetWorldDeltaSeconds(GetWorld()), RotationSpeed).Yaw;
			tempRotation.Normalize();
			thisRotation.Normalize();
			if (tempRotation.Yaw - thisRotation.Yaw > 0 && tempRotation.Yaw - thisRotation.Yaw < 180 || tempRotation.Yaw - thisRotation.Yaw < 0 && tempRotation.Yaw - thisRotation.Yaw < -180) { rotateLeft(); }
			else { rotateRight(); }
		}
	}
	else
	{
		isShooting = false;
	}
}

void AAbstractTower::shoot()
{
	if (AllEnemies.Num() > 0 && isShooting)
	{
		AActor* tempBullet = GetWorld()->SpawnActor<AActor>(Bullet, this->GetActorTransform());
		AAbstractBullet* Bulle = Cast<AAbstractBullet>(tempBullet);
		if (Bulle)
		{
			Bulle->LevelOfDamage = LevelOfTower - 1;
			Bulle->Enemy = AllEnemies[0];
		}
		GetWorldTimerManager().SetTimer(timer, this, &AAbstractTower::shoot, ShootingSpeed, false);
	}
	else
	{
		GetWorldTimerManager().SetTimer(timer, this, &AAbstractTower::shoot, 0.01, false);
	}
}

