// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	MyVector = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	MyVector.X += 300;
	MyVector.Y += 300;

	
	
	
	

	 

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector LocalVector = MyVector;


	LocalVector.Z = LocalVector.Z + 0.1;
	MyVector.Z += 0.1;
	SetActorLocation(MyVector);

}

