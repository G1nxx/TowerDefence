// Fill out your copyright notice in the Description page of Project Settings.


#include "AbstractEnemy.h"

void AAbstractEnemy::checkMoveEnemy()
{
	if (isMoving)
	{
		moveEnemy();
	}
}

void AAbstractEnemy::setEnemyX()
{
	SetActorLocation(controlPoints[indI], true);
	isRotatingX = true;
	enemyDirection = thisPosition.X == rotatePoints[indI].X ? thisPosition.Y > rotatePoints[indI].Y ? right : left : thisPosition.X < rotatePoints[indI].X ? right : left;
}


void AAbstractEnemy::setEnemyY()
{
	SetActorLocation(controlPoints[indI], true);
	isRotatingY = true;
	enemyDirection = thisPosition.X == rotatePoints[indI].X ? thisPosition.Y < rotatePoints[indI].Y ? right : left : thisPosition.X < rotatePoints[indI].X ? right : left;
}

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
	enemyDirection = forward;

	thisPosition = this->GetActorLocation();
	thisRotation = this->GetActorRotation();
	Super::BeginPlay();


	GetWorldTimerManager().SetTimer(moveTimer, this, &AAbstractEnemy::checkMoveEnemy, WORLD_FRAME_SPEED, true);
}

// Called every frame
void AAbstractEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAbstractEnemy::setIsMoving(bool branch)
{
	isMoving = branch;
}

void AAbstractEnemy::moveEnemy()
{
	if (indI < controlPoints.Num())
	{
		if (isRotatingX || isRotatingY) { rotateEnemy(); }
		else if (thisPosition.X == controlPoints[indI].X) {
			if (thisPosition.Y < controlPoints[indI].Y) {
				thisPosition.Y += MovementSpeed;
				SetActorLocation(thisPosition, true);
				if (thisPosition.Y >= controlPoints[indI].Y)
				{
					setEnemyX();
				}
			}
			else if (thisPosition.Y > controlPoints[indI].Y)
			{
				thisPosition.Y -= MovementSpeed;
				SetActorLocation(thisPosition, true);
				if (thisPosition.Y <= controlPoints[indI].Y)
				{
					setEnemyX();
				}
			}
		}
		else if (thisPosition.Y == controlPoints[indI].Y)
		{
			if (thisPosition.X < controlPoints[indI].X) {
				thisPosition.X += MovementSpeed;
				SetActorLocation(thisPosition, true);
				if (thisPosition.X >= controlPoints[indI].X)
				{
					setEnemyY();
				}
			}
			else if (thisPosition.X > controlPoints[indI].X) {
				thisPosition.X -= MovementSpeed;
				SetActorLocation(thisPosition, true);
				if (thisPosition.X <= controlPoints[indI].X)
				{
					setEnemyY();
				}
			}
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("error"));
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
	if (indI == controlPoints.Num() - 1)
	{
		indI++;
	}
	else if (isRotatingX)
	{
		if (enemyDirection == right)
		{
			rotateRight();
			if (thisPosition.X > rotatePoints[indI].X)
			{
				thisPosition.X = rotatePoints[indI].X;
				thisPosition.Y = controlPoints[indI + 1].Y;
				SetActorLocation(thisPosition, true);
				indI++;
				isRotatingX = false;
			}
		}
		else if (enemyDirection == left)
		{
			rotateRight();
			if (thisPosition.X < rotatePoints[indI].X)
			{
				thisPosition.X = rotatePoints[indI].X;
				thisPosition.Y = controlPoints[indI + 1].Y;
				SetActorLocation(thisPosition, true);
				indI++;
				isRotatingX = false;
			}
		}
	}
	else if (isRotatingY)
	{
		if (enemyDirection == right) {
			rotateRight();
			if (thisPosition.Y > rotatePoints[indI].Y)
			{
				thisPosition.Y = rotatePoints[indI].Y;
				thisPosition.X = controlPoints[indI + 1].X;
				SetActorLocation(thisPosition, true);
				indI++;
				isRotatingY = false;
			}
		}
		else if (enemyDirection == left)
		{
			rotateRight();
			if (thisPosition.Y < rotatePoints[indI].Y)
			{
				thisPosition.Y = rotatePoints[indI].Y;
				thisPosition.X = controlPoints[indI + 1].X;
				SetActorLocation(thisPosition, true);
				indI++;
				isRotatingY = false;
			}
		}
	}
}

void AAbstractEnemy::rotateRight() {
	thisRotation.Yaw -= ROTATION_CONST * ROTATION_ANGLE_RIGHT_ENEMY;
	SetActorRotation(thisRotation);
	long double newX =
		(thisPosition.X - rotatePoints[indI].X) * std::cos(ROTATION_ANGLE_RIGHT_ENEMY) + (thisPosition.Y - rotatePoints[indI].Y) * std::sin(ROTATION_ANGLE_RIGHT_ENEMY) + rotatePoints[indI].X;
	long double newY =
		(thisPosition.Y - rotatePoints[indI].Y) * std::cos(ROTATION_ANGLE_RIGHT_ENEMY) - (thisPosition.X - rotatePoints[indI].X) * std::sin(ROTATION_ANGLE_RIGHT_ENEMY) + rotatePoints[indI].Y;
	thisPosition.X = newX;
	thisPosition.Y = newY;
	SetActorLocation(thisPosition, true);
}


void AAbstractEnemy::rotateLeft() {
	thisRotation.Yaw -= ROTATION_CONST * ROTATION_ANGLE_LEFT_ENEMY;
	SetActorRotation(thisRotation);
	long double newX =
		(thisPosition.X - rotatePoints[indI].X) * std::cos(ROTATION_ANGLE_LEFT_ENEMY) + (thisPosition.Y - rotatePoints[indI].Y) * std::sin(ROTATION_ANGLE_LEFT_ENEMY) + rotatePoints[indI].X;
	long double newY =
		(thisPosition.Y - rotatePoints[indI].Y) * std::cos(ROTATION_ANGLE_LEFT_ENEMY) - (thisPosition.X - rotatePoints[indI].X) * std::sin(ROTATION_ANGLE_LEFT_ENEMY) + rotatePoints[indI].Y;
	thisPosition.X = newX;
	thisPosition.X = newY;
	SetActorLocation(thisPosition, true);
}

