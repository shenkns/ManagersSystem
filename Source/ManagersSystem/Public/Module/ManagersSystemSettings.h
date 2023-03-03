// Copyright shenkns Managers System Developed With Unreal Engine. All Rights Reserved 2022.

#pragma once

#include "UObject/Object.h"

#include "UObject/SoftObjectPtr.h"
#include "Libs/SerializationSystemLibrary.h"

#include "ManagersSystemSettings.generated.h"

class UManager;

MANAGERSSYSTEM_API DECLARE_LOG_CATEGORY_EXTERN(LogManagersSystemSettings, Log, All);

UCLASS(Config=Game, DefaultConfig)
class MANAGERSSYSTEM_API UManagersSystemSettings : public UObject
{
	GENERATED_BODY()

public:

	// Configuration For Managers System

	// Managers
	UPROPERTY(EditDefaultsOnly, Instanced, Category = "Managers")
	TArray<UManager*> Managers;
	
	UPROPERTY(EditDefaultsOnly, Config, Category = "Managers")
	TArray<TSoftClassPtr<UManager>> DefaultManagers;

	UPROPERTY(Config)
	TArray<FObjectSaveData> ManagersSaveData;

	// Debug
	UPROPERTY(Config, EditDefaultsOnly, Category = "Debug")
	bool bShowDebugMessages;

public:

	virtual void PostInitProperties() override;

#if UE_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	void SaveSettings();
};
