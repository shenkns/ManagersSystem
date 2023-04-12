// Copyright shenkns Managers System Developed With Unreal Engine. All Rights Reserved 2022.

#pragma once

#include "Subsystems/GameInstanceSubsystem.h"

#include "Managers/Manager.h"
#include "ManagersSystem.generated.h"

class UManager;

UCLASS(BlueprintType)
class MANAGERSSYSTEM_API UManagersSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

protected:

	UPROPERTY()
	TArray<UManager*> Managers;

public:

	static UManagersSystem* Get();
	static UManagersSystem* Get(UObject* WorldContext);

	// Managers Getters
	UFUNCTION(BlueprintPure, Category = "ManagersSystem", meta = (CompactNodeTitle = "Manager", DeterminesOutputType = "Class"))
	UManager* GetManager(TSubclassOf<UManager> Class) const;
	
	template<typename T>
	T* GetManager() const;
	
protected:
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	void InitializeManagers();
};

template <typename T>
T* UManagersSystem::GetManager() const
{
	// Find Manager
	UManager* const* Out = Managers.FindByPredicate(
		[&](const UManager* Src)
		{
			return Src && Src->GetClass() == T::StaticClass();
		});
	return Out ? static_cast<T*>(*Out) : nullptr;
}
