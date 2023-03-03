// Copyright shenkns Managers System Developed With Unreal Engine. All Rights Reserved 2022.

#include "Module/ManagersSystemSettings.h"

#include "Libs/SerializationSystemLibrary.h"
#include "LogSystem.h"

MANAGERSSYSTEM_API DEFINE_LOG_CATEGORY(LogManagersSystemSettings);

void UManagersSystemSettings::PostInitProperties()
{
	Super::PostInitProperties();
	
	Managers = USerializationSystemLibrary::ConvertSaveDataToObjects<UManager>(ManagersSaveData, this);

	LOG(LogTemp, "Managers Objects Settings Loaded")
}

#if UE_EDITOR
void UManagersSystemSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if(CastField<FArrayProperty>(PropertyChangedEvent.MemberProperty))
	{
		USerializationSystemLibrary::ConvertObjectsToSaveData<UManager>(Managers, ManagersSaveData);

		SaveSettings();

		LOG(LogManagersSystemSettings, "Profile Objects Settings Saved To Config")
	}
}
#endif

void UManagersSystemSettings::SaveSettings()
{
	SaveConfig(CPF_Config, *GetDefaultConfigFilename(), new FConfigCacheIni(EConfigCacheType::DiskBacked), true);
	TryUpdateDefaultConfigFile();
}
