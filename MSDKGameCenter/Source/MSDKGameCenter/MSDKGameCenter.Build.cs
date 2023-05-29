// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System;
using System.IO;

public class MSDKGameCenter : ModuleRules
{
	public MSDKGameCenter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

#if UE_4_20_OR_LATER
		// ue 4.20 or later do not need PublicIncludePaths
#else

		PublicIncludePaths.AddRange(
			new string[] {
				"MSDKGameCenter/Public"
				// ... add public include paths required here ...
			}
			);
#endif
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"MSDKGameCenter/Private",
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
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

		if (Target.Platform == UnrealTargetPlatform.Android) {
			//Add Android
			PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });
			string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);

#if UE_4_20_OR_LATER
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "MSDKGameCenter_UPL.xml"));
#else
			AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(PluginPath, "MSDKGameCenter_UPL.xml")));
#endif

            System.Console.WriteLine("MSDK APL Path = " + Path.Combine(PluginPath, "MSDKGameCenter_UPL.xml"));
		} else if (Target.Platform == UnrealTargetPlatform.IOS) {
		    var libPath = Path.GetFullPath(ModuleDirectory);
			System.Console.WriteLine("--------------Add iOS MSDKPlugin:" + libPath);
            //IOSStart not delete
			#if UE_4_22_OR_LATER 
				PublicAdditionalFrameworks.Add(new Framework("MSDKGameCenter", "lib/iOS/MSDKGameCenter/MSDKGameCenter.embeddedframework.zip", "")); 
			#else 
				PublicAdditionalFrameworks.Add(new UEBuildFramework("MSDKGameCenter", "lib/iOS/MSDKGameCenter/MSDKGameCenter.embeddedframework.zip", "")); 
			#endif
			//IOSEnd
			PublicFrameworks.AddRange(new string[] { "GameKit" });
#if UE_4_24_OR_LATER
			PublicSystemLibraries.AddRange(new string[] {  });
#else
			PublicAdditionalLibraries.AddRange(new string[] {  });
#endif
		}
	}
}
