// Fill out your copyright notice in the Description page of Project Settings.

#include "UETUT_02_Pacman.h"
#include "AIEnemy.h"
#include "Enemy.h"

void AAIEnemy::Possess(class APawn* InPawn)
{
	Super::Possess(InPawn);

	AEnemy* Bot = Cast<AEnemy>(InPawn);

	HomeLocation = Bot->GetActorLocation();
	SearchNewPoint(Bot);
}

AAIEnemy::AAIEnemy()
{
}

void AAIEnemy::OnMoveCompleted(FAIRequestID RequestId,
	EPathFollowingResult::Type Result)
{
	//if(!Bot->bIsDead)
	//	SearchNewPoint ();
}

// in order to find a new point we search if there is a navigation
//mesh active and
// when found, we simple call the GetRandomPointInRadius function from
//the NavMesh
void AAIEnemy::SearchNewPoint(AEnemy* Bot)
{
	static UNavigationSystem* const NavMesh = UNavigationSystem::GetCurrent(GetWorld());
	auto test = NavMesh->GetMainNavData ();
	if (NavMesh)
	{
		const float SearchRadius = 10000.0f;
		FNavLocation RandomPt;
		auto actorLoc = Bot->GetActorLocation();
		const bool bFound = NavMesh->GetRandomPointInNavigableRadius
		(actorLoc, SearchRadius, RandomPt);
		if (bFound)
		{
			MoveToLocation(RandomPt.Location);
		}
	}
}
// simple return to the home location and start a timer for the dead
void AAIEnemy::GoHome()
{
	MoveToLocation(HomeLocation);
	GetWorldTimerManager().SetTimer(TimerDead, this, &AAIEnemy::Rearm, 5.0f, false);
}
//Almost like Respawn
void AAIEnemy::Rearm()
{
	//GetWorldTimerManager().ClearTimer(TimerDead);
	//Bot->Rearm();
}

void AAIEnemy::StopMove()
{
	StopMovement();
}


