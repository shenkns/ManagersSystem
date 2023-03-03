// Copyright shenkns Managers System Developed With Unreal Engine. All Rights Reserved 2022.

#include "Managers/Manager.h"

#include "ManagersSystem.h"
#include "LogSystem.h"
#include "Module/ManagersSystemSettings.h"

void UManager::InitManager()
{
	DEBUG_MESSAGE(GetDefault<UManagersSystemSettings>()->bShowDebugMessages, LogManagersSystem, "%s Initialization", *GetName())
	
	Init();
}

// World Override
UWorld* UManager::GetWorld() const
{
	if (IsTemplate()) return nullptr;

	if(UWorld* GEngineWorld = GEngine->GetCurrentPlayWorld())
	{
		return GEngineWorld;
	}
    
	return IsValid(GetOuter()) ? GetOuter()->GetWorld() : nullptr;
}

UManagersSystem* UManager::GetManagerSystem() const
{
	return Cast<UManagersSystem>(GetOuter());
}
