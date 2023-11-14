// Copyright shenkns Managers System Developed With Unreal Engine. All Rights Reserved 2023.

#include "Module/ManagersSystemSettings.h"

#include "Log.h"
#include "Libs/SerializationSystemLibrary.h"
#include "Log/Details/LocalLogCategory.h"

MANAGERSSYSTEM_API DEFINE_LOG_CATEGORY(LogManagersSystemSettings);
DEFINE_LOG_CATEGORY_LOCAL(LogManagersSystemSettings);

void UManagersSystemSettings::PostInitProperties()
{
	Super::PostInitProperties();
	
	Managers = USerializationSystemLibrary::ConvertSaveDataToObjects<UManager>(ManagersSaveData, this);

	LOG(Display, "Managers Objects Settings Loaded");
}

#if UE_EDITOR
void UManagersSystemSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if(CastField<FArrayProperty>(PropertyChangedEvent.MemberProperty))
	{
		USerializationSystemLibrary::ConvertObjectsToSaveData<UManager>(Managers, ManagersSaveData);

		SaveSettings();

		LOG(Display, "Profile Objects Settings Saved To Config");
	}
}
#endif

void UManagersSystemSettings::SaveSettings()
{
	SaveConfig(CPF_Config, *GetDefaultConfigFilename(), new FConfigCacheIni(EConfigCacheType::DiskBacked), true);
	UpdateDefaultConfigFile();
}
