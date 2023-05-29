// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;
using System;

public class TssSDK : ModuleRules
{
	public TssSDK(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
#if UE_4_20_OR_LATER
		// ue 4.20 or later do not need PublicIncludePaths
#else
	PublicIncludePaths.AddRange(
			new string[] {
				"TssSDK/Public"
				// ... add public include paths required here ...
			}
			);
#endif
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"TssSDK/Private",
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
		//=======

		string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
		string TssPartyDir = Path.GetFullPath(Path.Combine(ModuleDirectory, "../TssSDKLib"));

		System.Console.WriteLine("----PluginPath = " + PluginPath);

		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });
			string aplPath = Path.Combine(PluginPath, "TssSDK_APL.xml");
#if UE_4_20_OR_LATER
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", aplPath);
#else
			AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", aplPath));
#endif

			//
			string libPath = TssPartyDir + "/Android/libs";

			//TssPartyDir + "/Android/libs/armeabi-v7a/libanogs.so";

			string archDir = "armeabi-v7a";
			string archLibPath = Path.Combine(libPath, archDir);
			System.Console.WriteLine("----PluginPath = " + archLibPath);
#if UE_4_24_OR_LATER
			PublicAdditionalLibraries.Add(Path.Combine(archLibPath,"libanogs.so"));
#else
			PublicLibraryPaths.Add(archLibPath);
			PublicAdditionalLibraries.Add("anogs");
#endif
			

			archDir = "arm64-v8a";
			archLibPath = Path.Combine(libPath, archDir);
			System.Console.WriteLine("----PluginPath = " + archLibPath);
#if UE_4_24_OR_LATER
			PublicAdditionalLibraries.Add(Path.Combine(archLibPath,"libanogs.so"));
#else
			PublicLibraryPaths.Add(archLibPath);
			PublicAdditionalLibraries.Add("anogs");
#endif

			archDir = "x86";
			archLibPath = Path.Combine(libPath, archDir);
			System.Console.WriteLine("----PluginPath = " + archLibPath);
#if UE_4_24_OR_LATER
			PublicAdditionalLibraries.Add(Path.Combine(archLibPath,"libanogs.so"));
#else
			PublicLibraryPaths.Add(archLibPath);
			PublicAdditionalLibraries.Add("anogs");
#endif

			archDir = "x86_64";
			archLibPath = Path.Combine(libPath, archDir);
			System.Console.WriteLine("----PluginPath = " + archLibPath);
#if UE_4_24_OR_LATER
			PublicAdditionalLibraries.Add(Path.Combine(archLibPath,"libanogs.so"));
#else
			PublicLibraryPaths.Add(archLibPath);
			PublicAdditionalLibraries.Add("anogs");
#endif


		}
		else if (Target.Platform == UnrealTargetPlatform.IOS)
		{
            System.Console.WriteLine("--------------Add iOS TSS");
			#if UE_4_22_OR_LATER 
				PublicAdditionalFrameworks.Add(new Framework("anogs", "../TssSDKLib/iOS/anogs.embeddedframework.zip", "")); 
			#else 
				PublicAdditionalFrameworks.Add(new UEBuildFramework("anogs", "../TssSDKLib/iOS/anogs.embeddedframework.zip", "")); 
			#endif

            PublicFrameworks.AddRange(
                new string[] {
                    "SystemConfiguration",
                    "MobileCoreServices",
                    "Security",
                    "CoreImage"
            });
		}


		//======



	}
}
