// Fill out your copyright notice in the Description page of Project Settings.


#include "AbstractEnemy.h"

// Sets default values
AAbstractEnemy::AAbstractEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


void AAbstractEnemy::TakeDamage(const int32 IncomingDamage)
{
	Health -= IncomingDamage;
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Take Damage"));
	if (Health <= 0)
	{
		EnemyIsKilled();
	}
}

// Called when the game starts or when spawned
void AAbstractEnemy::BeginPlay()
{
	/*srand(time(nullptr));
	int32 Bias = rand() % 101 - 50;*/
	//ThisPosition.X = Bias;

	isRotatingX = false;
	isRotatingY = false;
	ValueForKilling = 0;
	Health = 100;
	EnemyDirection = forward;

	ThisPosition = this->GetActorLocation();
	ThisRotation = this->GetActorRotation();
	ControlPoints.Add(FVector(ThisPosition.X, ThisPosition.Y + 21 * SIZE_OF_TITLE, ThisPosition.Z));
	ControlPoints.Add(FVector(ThisPosition.X + 39 * SIZE_OF_TITLE, ThisPosition.Y + 22 * SIZE_OF_TITLE, ThisPosition.Z));
	ControlPoints.Add(FVector(ThisPosition.X + 40 * SIZE_OF_TITLE, ThisPosition.Y + 7 * SIZE_OF_TITLE, ThisPosition.Z));
	ControlPoints.Add(FVector(ThisPosition.X + 13 * SIZE_OF_TITLE, ThisPosition.Y + 6 * SIZE_OF_TITLE, ThisPosition.Z));
	ControlPoints.Add(FVector(ThisPosition.X + 12 * SIZE_OF_TITLE, ThisPosition.Y + 16 * SIZE_OF_TITLE, ThisPosition.Z));

	RotatePoints.Add(FVector(ThisPosition.X + SIZE_OF_TITLE, ThisPosition.Y + 21 * SIZE_OF_TITLE, ThisPosition.Z));
	RotatePoints.Add(FVector(ThisPosition.X + 39 * SIZE_OF_TITLE, ThisPosition.Y + 21 * SIZE_OF_TITLE, ThisPosition.Z));
	RotatePoints.Add(FVector(ThisPosition.X + 39 * SIZE_OF_TITLE, ThisPosition.Y + 7 * SIZE_OF_TITLE, ThisPosition.Z));
	RotatePoints.Add(FVector(ThisPosition.X + 13 * SIZE_OF_TITLE, ThisPosition.Y + 7 * SIZE_OF_TITLE, ThisPosition.Z));
	RotatePoints.Add(FVector(ThisPosition.X + 12 * SIZE_OF_TITLE, ThisPosition.Y + 16 * SIZE_OF_TITLE, ThisPosition.Z));
	Super::BeginPlay();
}

// Called every frame
void AAbstractEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	moveEnemy();
}

void AAbstractEnemy::moveEnemy()
{
	if (IndI < ControlPoints.Num())
	{
		if (isRotatingX || isRotatingY) { rotateEnemy(); }
		else if (ThisPosition.X == ControlPoints[IndI].X) {
			if (ThisPosition.Y < ControlPoints[IndI].Y) {
				ThisPosition.Y += MovementSpeed;
				SetActorLocation(ThisPosition, true);
				if (ThisPosition.Y >= ControlPoints[IndI].Y)
				{
					SetActorLocation(ControlPoints[IndI], true);
					isRotatingX = true;
					EnemyDirection = ThisPosition.X == RotatePoints[IndI].X ? ThisPosition.Y > RotatePoints[IndI].Y ? right : left : ThisPosition.X < RotatePoints[IndI].X ? right : left;
				}
			}
			else if (ThisPosition.Y > ControlPoints[IndI].Y)
			{
				ThisPosition.Y -= MovementSpeed;
				SetActorLocation(ThisPosition, true);
				if (ThisPosition.Y <= ControlPoints[IndI].Y)
				{
					SetActorLocation(ControlPoints[IndI], true);
					isRotatingX = true;
					EnemyDirection = ThisPosition.X == RotatePoints[IndI].X ? ThisPosition.Y > RotatePoints[IndI].Y ? right : left : ThisPosition.X < RotatePoints[IndI].X ? right : left;
				}
			}
		}
		else if (ThisPosition.Y == ControlPoints[IndI].Y)
		{
			if (ThisPosition.X < ControlPoints[IndI].X) {
				ThisPosition.X += MovementSpeed;
				SetActorLocation(ThisPosition, true);
				if (ThisPosition.X >= ControlPoints[IndI].X)
				{
					SetActorLocation(ControlPoints[IndI], true);
					isRotatingY = true;
					EnemyDirection = ThisPosition.X == RotatePoints[IndI].X ? ThisPosition.Y < RotatePoints[IndI].Y ? right : left : ThisPosition.X < RotatePoints[IndI].X ? right : left;
				}
			}
			else if (ThisPosition.X > ControlPoints[IndI].X) {
				ThisPosition.X -= MovementSpeed;
				SetActorLocation(ThisPosition, true);
				if (ThisPosition.X <= ControlPoints[IndI].X)
				{
					SetActorLocation(ControlPoints[IndI], true);
					isRotatingY = true;
					EnemyDirection = ThisPosition.X == RotatePoints[IndI].X ? ThisPosition.Y < RotatePoints[IndI].Y ? right : left : ThisPosition.X < RotatePoints[IndI].X ? right : left;
				}
			}
		}
	}
	else
	{
		EnemyAtBase();
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Enemy Destroyed"));
	}
}

void AAbstractEnemy::rotateEnemy()
{
	if (IndI == ControlPoints.Num() - 1)
	{
		IndI++;
	}
	else if (isRotatingX)
	{
		if (EnemyDirection == right)
		{
			rotateRight();
			if (ThisPosition.X > RotatePoints[IndI].X)
			{
				ThisPosition.X = RotatePoints[IndI].X;
				ThisPosition.Y = ControlPoints[IndI + 1].Y;
				SetActorLocation(ThisPosition, true);
				IndI++;
				isRotatingX = false;
			}
		}
		else if (EnemyDirection == left)
		{
			rotateRight();
			if (ThisPosition.X < RotatePoints[IndI].X)
			{
				ThisPosition.X = RotatePoints[IndI].X;
				ThisPosition.Y = ControlPoints[IndI + 1].Y;
				SetActorLocation(ThisPosition, true);
				IndI++;
				isRotatingX = false;
			}
		}
	}
	else if (isRotatingY)
	{
		if (EnemyDirection == right) {
			rotateRight();
			if (ThisPosition.Y > RotatePoints[IndI].Y)
			{
				ThisPosition.Y = RotatePoints[IndI].Y;
				ThisPosition.X = ControlPoints[IndI + 1].X;
				SetActorLocation(ThisPosition, true);
				IndI++;
				isRotatingY = false;
			}
		}
		else if (EnemyDirection == left)
		{
			rotateRight();
			if (ThisPosition.Y < RotatePoints[IndI].Y)
			{
				ThisPosition.Y = RotatePoints[IndI].Y;
				ThisPosition.X = ControlPoints[IndI + 1].X;
				SetActorLocation(ThisPosition, true);
				IndI++;
				isRotatingY = false;
			}
		}
	}
}

void AAbstractEnemy::rotateRight() {
	ThisRotation.Yaw -= ROTATION_CONST * ROTATION_ANGLE_RIGHT_ENEMY;
	SetActorRotation(ThisRotation);
	long double newX =
		(ThisPosition.X - RotatePoints[IndI].X) * std::cos(ROTATION_ANGLE_RIGHT_ENEMY) + (ThisPosition.Y - RotatePoints[IndI].Y) * std::sin(ROTATION_ANGLE_RIGHT_ENEMY) + RotatePoints[IndI].X;
	long double newY =
		(ThisPosition.Y - RotatePoints[IndI].Y) * std::cos(ROTATION_ANGLE_RIGHT_ENEMY) - (ThisPosition.X - RotatePoints[IndI].X) * std::sin(ROTATION_ANGLE_RIGHT_ENEMY) + RotatePoints[IndI].Y;
	ThisPosition.X = newX;
	ThisPosition.Y = newY;
	SetActorLocation(ThisPosition, true);
}


void AAbstractEnemy::rotateLeft() {
	ThisRotation.Yaw -= ROTATION_CONST * ROTATION_ANGLE_LEFT_ENEMY;
	SetActorRotation(ThisRotation);
	long double newX =
		(ThisPosition.X - RotatePoints[IndI].X) * std::cos(ROTATION_ANGLE_LEFT_ENEMY) + (ThisPosition.Y - RotatePoints[IndI].Y) * std::sin(ROTATION_ANGLE_LEFT_ENEMY) + RotatePoints[IndI].X;
	long double newY =
		(ThisPosition.Y - RotatePoints[IndI].Y) * std::cos(ROTATION_ANGLE_LEFT_ENEMY) - (ThisPosition.X - RotatePoints[IndI].X) * std::sin(ROTATION_ANGLE_LEFT_ENEMY) + RotatePoints[IndI].Y;
	ThisPosition.X = newX;
	ThisPosition.X = newY;
	SetActorLocation(ThisPosition, true);
}

