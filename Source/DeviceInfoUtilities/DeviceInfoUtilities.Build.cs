// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;
public class DeviceInfoUtilities : ModuleRules
{
    private string ModulePath
    {
        get { return ModuleDirectory; }//return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); 
    }
    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty/")); }
    }
    public DeviceInfoUtilities(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicLibraryPaths.Add(Path.Combine(ThirdPartyPath, "DLL"));
        //PublicDelayLoadDLLs.Add("ThirdPartyDLL.dll");
        RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(ThirdPartyPath, "DLL","ThirdPartyDLL.dll")));

        PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "Include"));
        PublicAdditionalLibraries.Add(Path.Combine(ThirdPartyPath, "Lib", "ThirdPartyDLL.lib"));
        PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "Sockets"
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
