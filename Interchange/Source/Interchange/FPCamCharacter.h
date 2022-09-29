// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "FPCamCharacter.generated.h"


UCLASS()
class INTERCHANGE_API AFPCamCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPCamCharacter();

	void MoveLRAction(float movementDelta);

	void MoveFBAction(float movementDelta);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// Camera Rotation methods
	void HorizontalRotation(float value);
	void VerticalRotation(float value);

	UPROPERTY(EditAnywhere, Category = "Camera")
		UCameraComponent* cam;

	// Jump
	void CheckJump();	// One jump only

	UPROPERTY()
		bool jumping;
};
