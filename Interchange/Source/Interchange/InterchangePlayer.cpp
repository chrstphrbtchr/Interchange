// Fill out your copyright notice in the Description page of Project Settings.


#include "InterchangePlayer.h"

// Sets default values
AInterchangePlayer::AInterchangePlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInterchangePlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInterchangePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AInterchangePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

