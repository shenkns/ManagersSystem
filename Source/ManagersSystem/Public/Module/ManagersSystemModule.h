// Copyright shenkns Managers System Developed With Unreal Engine. All Rights Reserved 2022.

#pragma once

MANAGERSSYSTEM_API DECLARE_LOG_CATEGORY_EXTERN(LogManagersSystem, Log, All);

class FManagersSystemModule : public IModuleInterface
{
public:

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
private:

#if UE_EDITOR
	// Init Managers Configuration
	void RegisterSystemSettings() const;
	void UnregisterSystemSettings() const;
#endif
};
