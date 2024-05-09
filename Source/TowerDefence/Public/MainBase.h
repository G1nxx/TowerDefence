// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "MainBase.generated.h"

UCLASS()
class TOWERDEFENCE_API AMainBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainBase")
	int32 HealthOfMainBase;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainBase")
	int32 MoneyInGame;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CostOfTowers")
	int32 BasicTowerCost = 50;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CostOfTowers")
	int32 SplashTowerCost = 65;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CostOfTowers")
	int32 SniperTowerCost = 100;

	UFUNCTION(BlueprintImplementableEvent, Category = "EndOfGame")
	void BaseDestroyedEvent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
