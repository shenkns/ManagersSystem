// Copyright shenkns Managers System Developed With Unreal Engine. All Rights Reserved 2022.

#include "Module/ManagersSystemModule.h"

#include "Module/ManagersSystemSettings.h"
#include "LogSystem.h"

#if UE_EDITOR
#include "ISettingsModule.h"
#endif

IMPLEMENT_MODULE(FManagersSystemModule, ManagersSystem)

MANAGERSSYSTEM_API DEFINE_LOG_CATEGORY(LogManagersSystem);

void FManagersSystemModule::StartupModule()
{
#if UE_EDITOR
	RegisterSystemSettings();
#endif
}

void FManagersSystemModule::ShutdownModule()
{
#if UE_EDITOR
	UnregisterSystemSettings();
#endif
}
#if UE_EDITOR
void FManagersSystemModule::RegisterSystemSettings() const
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings(
			"Project",
			"Plugins",
			"Managers System",
			FText::FromString(TEXT("Managers System")),
			FText::FromString(TEXT("Configuration settings for Managers System")),
			GetMutableDefault<UManagersSystemSettings>()
		);

		LOG_STATIC(LogManagersSystemSettings, "Managers System Settings Registered")
	}
}

void FManagersSystemModule::UnregisterSystemSettings() const
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "Managers System");

		LOG_STATIC(LogManagersSystemSettings, "Managers System Settings Unregistered")
	}
}
#endif
