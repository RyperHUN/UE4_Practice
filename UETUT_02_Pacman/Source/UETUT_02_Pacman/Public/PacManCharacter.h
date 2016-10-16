// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PacManGameState.h"
#include "Collectable.h"

#include "GameFramework/Character.h"
#include "PacManCharacter.generated.h"



UCLASS()
class UETUT_02_PACMAN_API APacManCharacter : public ACharacter
{
	GENERATED_BODY()

		UStaticMeshComponent* SphereMesh;

	uint8 CollectablesToEat; //Total collactbles
	uint8 Lives;    //Total lives

	FVector SpawnPoint;
	void Kill();

	APacManGameState* GameMode;

	UFUNCTION()
	void OnCollision(class UPrimitiveComponent* HitComp, class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult & SweepResult);
public:
	FVector CurrentVelocity;
	// Sets default values for this character's properties
	APacManCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//Input handler functions
	void MoveXAxis(float AxisValue);
	void MoveYAxis(float AxisValue);
	void NewGame();
	void Pause();
	void RestartGame();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
