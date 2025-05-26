// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Otus : ModuleRules
{
	public Otus(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateDependencyModuleNames.AddRange(new string[] { "WeaponModule", "WeaponPlugin" });
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange([
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput"
		]);
		
		if (Target.bBuildEditor)
		{
			PrivateDependencyModuleNames.AddRange([
				"UnrealEd",
				"EditorSubsystem",
				"Slate",
				"SlateCore"
			]);
		}
	}
}
