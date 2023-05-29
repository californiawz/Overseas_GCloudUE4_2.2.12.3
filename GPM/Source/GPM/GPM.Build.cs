// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
// Created and edited by vincentwgao.com


using UnrealBuildTool;
using System.IO;
using System;
public class GPM : ModuleRules
{
#if WITH_FORWARDED_MODULE_RULES_CTOR
		public GPM(ReadOnlyTargetRules Target) : base(Target)
#else
		public GPM(TargetInfo Target)
#endif
    {
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
#if UE_4_20_OR_LATER
			PublicDefinitions.Add("USE_TGPA_DYNAMIC");
#else
            Definitions.Add("USE_TGPA_DYNAMIC");
#endif

#if UE_4_20_OR_LATER
        // ue 4.20 or later do not need PublicIncludePaths
#else
        PublicIncludePaths.AddRange(
            new string[] {
                "GPM/Public"
				// ... add public include paths required here ...
			}
            );
#endif

        PrivateIncludePaths.AddRange(
            new string[] {
                "GPM/Private"
				// ... add other private include paths required here ...
			}
            );


        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
				"Slate",
				"SlateCore",
				// ... add other public dependencies that you statically link with here ...
                //"UMG",
            }
            );

        if (Target.Platform == UnrealTargetPlatform.IOS ||
            Target.Platform == UnrealTargetPlatform.Mac)
        {
            PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
				// ... add private dependencies that you statically link with here ...	
			}
            );
        }
        else
        {
            PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",              
				// ... add private dependencies that you statically link with here ...	

            }
            );
        }
        if (Target.Type == TargetRules.TargetType.Editor)
        {

            DynamicallyLoadedModuleNames.AddRange(
                        new string[] {
                    "Settings",
                    }
                    );

            PrivateIncludePathModuleNames.AddRange(
                new string[] {
                    "Settings",
            }
            );
        }



        if (Target.Platform == UnrealTargetPlatform.Android)
        {
            PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });

            string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
            string aplPath = Path.Combine(PluginPath, "GPM_APL.xml");
            System.Console.WriteLine("GPM APL PATH : " + aplPath);

#if UE_4_20_OR_LATER
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", aplPath);
#else
            AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", aplPath));
#endif

            string GPMRootLibDir = Path.GetFullPath(Path.Combine(ModuleDirectory, "../GPMSDKLib/Android/libs"));
            System.Console.WriteLine("--------------Android GPMLibPath = " + GPMRootLibDir);
#if UE_4_24_OR_LATER
            PublicSystemLibraryPaths.Add(Path.Combine(GPMRootLibDir, "armeabi-v7a"));
            PublicAdditionalLibraries.Add(Path.Combine(GPMRootLibDir, "armeabi-v7a/libGPM.so"));
            PublicSystemLibraryPaths.Add(Path.Combine(GPMRootLibDir, "arm64-v8a"));
            PublicAdditionalLibraries.Add(Path.Combine(GPMRootLibDir, "arm64-v8a/libGPM.so"));
            PublicSystemLibraryPaths.Add(Path.Combine(GPMRootLibDir, "x86"));
            PublicAdditionalLibraries.Add(Path.Combine(GPMRootLibDir, "x86/libGPM.so"));
            PublicSystemLibraryPaths.Add(Path.Combine(GPMRootLibDir, "x86_64"));
            PublicAdditionalLibraries.Add(Path.Combine(GPMRootLibDir, "x86_64/libGPM.so"));
#else
			PublicLibraryPaths.Add(Path.GetFullPath(Path.Combine(GPMRootLibDir, "armeabi-v7a")));
            PublicLibraryPaths.Add(Path.GetFullPath(Path.Combine(GPMRootLibDir, "arm64-v8a")));
            PublicLibraryPaths.Add(Path.GetFullPath(Path.Combine(GPMRootLibDir, "x86")));
            PublicLibraryPaths.Add(Path.GetFullPath(Path.Combine(GPMRootLibDir, "x86_64")));
#endif

#if UE_4_24_OR_LATER
#else
            PublicAdditionalLibraries.Add("GPM");
#endif
        }
        else if (Target.Platform == UnrealTargetPlatform.IOS)
        {

#if UE_4_24_OR_LATER
            PublicSystemLibraries.AddRange(
				new string[] {
				 "z","c++","z.1.1.3","sqlite3","xml2","resolv"
			});
#else
		    PublicAdditionalLibraries.AddRange(
                new string[] {
                "z","c++","z.1.1.3","sqlite3","xml2","resolv"
            });
#endif
                // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
                PublicFrameworks.AddRange(
                    new string[] {
                        "CoreTelephony",
                        "Foundation",
                        "MobileCoreServices",
                        "CoreData",
                        "CoreText",
                        "Security",
                        "ImageIO",
                        "StoreKit",
                        "AdSupport",
                        "JavaScriptCore",
                        "CoreLocation",
                        "SystemConfiguration",
                        "UIKit",
                        "CoreGraphics",
                        "CFNetwork",
                        "Security",
                        "QuartzCore",
                        "UIKit"
                    });
                        
                PublicWeakFrameworks.AddRange(
                        new string[] {
                        "CoreHaptics",
                        "MetricKit"
                        });


            //PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "../GPMSDKLib/iOS", "libTuringShield.a"));


             #if UE_4_22_OR_LATER
                PublicAdditionalFrameworks.Add(new Framework("GPM_dylib", "../GPMSDKLib/iOS/GPM_dylib.embeddedframework.zip"));
                PublicAdditionalFrameworks.Add( new Framework("kgvmp_dy", "../GPMSDKLib/iOS/kgvmp_dy.embeddedframework.zip"));

            #else
                PublicAdditionalFrameworks.Add( new UEBuildFramework("GPM_dylib", "../GPMSDKLib/iOS/GPM_dylib.embeddedframework.zip"));
                PublicAdditionalFrameworks.Add( new UEBuildFramework("kgvmp_dy", "../GPMSDKLib/iOS/kgvmp_dy.embeddedframework.zip"));

            #endif
          
        }


    }
}
