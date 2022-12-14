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

	UPROPERTY(VisibleAnywhere, Category = "Camera")
		class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, Category = "Camera")
		UCameraComponent* cam;

	UPROPERTY(EditAnywhere, Category = "Components")
		AActor* capsule;

	

	// Jump
	void CheckJump();	// One jump only

	// Swap
	void SelectTarget();
	void SwapPlayerTarget();
	void SwapTick();

	//Sprint
	void SpeedUp();
	void SpeedDown();

	UPROPERTY()
		bool jumping;
		AActor *swapTarget;
		bool swapAvailable;
		float playerSpeed;
		bool swapping;
		FVector targetVelocity;
		FVector playerVelocity;
		FVector startingPoint;
		FVector finalDestination;

	void MantleJump();
};
