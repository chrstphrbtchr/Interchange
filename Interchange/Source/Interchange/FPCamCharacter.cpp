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

	//create components
	cam = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	//setup camera
	//Camera->FieldOfView = 120.f;					//FOV changer
	cam->SetupAttachment(RootComponent);			// Attaches to center of player object.
	cam->SetRelativeLocation(FVector(0, 0, 50));	// ? Might need to be changed for player

	jumping = false;
	swapAvailable = false;
	swapTarget = (AActor *) NULL;
	playerSpeed = 7.0f;

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

	if (jumping) { Jump(); }	// UNREAL DID IT FOR US!
}

// Called to bind functionality to input
void AFPCamCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Rotation bindings
	InputComponent->BindAxis("Rot_Horizontal", this, &AFPCamCharacter::HorizontalRotation);
	InputComponent->BindAxis("Rot_Vertical",   this, &AFPCamCharacter::VerticalRotation);

	//LRMovement bindings
	PlayerInputComponent->BindAxis("MoveLR", this, &AFPCamCharacter::MoveLRAction);
	PlayerInputComponent->BindAxis("MoveFB", this, &AFPCamCharacter::MoveFBAction);

	//Jump input
	InputComponent->BindAction("Jump", IE_Pressed,  this, &AFPCamCharacter::CheckJump);
	InputComponent->BindAction("Jump", IE_Released, this, &AFPCamCharacter::CheckJump);

	//Swap Left Click
	InputComponent->BindAction("LeftClick", IE_Pressed, this, &AFPCamCharacter::SelectTarget);
	InputComponent->BindAction("LeftClick", IE_Released, this, &AFPCamCharacter::SwapPlayerTarget);

	//Sprint Inputs
	InputComponent->BindAction("Sprint", IE_Pressed, this, &AFPCamCharacter::SpeedUp);
	InputComponent->BindAction("Sprint", IE_Released, this, &AFPCamCharacter::SpeedDown);
}

void AFPCamCharacter::CheckJump() {
	jumping = jumping ? false : true;
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

void AFPCamCharacter::MoveLRAction(float movementDelta)
{
	FVector newLocation = GetActorLocation();
	FVector horizontalVector = GetActorRightVector();
	newLocation += (horizontalVector *movementDelta*playerSpeed);
	//global implementation, instead of local rotation based
	//newLocation.Y += (movementDelta*7.0f);
	SetActorLocation(newLocation);
}

void AFPCamCharacter::MoveFBAction(float movementDelta)
{
	FVector newLocation = GetActorLocation();
	FVector forwardVector = GetActorForwardVector();
	newLocation += (forwardVector * movementDelta * playerSpeed);
	SetActorLocation(newLocation);
}

void AFPCamCharacter::SelectTarget()
{
	FHitResult InteractHit;
	TArray<FHitResult, FDefaultAllocator> InteractHits;
	FVector const CamLoc = cam->GetComponentLocation();
	FRotator const CamRot = cam->GetComponentRotation();
	bool BHit = GetWorld()->LineTraceMultiByChannel(InteractHits, CamLoc, CamRot.Vector() * 100000.f + CamLoc, ECC_GameTraceChannel1);
	bool bHit = GetWorld()->LineTraceSingleByChannel(InteractHit, CamLoc, CamRot.Vector() * 100000.f + CamLoc, ECC_Pawn);
	if (InteractHits.Num() > 0)
	{
		if (bHit)
		{
			if (InteractHit.GetActor() == InteractHits.GetData()->GetActor())
			{
				swapTarget = InteractHits.GetData()->GetActor();
				swapAvailable = true;
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Hit inside"));
			}
			else
			{
				swapAvailable = false;
			}
		}
	}
	else
	{
		swapAvailable = false;
	}
	
	/*
	if (bHit)
	{
		swapTarget = InteractHit.GetActor();//<- if bHit was false, this would return NULL.
		swapAvailable = true;
	}
	*/
	
}

void AFPCamCharacter::SwapPlayerTarget()
{
	if (swapAvailable)
	{
		FVector finalDestination = swapTarget->GetActorLocation();
		FVector targetVelocity = swapTarget->GetVelocity();
		//NEED TO FIGURE OUT HOW TO ACCESS MASS
		FVector playerVelocity = GetVelocity();
		FVector startingPoint = GetActorLocation();
		swapTarget->SetActorEnableCollision(false);
		swapTarget->SetActorLocation(startingPoint);
		SetActorLocation(finalDestination);
		GetRootComponent()->ComponentVelocity = targetVelocity;
		swapTarget->GetRootComponent()->ComponentVelocity = playerVelocity;
		swapTarget->SetActorEnableCollision(true);
		

	}
}

void AFPCamCharacter::SpeedUp()
{
	playerSpeed = 14.0f;
}

void AFPCamCharacter::SpeedDown()
{
	playerSpeed = 7.0f;
}

void MantleJump()
{
	
}
