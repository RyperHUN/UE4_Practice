// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "PacManGameState.generated.h"

enum class EGameState : short
{
	EMenu,
	EPlaying,
	EPause,
	EWin,
	EGameOver
};

/**
 * 
 */
UCLASS()
class UETUT_02_PACMAN_API APacManGameState : public AGameMode
{
	GENERATED_BODY()

	TArray<class AEnemy*> Enemies;
	EGameState currentState = EGameState::EMenu;
	APlayerController* PlayerController;
public:
	APacManGameState();

	void BeginPlay() override;

	EGameState GetCurrentState () const;

	void SetCurrentState (EGameState value);
	
	
};
