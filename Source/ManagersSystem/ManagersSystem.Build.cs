// Copyright shenkns Managers System Developed With Unreal Engine. All Rights Reserved 2022.

using UnrealBuildTool;

public class ManagersSystem : ModuleRules
{
	public ManagersSystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		CppStandard = CppStandardVersion.Cpp17;

		PrivateIncludePaths.AddRange(
			new string[] 
			{
				"ManagersSystem/Public/"
			}
		);

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core"
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"LogSystem",
				"SerializationSystem"
			}
		);
		
		PrivateIncludePathModuleNames.AddRange(
			new string[]
			{
				"LogSystem",
				"SerializationSystem"
			}
		);
	}
}
