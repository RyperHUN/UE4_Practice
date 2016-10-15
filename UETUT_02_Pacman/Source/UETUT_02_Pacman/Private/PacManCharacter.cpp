// Fill out your copyright notice in the Description page of Project Settings.

#include "UETUT_02_Pacman.h"
#include "PacManCharacter.h"


// Sets default values
APacManCharacter::APacManCharacter()
	: CurrentVelocity (0.0f)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APacManCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APacManCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

//Input handler functions
void APacManCharacter::MoveXAxis (float AxisValue)
{
	this->CurrentVelocity.X = AxisValue;
	AddMovementInput (CurrentVelocity);
}
void APacManCharacter::MoveYAxis (float AxisValue)
{
	CurrentVelocity.Y = AxisValue;
	AddMovementInput (CurrentVelocity);
}
void APacManCharacter::NewGame ()
{

}

void APacManCharacter::Pause ()
{

}
void APacManCharacter::RestartGame ()
{

}


// Called to bind functionality to input
void APacManCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent2)
{
	Super::SetupPlayerInputComponent(InputComponent2);

	//Bind the input from the player
	InputComponent2->BindAxis ("MoveX", this, &APacManCharacter::MoveXAxis);
	InputComponent2->BindAxis ("MoveY", this, &APacManCharacter::MoveYAxis);
	InputComponent2->BindAction("NewGame", IE_Pressed, this, &APacManCharacter::NewGame);
	InputComponent2->BindAction("Pause",   IE_Pressed, this, &APacManCharacter::Pause);
	InputComponent2->BindAction("Restart", IE_Pressed, this, &APacManCharacter::Restart);


}
