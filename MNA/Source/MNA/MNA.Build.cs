// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;
using System;

public class MNA : ModuleRules
{
    public MNA(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
                "DeveloperSettings",
                // ... add other public dependencies that you statically link with here ...
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                // ... add private dependencies that you statically link with here ...
            }
            );

        PublicIncludePathModuleNames.AddRange(
            new string[]
            {
                    "Core",
            }
        );

        PrivateIncludePathModuleNames.AddRange(
            new string[]
            {
                    "Core",
                //"UnrealEd",
            }
        );

#if UE_4_20_OR_LATER
        // ue 4.20 or later do not need PublicIncludePaths
#else
        PublicIncludePaths.AddRange(
            new string[] {
                "MNA/Public",
                // ... add public include paths required here ...
            }
            );
#endif

        PrivateIncludePaths.AddRange(
            new string[] {
                    "MNA/Private",
                // ... add other private include paths required here ...
            }
            );

        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
                // ... add any modules that your module loads dynamically here ...
            }
            );

        System.Console.WriteLine("MNA ModuleDirectory : " + ModuleDirectory);
        string PluginPath = ModuleDirectory;
        System.Console.WriteLine("MNA PluginPath : " + PluginPath);
        if (Target.Platform == UnrealTargetPlatform.Android)
        {
            PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                    "Launch",
                    "ApplicationCore",
            }
            );
#if UE_4_20_OR_LATER
                AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "MNA_APL.xml"));
#else
            AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(PluginPath, "MNA_APL.xml")));
#endif

            string MNARootLibDir = Path.Combine(PluginPath, "MNA/Android");
            System.Console.WriteLine("MNA MNARootLibDir : " + MNARootLibDir);
#if UE_4_24_OR_LATER
                PublicSystemLibraryPaths.Add(Path.Combine(MNARootLibDir, "armeabi-v7a"));
                PublicSystemLibraryPaths.Add(Path.Combine(MNARootLibDir, "arm64-v8a"));
                PublicSystemLibraryPaths.Add(Path.Combine(MNARootLibDir, "x86"));
                PublicSystemLibraryPaths.Add(Path.Combine(MNARootLibDir, "x86_64"));
#else
            PublicLibraryPaths.Add(Path.Combine(MNARootLibDir, "armeabi-v7a"));
            PublicLibraryPaths.Add(Path.Combine(MNARootLibDir, "arm64-v8a"));
            PublicLibraryPaths.Add(Path.Combine(MNARootLibDir, "x86"));
            PublicLibraryPaths.Add(Path.Combine(MNARootLibDir, "x86_64"));
#endif
            PublicAdditionalLibraries.Add("gsdk");
        }
        else if (Target.Platform == UnrealTargetPlatform.IOS)
        {
            PublicIncludePaths.AddRange(new string[] { "Runtime/ApplicationCore/Public/Apple", "Runtime/ApplicationCore/Public/IOS" });
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
                        "OpenGLES"
                });

#if UE_4_22_OR_LATER
                PublicAdditionalFrameworks.Add(
                    new Framework("MNA",
                        "MNA/IOS/C11/MNA.embeddedframework.zip", // Zip name
                        ""));
#else
            PublicAdditionalFrameworks.Add(
                new UEBuildFramework("MNA",
                    "MNA/IOS/C11/MNA.embeddedframework.zip", // Zip name
                    ""));
#endif
        }
    }
}
