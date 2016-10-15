// Fill out your copyright notice in the Description page of Project Settings.

#include "UETUT_02_Pacman.h"
#include "PacManGameState.h"



EGameState APacManGameState::GetCurrentState() const
{
	return currentState;
}

void APacManGameState::SetCurrentState(EGameState value)
{
	currentState = value;
}


