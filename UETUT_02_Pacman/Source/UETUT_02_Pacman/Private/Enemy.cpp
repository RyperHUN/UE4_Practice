// Fill out your copyright notice in the Description page of Project Settings.

#include "UETUT_02_Pacman.h"
#include "Enemy.h"

void AEnemy::SetMove (bool bMoveIt)
{
	// need to cast the AI class and call two public functions from here
		// if false move to its location in order to stop movements
	AAIEnemy* AI = Cast<AAIEnemy>(AIControllerClass);
	
	if (bMoveIt) 
		AI->SearchNewPoint(); 
	else 
		AI->StopMove(); 
}

void AEnemy::Kill ()
{
	if (bIsDead)  //Don't kill twice
		return;

	//IF not dead, kill and modify it's speed, to go fast and respawn
	bIsDead = true;
	GetCharacterMovement ()->MaxWalkSpeed = 300.0f;
}

// Sets default values
AEnemy::AEnemy()
{
 	SetActorEnableCollision (true);

	GetCapsuleComponent()->SetCapsuleRadius (40.0f);
	GetCapsuleComponent()->SetCapsuleHalfHeight(50.0f);
	
	//Add cylinder shape
	static ConstructorHelpers::FObjectFinder<UStaticMesh>CylinderObj
		(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));

	EnemyBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	EnemyBody->StaticMesh = CylinderObj.Object;
	EnemyBody->SetRelativeScale3D(FVector(0.7f, 0.8f, 1.0f));
	EnemyBody->AttachTo(RootComponent);

	///TODO Replace
	static ConstructorHelpers::FObjectFinder<UMaterial>
		VulnerableMat(TEXT("Material'/Game/Materials/M_Enemy_Blue.M_Enemy_Blue'"));
	VulnerableMaterial = VulnerableMat.Object;

	//Controlled by AIController
	AIControllerClass = AAIEnemy::StaticClass ();
}

void AEnemy::OnCollision(class UPrimitiveComponent* HitComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult & SweepResult)
{
	
}


// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	DefaultMaterial = EnemyBody->GetMaterial(0); //Store material when respawning

	GetCapsuleComponent() ->OnComponentBeginOverlap.AddDynamic (this, &AEnemy::OnCollision);

}

// Called every frame
void AEnemy::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(class UInputComponent* InputComponent2)
{
	Super::SetupPlayerInputComponent(InputComponent2);

}

