// Fill out your copyright notice in the Description page of Project Settings.


#include "FPCamCharacter.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AFPCamCharacter::AFPCamCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	bUseControllerRotationYaw = false;	// Yaw is defaulted to true?

	cam = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	cam->SetupAttachment(RootComponent);	// Attaches to center of player object.
	cam->SetRelativeLocation(FVector(0, 0, 40));	// ? Might need to be changed for player

	
}

// Called when the game starts or when spawned
void AFPCamCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPCamCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPCamCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Rotation bindings
	InputComponent->BindAxis("Rot_Horizontal", this, &AFPCamCharacter::HorizontalRotation);
	InputComponent->BindAxis("Rot_Vertical", this, &AFPCamCharacter::VerticalRotation);

}

void AFPCamCharacter::HorizontalRotation(float value) 
{
	if (value) {
		AddActorLocalRotation(FRotator(0, value, 0));
	}
}

void AFPCamCharacter::VerticalRotation(float value)
{
	if (value) 
	{
		float temp = cam->GetRelativeRotation().Pitch + value;
		if (temp < 65 && temp > -75) 
		{
			cam->AddLocalRotation(FRotator(value, 0, 0));
		}
	}
}

