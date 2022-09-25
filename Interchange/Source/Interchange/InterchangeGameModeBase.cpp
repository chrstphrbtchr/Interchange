// Copyright Epic Games, Inc. All Rights Reserved.


#include "InterchangeGameModeBase.h"

AInterchangeGameModeBase::AInterchangeGameModeBase()
{
	//instead of defaulting to a freefly camera we default to our character class
	DefaultPawnClass = AFPCamCharacter::StaticClass(); 
}

