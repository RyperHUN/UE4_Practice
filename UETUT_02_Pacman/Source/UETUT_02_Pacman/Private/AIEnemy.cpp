// Fill out your copyright notice in the Description page of Project Settings.

#include "UETUT_02_Pacman.h"
#include "AIEnemy.h"

void AAIEnemy::Possess(class APawn* InPawn)
{
	Super::Possess(InPawn);

	Bot = Cast<AEnemy>(InPawn);

	HomeLocation = Bot->GetActorLocation();
	SearchNewPoint();
}

AAIEnemy::AAIEnemy()
{

}

void AAIEnemy::OnMoveCompleted(FAIRequestID RequestId,
	EPathFollowingResult::Type Result)
{
}

void AAIEnemy::SearchNewPoint()
{

}

void AAIEnemy::GoHome()
{
}

void AAIEnemy::Rearm()
{
}

void AAIEnemy::StopMove()
{

}


