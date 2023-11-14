// Copyright shenkns Managers System Developed With Unreal Engine. All Rights Reserved 2023.

#include "Managers/Manager.h"

#include "Log.h"
#include "ManagersSystem.h"
#include "Log/Details/LocalLogCategory.h"
#include "Module/ManagersSystemModule.h"

DEFINE_LOG_CATEGORY_LOCAL(LogManagersSystem);

void UManager::InitManager()
{
	LOG(Display, "%s Initialization", *GetName());
	
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
