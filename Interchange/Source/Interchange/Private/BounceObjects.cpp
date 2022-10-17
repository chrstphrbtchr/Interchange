// Fill out your copyright notice in the Description page of Project Settings.


#include "BounceObjects.h"

// Sets default values
ABounceObjects::ABounceObjects()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABounceObjects::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABounceObjects::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

