// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbstractTower.h"
#include "GameFramework/Actor.h"
#include "SniperTower.generated.h"

UCLASS()
class TOWERDEFENCE_API ASniperTower : public AAbstractTower
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASniperTower();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
