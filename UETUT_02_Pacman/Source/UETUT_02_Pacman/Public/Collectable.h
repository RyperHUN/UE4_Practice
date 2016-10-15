// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Collectable.generated.h"



// Ettol latjuk az editorban
UCLASS() 
class UETUT_02_PACMAN_API ACollectable : public AActor
{
	GENERATED_BODY()

public:	

	UPROPERTY(EditDefaultsOnly, Category = Collectable)
		USphereComponent* BaseCollisionComponent;
	UPROPERTY(EditDefaultsOnly, Category = Collectable)
		UStaticMeshComponent* CollectableMesh;
	UPROPERTY(EditAnywhere, Category = Collectable)
		bool bIsSuperCollectable;

	// Sets default values for this actor's properties
	ACollectable();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
