// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System;
using System.IO;

public class MSDKFacebook : ModuleRules
{
	public MSDKFacebook(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

#if UE_4_20_OR_LATER
		// ue 4.20 or later do not need PublicIncludePaths
#else

		PublicIncludePaths.AddRange(
			new string[] {
				"MSDKFacebook/Public"
				// ... add public include paths required here ...
			}
			);
#endif
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"MSDKFacebook/Private",
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
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "MSDKFacebook_UPL.xml"));
#else
			AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(PluginPath, "MSDKFacebook_UPL.xml")));
#endif

            System.Console.WriteLine("MSDK APL Path = " + Path.Combine(PluginPath, "MSDKFacebook_UPL.xml"));
		} else if (Target.Platform == UnrealTargetPlatform.IOS) {
		    var libPath = Path.GetFullPath(ModuleDirectory);
			System.Console.WriteLine("--------------Add iOS MSDKPlugin:" + libPath);
            //IOSStart not delete
			#if UE_4_22_OR_LATER 
				PublicAdditionalFrameworks.Add(new Framework("MSDKFacebook", "lib/iOS/MSDKFacebook/MSDKFacebook.embeddedframework.zip", "")); 
			#else 
				PublicAdditionalFrameworks.Add(new UEBuildFramework("MSDKFacebook", "lib/iOS/MSDKFacebook/MSDKFacebook.embeddedframework.zip", "")); 
			#endif
			#if UE_4_22_OR_LATER 
				PublicAdditionalFrameworks.Add(new Framework("FBSDKLoginKit", "lib/iOS/Third/MSDKFacebook/FBSDKLoginKit.embeddedframework.zip", "")); 
			#else 
				PublicAdditionalFrameworks.Add(new UEBuildFramework("FBSDKLoginKit", "lib/iOS/Third/MSDKFacebook/FBSDKLoginKit.embeddedframework.zip", "")); 
			#endif
			#if UE_4_22_OR_LATER 
				PublicAdditionalFrameworks.Add(new Framework("FBSDKShareKit", "lib/iOS/Third/MSDKFacebook/FBSDKShareKit.embeddedframework.zip", "")); 
			#else 
				PublicAdditionalFrameworks.Add(new UEBuildFramework("FBSDKShareKit", "lib/iOS/Third/MSDKFacebook/FBSDKShareKit.embeddedframework.zip", "")); 
			#endif
			#if UE_4_22_OR_LATER 
				PublicAdditionalFrameworks.Add(new Framework("FBAEMKit", "lib/iOS/Third/MSDKFacebook/FBAEMKit.embeddedframework.zip", "")); 
			#else 
				PublicAdditionalFrameworks.Add(new UEBuildFramework("FBAEMKit", "lib/iOS/Third/MSDKFacebook/FBAEMKit.embeddedframework.zip", "")); 
			#endif
			#if UE_4_22_OR_LATER 
				PublicAdditionalFrameworks.Add(new Framework("FBSDKCoreKit", "lib/iOS/Third/MSDKFacebook/FBSDKCoreKit.embeddedframework.zip", "")); 
			#else 
				PublicAdditionalFrameworks.Add(new UEBuildFramework("FBSDKCoreKit", "lib/iOS/Third/MSDKFacebook/FBSDKCoreKit.embeddedframework.zip", "")); 
			#endif
			#if UE_4_22_OR_LATER 
				PublicAdditionalFrameworks.Add(new Framework("FBSDKGamingServicesKit", "lib/iOS/Third/MSDKFacebook/FBSDKGamingServicesKit.embeddedframework.zip", "")); 
			#else 
				PublicAdditionalFrameworks.Add(new UEBuildFramework("FBSDKGamingServicesKit", "lib/iOS/Third/MSDKFacebook/FBSDKGamingServicesKit.embeddedframework.zip", "")); 
			#endif
			#if UE_4_22_OR_LATER 
				PublicAdditionalFrameworks.Add(new Framework("FBSDKCoreKit_Basics", "lib/iOS/Third/MSDKFacebook/FBSDKCoreKit_Basics.embeddedframework.zip", "")); 
			#else 
				PublicAdditionalFrameworks.Add(new UEBuildFramework("FBSDKCoreKit_Basics", "lib/iOS/Third/MSDKFacebook/FBSDKCoreKit_Basics.embeddedframework.zip", "")); 
			#endif
			//IOSEnd
			PublicFrameworks.AddRange(new string[] { "Accelerate" });
#if UE_4_24_OR_LATER
			PublicSystemLibraries.AddRange(new string[] {  });
#else
			PublicAdditionalLibraries.AddRange(new string[] {  });
#endif
		}
	}
}
