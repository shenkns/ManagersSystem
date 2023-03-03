// Copyright shenkns Managers System Developed With Unreal Engine. All Rights Reserved 2022.

#pragma once

#include "UObject/Object.h"

#include "Manager.generated.h"

class UManagersSystem;

UCLASS(Abstract, Blueprintable, BlueprintType, EditInlineNew, DefaultToInstanced)
class MANAGERSSYSTEM_API UManager : public UObject
{
	GENERATED_BODY()

protected:

	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Profile|Replication")
	//bool Replicated = false;
	
	public:
	
	virtual UWorld* GetWorld() const override;

	virtual void InitManager();

	UFUNCTION(BlueprintPure, Category = "Profile", meta = (CompactNodeTitle = "System"))
	UManagersSystem* GetManagerSystem() const;

protected:


	UFUNCTION(BlueprintImplementableEvent, meta = (BlueprintProtected))
	void Init();
};
