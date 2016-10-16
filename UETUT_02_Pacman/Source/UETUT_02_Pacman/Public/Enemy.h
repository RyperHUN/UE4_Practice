// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIEnemy.h"
#include "PacManCharacter.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class UETUT_02_PACMAN_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	//Make it editable to modify Colors in editor
	UPROPERTY(EditDefaultsOnly, Category = Body)
	UStaticMeshComponent* EnemyBody;

	void SetVulnerable ();
	void SetInvulnerable ();

	void SetMove (bool MoveIt);
	void Kill ();
	void Rearm ();

	bool bIsDead;

	// Sets default values for this character's properties
	AEnemy();

	UFUNCTION()
	void OnCollision(class UPrimitiveComponent* HitComp, class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult & SweepResult);

	

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

private:
	bool bIsVulnerable;

	FTimerHandle TimerVulnerable;

	class UMaterialInterface* DefaultMaterial;
	class UMaterialInterface* VulnerableMaterial;
	
};
