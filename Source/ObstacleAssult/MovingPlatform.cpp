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
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*
		Move platform forwards
			Get current location
			Add vector to current location
			set the location
		Send platform back if gone too far
			Check how far we ve moved
			Reverse direction of motion if goine too far
	*/

	FVector CurrentLocation = GetActorLocation();

	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);

	float PlatformDistance = FVector::Distance(StartLocation, CurrentLocation);
	if (PlatformDistance > moveDistance)
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * moveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
	else
	{
		SetActorLocation(CurrentLocation);
	}
}
