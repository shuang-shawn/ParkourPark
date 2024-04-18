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
	startLocation = GetActorLocation();

	FString MyString = GetName();

	UE_LOG(LogTemp, Display, TEXT("Begin play: %s"), *MyString);
	// UE_LOG(LogTemp, Warning, TEXT("Your message"));
	// UE_LOG(LogTemp, Error, TEXT("Your message"));

	
	
	
	

	 

}

// Called every frame

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
	if (ShouldPlatformReturn()) {
		ReturnPlatform(DeltaTime);
	}
	RotatePlatform(DeltaTime);
	
	

	
}


void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + platformVelocity * DeltaTime;
	SetActorLocation(CurrentLocation);
}

void AMovingPlatform::ReturnPlatform(float DeltaTime)
{
	startLocation = startLocation + moveDistance * platformVelocity.GetSafeNormal();
	SetActorLocation(startLocation);
	platformVelocity *= -1;
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	return GetDistanceMoved() > moveDistance;
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(startLocation, GetActorLocation());
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(rotationVelocity * DeltaTime);
}


