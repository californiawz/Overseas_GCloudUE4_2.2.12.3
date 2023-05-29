// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;
using System;

public class CrashSight : ModuleRules
{
    public CrashSight(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

#if UE_4_20_OR_LATER
        // ue 4.20 or later do not need PublicIncludePaths
#else
        PublicIncludePaths.AddRange(
            new string[] {
                "CrashSight/Public",
            }
            );
#endif

        PrivateIncludePaths.AddRange(
            new string[] {
                "CrashSight/Private"
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
            //Add Android
            PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });

#if UE_4_24_OR_LATER
            PublicSystemLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../CrashSightLib/Android/libs/armeabi-v7a")));
            PublicSystemLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../CrashSightLib/Android/libs/arm64-v8a")));
            PublicSystemLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../CrashSightLib/Android/libs/x86")));
            PublicSystemLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../CrashSightLib/Android/libs/x86_64")));
#else
            PublicLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../CrashSightLib/Android/libs/armeabi-v7a")));
            PublicLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../CrashSightLib/Android/libs/arm64-v8a")));
            PublicLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../CrashSightLib/Android/libs/x86")));
            PublicLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../CrashSightLib/Android/libs/x86_64")));
#endif

            System.Console.WriteLine("--------------Add Android CrashSight");
            PublicAdditionalLibraries.Add("CrashSight");

            string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
#if UE_4_20_OR_LATER
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "CrashSight_APL.xml"));
#else
            AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(PluginPath, "CrashSight_APL.xml")));
#endif
            System.Console.WriteLine("CrashSight APL Path = " + Path.Combine(PluginPath, "CrashSight_APL.xml"));

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
                "z","c++","z.1.1.3"
            });
#endif
            // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
            PublicFrameworks.AddRange(
                new string[] {
                    "Foundation",
                    "Security"
                                    });

            PublicWeakFrameworks.AddRange(
            new string[] {
                    "MetricKit"
                });

            PublicAdditionalFrameworks.Add(
            #if UE_4_22_OR_LATER
                new Framework("CrashSight", "../CrashSightLib/iOS/CrashSight.embeddedframework.zip")
            #else
                new UEBuildFramework("CrashSight", "../CrashSightLib/iOS/CrashSight.embeddedframework.zip")
            #endif
            );

            PublicAdditionalFrameworks.Add(
            #if UE_4_22_OR_LATER
                new Framework("CrashSightAdapter", "../CrashSightLib/iOS/CrashSightAdapter.embeddedframework.zip")
            #else
                new UEBuildFramework("CrashSightAdapter", "../CrashSightLib/iOS/CrashSightAdapter.embeddedframework.zip")
            #endif
            );

            PublicAdditionalFrameworks.Add(
            #if UE_4_22_OR_LATER
                new Framework("CrashSightCore", "../CrashSightLib/iOS/CrashSightCore.embeddedframework.zip")
            #else
                new UEBuildFramework("CrashSightCore", "../CrashSightLib/iOS/CrashSightCore.embeddedframework.zip")
            #endif
            );

            PublicAdditionalFrameworks.Add(
            #if UE_4_22_OR_LATER
                new Framework("CrashSightPlugin", "../CrashSightLib/iOS/CrashSightPlugin.embeddedframework.zip")
            #else
                new UEBuildFramework("CrashSightPlugin", "../CrashSightLib/iOS/CrashSightPlugin.embeddedframework.zip")
            #endif
            );

         } else if (Target.Platform == UnrealTargetPlatform.Win64)
         {
            PublicDelayLoadDLLs.Add("CrashSight64.dll");

            // Ensure that the DLL is staged along with the executable
			 #if UE_4_22_OR_LATER
             RuntimeDependencies.Add("$(TargetOutputDir)/...", "$(PluginDir)/Source/CrashSightLib/Win/X86_64/...");
            #else
                // new UEBuildFramework("CrashSightPlugin", "../CrashSightLib/iOS/CrashSightPlugin.embeddedframework.zip")
            #endif
        }
    }
}
