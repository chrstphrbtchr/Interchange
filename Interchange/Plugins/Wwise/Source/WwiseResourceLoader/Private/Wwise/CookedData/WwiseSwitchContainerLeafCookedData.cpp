/*******************************************************************************
The content of this file includes portions of the proprietary AUDIOKINETIC Wwise
Technology released in source code form as part of the game integration package.
The content of this file may not be used without valid licenses to the
AUDIOKINETIC Wwise Technology.
Note that the use of the game engine is subject to the Unreal(R) Engine End User
License Agreement at https://www.unrealengine.com/en-US/eula/unreal
 
License Usage
 
Licensees holding valid licenses to the AUDIOKINETIC Wwise Technology may use
this file in accordance with the end user license agreement provided with the
software or, alternatively, in accordance with the terms contained
in a written agreement between you and Audiokinetic Inc.
Copyright (c) 2022 Audiokinetic Inc.
*******************************************************************************/

#include "Wwise/CookedData/WwiseSwitchContainerLeafCookedData.h"

FWwiseSwitchContainerLeafCookedData::FWwiseSwitchContainerLeafCookedData():
	GroupValueSet(),
	SoundBanks(),
	Media(),
	ExternalSources()
{}

void FWwiseSwitchContainerLeafCookedData::Serialize(FArchive& Ar)
{
	UStruct* Struct = StaticStruct();
	check(Struct);

	if (Ar.WantBinaryPropertySerialization())
	{
		Struct->SerializeBin(Ar, this);
	}
	else
	{
		Struct->SerializeTaggedProperties(Ar, (uint8*)this, Struct, nullptr);
	}
}

bool FWwiseSwitchContainerLeafCookedData::operator==(const FWwiseSwitchContainerLeafCookedData& Rhs) const
{
	if (GroupValueSet.Num() != Rhs.GroupValueSet.Num())
	{
		return false;
	}
	for (const auto& Elem : GroupValueSet)
	{
		if (!Rhs.GroupValueSet.Contains(Elem))
		{
			return false;
		}
	}
	return true;
}