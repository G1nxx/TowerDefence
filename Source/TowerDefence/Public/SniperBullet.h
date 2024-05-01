// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbstractBullet.h"
#include "GameFramework/Actor.h"
#include "SniperBullet.generated.h"

UCLASS()
class TOWERDEFENCE_API ASniperBullet : public AAbstractBullet
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASniperBullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
