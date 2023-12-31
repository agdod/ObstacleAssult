// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void MovePlatfrom(float DeltaTime);
	void RotatePlatfrom(float DeltaTime);
	bool ShouldPlatformReturn() const;
	float GetDistanceMoved() const;

	UPROPERTY(EditAnyWhere, Category = "Moving Platform")
	FVector PlatformVelocity = FVector(200, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	float moveDistance = 100;
	FVector StartLocation;
	UPROPERTY(EditAnywhere, Category = "Rotating Platfrom")
	FRotator RotationVelocity;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
