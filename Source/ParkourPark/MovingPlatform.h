// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class PARKOURPARK_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, Category="Moving")
	FVector platformVelocity = FVector(100, 0, 0);

	UPROPERTY(EditAnywhere, Category="Moving")
	float moveDistance;

	UPROPERTY(EditAnywhere, Category="Rotation")
	FRotator rotationVelocity;

	// UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector startLocation;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
	void ReturnPlatform(float DeltaTime);
	bool ShouldPlatformReturn() const;
	float GetDistanceMoved() const;



};
