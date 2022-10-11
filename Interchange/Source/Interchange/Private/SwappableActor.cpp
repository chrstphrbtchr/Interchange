// Fill out your copyright notice in the Description page of Project Settings.


#include "SwappableActor.h"

// Sets default values
ASwappableActor::ASwappableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	//variable declarations
	/*weight = GetThisWeight(); <-- Can maybe reference object name or model?
	  lockedOn = false;*/
}

// Called when the game starts or when spawned
void ASwappableActor::BeginPlay()
{
	Super::BeginPlay();
	//Tried to enforce auto enabling of Physics, but I couldn't figure out how. -J.S.
	//Not necessary, but could have been nice.
	/*
	for each (TObjectPtr<AActor> var in Children)
	{
		UPrimitiveComponent* PhysicsBody;
		PhysicsBody = var.Get()->GetRootComponent();
		//var.Get()
		var.Get()->GetRootComponent()->SetSimulatePhysics(true);
	}
	*/
	
}

// Called every frame
void ASwappableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

