// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Enemy.h"
#include "AIController.h"
#include "AIEnemy.generated.h"

/**
 * 
 */
UCLASS()
class UETUT_02_PACMAN_API AAIEnemy : public AAIController
{
	GENERATED_BODY()
	
public:
	AAIEnemy();
	//It's like BeginPlay
	void Possess(class APawn* InPawn) override;

	virtual void OnMoveCompleted (FAIRequestID RequestId,
		EPathFollowingResult::Type Result) override;
	void SearchNewPoint();
	void GoHome ();
	void Rearm();

	void StopMove();
private:
	class AEnemy* Bot;
	FVector HomeLocation;
	FTimerHandle TimerDead; //Before returning chasing pacman
};
