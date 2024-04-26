// Fill out your copyright notice in the Description page of Project Settings.


#include "MainBase.h"

// Sets default values
AMainBase::AMainBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainBase::BeginPlay()
{
	HealthOfMainBase = 5;
	Super::BeginPlay();
	
}

// Called every frame
void AMainBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (HealthOfMainBase <= 0)
	{
		UGameplayStatics::SetGamePaused(GetWorld(), true);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You lose!"));
	}
}

