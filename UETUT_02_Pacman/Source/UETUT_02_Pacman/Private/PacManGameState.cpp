// Fill out your copyright notice in the Description page of Project Settings.

#include "UETUT_02_Pacman.h"
#include "PacManGameState.h"


APacManGameState::APacManGameState()
{
	//search our custom pacman and set as default pawn if founded
	static ConstructorHelpers::FClassFinder<APawn>
			//PlayerPawnOb(TEXT("Class'/Script/UETUT_02_Pacman.PacManCharacter'"));
		    //PlayerPawnOb(TEXT("Blueprint'/Game/Blueprints/MyPacManCharacter.MyPacManCharacter'"));
		PlayerPawnOb(TEXT("Blueprint'/Game/Blueprints/BP_PacManChar.BP_PacManChar_C'"));

	if (PlayerPawnOb.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnOb.Class;
	}
}

void APacManGameState::BeginPlay ()
{
	Super::BeginPlay();
	// set to be on menu state as soon as the game start
	SetCurrentState(EGameState::EMenu);
	// find the first player controller and set it to our pc

		PlayerController = GetWorld()->GetFirstPlayerController();
	// find the ghosts in the scene and store them to our array
	//for (TActorIterator<AEnemy> enemyIt(GetWorld()); enemyIt; ++
	//	enemyIt)
	//{
	//	AEnemy * enemy = Cast< AEnemy >(*enemyIt);
	//	if (enemy) { Enemies.Add(enemy); }
	//}
}

EGameState APacManGameState::GetCurrentState() const
{
	return currentState;
}

void APacManGameState::SetCurrentState(EGameState value)
{
	currentState = value;
}


