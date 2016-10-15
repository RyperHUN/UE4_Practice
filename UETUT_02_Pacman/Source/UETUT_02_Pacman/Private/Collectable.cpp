// Fill out your copyright notice in the Description page of Project Settings.

#include "UETUT_02_Pacman.h"
#include "Collectable.h"


// Sets default values
ACollectable::ACollectable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	SetActorEnableCollision(true);
	//Setting collision component:
	BaseCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("BaseCollisionComponent"));

	CollectableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CollectableMesh"));
	
	CollectableMesh->AttachTo(BaseCollisionComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Sphere(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));

	if(Sphere.Succeeded () ) //Lecsekkolj amegtalalta-e az objectet a contet browserbe!
		CollectableMesh->SetStaticMesh(Sphere.Object);

	CollectableMesh->SetWorldScale3D (FVector(0.3,0.3,0.3));
	BaseCollisionComponent->SetSphereRadius(16);
}

// Called when the game starts or when spawned
void ACollectable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectable::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

