// Copyright shenkns Managers System Developed With Unreal Engine. All Rights Reserved 2023.

#include "ManagersSystem.h"

#include "Log.h"
#include "Module/ManagersSystemModule.h"
#include "Log/Details/LocalLogCategory.h"
#include "Module/ManagersSystemSettings.h"

DEFINE_LOG_CATEGORY_LOCAL(LogManagersSystem);

UManagersSystem* UManagersSystem::Get()
{
	if(!GEngine) return nullptr;

	if(const UWorld* World = GEngine->GetWorld())
	{
		if(const UGameInstance* GameInstance = World->GetGameInstance())
		{
			return GameInstance->GetSubsystem<UManagersSystem>();
		}
	}

	return nullptr;
}

UManagersSystem* UManagersSystem::GetWithContext(const UObject* WorldContext)
{
	if(!WorldContext) return nullptr;

	if(const UWorld* World = WorldContext->GetWorld())
	{
		if(const UGameInstance* GameInstance = World->GetGameInstance())
		{
			return GameInstance->GetSubsystem<UManagersSystem>();
		}
	}

	return nullptr;
}

void UManagersSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	LOG(Display, "Managers System Initialization");

	InitializeManagers();
}

void UManagersSystem::InitializeManagers()
{
	// Managers Initialization

	// Validate ProfileSystem Settings
	const UManagersSystemSettings* Settings = GetDefault<UManagersSystemSettings>();
	if(!Settings) return;

	for(TSoftClassPtr<UManager> ManagerSoftClass : Settings->DefaultManagers)
	{
		UClass* ManagerClass = ManagerSoftClass.LoadSynchronous();
		if(!ManagerClass) continue;
		
		if(GetManager(ManagerClass)) continue;

		UManager* Manager = NewObject<UManager>(this, ManagerClass);
		
		Managers.Add(Manager);
	}

	for(const UManager* TemplateManager : Settings->Managers)
	{
		if(!TemplateManager) continue;
		if(GetManager(TemplateManager->GetClass())) continue;

		UManager* Manager = DuplicateObject<UManager>(TemplateManager, this);
		
		Managers.Add(Manager);
	}

	for(UManager* Manager : Managers)
	{
		Manager->InitManager();
	}
}

// Profile Manager Getter
UManager* UManagersSystem::GetManager(TSubclassOf<UManager> Class) const
{
	if(!Class) Class = UManager::StaticClass();
	
	// Find Manager
	UManager* const* Out = Managers.FindByPredicate([Class](const UManager* Src)
	{
		return Src && Src->GetClass() == Class;
	});

	return Out ? *Out : nullptr;
}
