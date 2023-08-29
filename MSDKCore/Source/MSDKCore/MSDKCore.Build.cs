// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System;
using System.IO;
using System.Collections.Generic;

public class MSDKCore : ModuleRules
{
	public MSDKCore(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

#if UE_4_20_OR_LATER
		// ue 4.20 or later do not need PublicIncludePaths
#else

		PublicIncludePaths.AddRange(
			new string[] {
				"MSDKCore/Public"
				// ... add public include paths required here ...
			}
			);
#endif
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"MSDKCore/Private",
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
				"HTTP", 
				"Json", 
				"JsonUtilities",
				"Projects"
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
#if UE_4_20_OR_LATER
        PublicDefinitions.Add("MSDK_CORE=1");
#else
		Definitions.Add("MSDK_CORE=1");
#endif	
		//Delete pthread files build for PC to prevent the conflict with the Mobile platform
		System.Console.WriteLine("--------------Delete pthread&sched&semaphore");
		string pcHeadersDir = Path.GetFullPath(Path.Combine(ModuleDirectory, "Public"));
		string pthreadHeaderPath = Path.GetFullPath(Path.Combine(pcHeadersDir, "pthread.h"));
		string schedHeaderPath = Path.GetFullPath(Path.Combine(pcHeadersDir, "sched.h"));
		string semaphoreHeaderPath = Path.GetFullPath(Path.Combine(pcHeadersDir, "semaphore.h"));
		try {
				if (File.Exists(pthreadHeaderPath)) {
					System.Console.WriteLine("Delete pthread.h");
					//File.Delete(pthreadHeaderPath);
				}
				
				if (File.Exists(schedHeaderPath)) {
					System.Console.WriteLine("Delete sched.h");
					//File.Delete(schedHeaderPath);
				}
				
				if (File.Exists(semaphoreHeaderPath)) {
					System.Console.WriteLine("Delete semaphore.h");
					//File.Delete(semaphoreHeaderPath);
				}
			} catch (IOException e) {
				System.Console.WriteLine("Delete pthread or sched or semaphore exception, err=", e.ToString());
		}

		if (Target.Platform == UnrealTargetPlatform.Android) {
			//Add Android
			PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });
#if UE_4_24_OR_LATER
            PublicSystemLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "lib/Android/msdk-core/libs/armeabi-v7a")));
            PublicSystemLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "lib/Android/msdk-core/libs/arm64-v8a")));
            PublicSystemLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "lib/Android/msdk-core/libs/x86")));
            PublicSystemLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "lib/Android/msdk-core/libs/x86_64")));
#else
            PublicLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "lib/Android/msdk-core/libs/armeabi-v7a")));
            PublicLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "lib/Android/msdk-core/libs/arm64-v8a")));
            PublicLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "lib/Android/msdk-core/libs/x86")));
            PublicLibraryPaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "lib/Android/msdk-core/libs/x86_64")));
#endif
			System.Console.WriteLine("--------------Add Android MSDKCore");
			PublicAdditionalLibraries.Add("MSDKCore");
			string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
#if UE_4_20_OR_LATER
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "MSDKCore_UPL.xml"));
#else
			AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(PluginPath, "MSDKCore_UPL.xml")));
#endif
            System.Console.WriteLine("MSDK APL Path = " + Path.Combine(PluginPath, "MSDKCore_UPL.xml"));
		} else if (Target.Platform == UnrealTargetPlatform.IOS) {
			System.Console.WriteLine("--------------Add iOS MSDKPlugin");
            //IOSStart not delete
			#if UE_4_22_OR_LATER 
				PublicAdditionalFrameworks.Add(new Framework("MSDKSensitivity", "lib/iOS/MSDKCore/MSDKSensitivity.embeddedframework.zip", "")); 
			#else 
				PublicAdditionalFrameworks.Add(new UEBuildFramework("MSDKSensitivity", "lib/iOS/MSDKCore/MSDKSensitivity.embeddedframework.zip", "")); 
			#endif
			#if UE_4_22_OR_LATER 
				PublicAdditionalFrameworks.Add(new Framework("MSDKCore", "lib/iOS/MSDKCore/MSDKCore.embeddedframework.zip", "MSDKAppSetting.bundle")); 
			#else 
				PublicAdditionalFrameworks.Add(new UEBuildFramework("MSDKCore", "lib/iOS/MSDKCore/MSDKCore.embeddedframework.zip", "MSDKAppSetting.bundle")); 
			#endif
			//IOSEnd
			PublicFrameworks.AddRange(new string[] { "CoreTelephony", "AdSupport", "Security", "GameKit", "UserNotifications", "WebKit", "UIKit", "SystemConfiguration", "AudioToolbox", "Foundation", "CoreMedia" });
#if UE_4_24_OR_LATER
			PublicSystemLibraries.AddRange(new string[] { "z", "sqlite3", "stdc++", "c++" });
#else
			PublicAdditionalLibraries.AddRange(new string[] { "z", "sqlite3", "stdc++", "c++" });
#endif
		} else if (Target.Platform == UnrealTargetPlatform.Win64) {
			System.Console.WriteLine("--------------Add Win64 MSDKPlugin");

			System.Console.WriteLine("--------------Make pthread&sched&semaphore&MSDKCore.cpp");
			string tempPthreadHeaderPath = Path.GetFullPath(Path.Combine(pcHeadersDir, ".msdk_pthread"));
			string tempSchedHeaderPath = Path.GetFullPath(Path.Combine(pcHeadersDir, ".msdk_sched"));
			string tempSemaphoreHeaderPath = Path.GetFullPath(Path.Combine(pcHeadersDir, ".msdk_semaphore"));
			string msdkCoreCppDir = Path.GetFullPath(Path.Combine(ModuleDirectory, "Private"));
			string msdkCoreCppPath = Path.GetFullPath(Path.Combine(msdkCoreCppDir, "MSDKCore.cpp"));
			string tempMsdkCoreCppPath = Path.GetFullPath(Path.Combine(msdkCoreCppDir, ".msdk_core"));
			try {
					if (File.Exists(tempPthreadHeaderPath)) {
						System.Console.WriteLine("Make pthread.h");
						File.Copy(tempPthreadHeaderPath, pthreadHeaderPath, false);
					}
					
					if (File.Exists(tempSchedHeaderPath)) {
						System.Console.WriteLine("Make sched.h");
						File.Copy(tempSchedHeaderPath, schedHeaderPath, false);
					}
					
					if (File.Exists(tempSemaphoreHeaderPath)) {
						System.Console.WriteLine("Make semaphore.h");
						File.Copy(tempSemaphoreHeaderPath, semaphoreHeaderPath, false);
					}

					if (File.Exists(tempMsdkCoreCppPath)) {
						if (File.Exists(msdkCoreCppPath)) {
							System.Console.WriteLine("Delete MSDKCore.cpp");
							File.Delete(msdkCoreCppPath);
						}
						System.Console.WriteLine("Make MSDKCore.cpp");
						File.Copy(tempMsdkCoreCppPath, msdkCoreCppPath, false);
					}
				} catch (IOException e) {
					System.Console.WriteLine("Make pthread or sched or semaphore or MSDKCore.cpp exception, err=" + e.ToString());
			}

#if UE_4_20_OR_LATER
			PublicDefinitions.Add("GCLOUD_MSDK_WINDOWS=1");
#else
			Definitions.Add("GCLOUD_MSDK_WINDOWS=1");
#endif
			string libraryDir = Path.GetFullPath(Path.Combine(ModuleDirectory, "lib/Win64"));
			PublicAdditionalLibraries.Add(Path.Combine(libraryDir, "MSDKCore.lib"));
			if (!Target.bBuildEditor) {
				PublicDelayLoadDLLs.Add("MSDKCore.dll");
			}

			string moduleBinaryDir = Path.Combine(ModuleDirectory, "../../Binaries", Target.Platform.ToString());
			if (!Directory.Exists(moduleBinaryDir)) {
                Directory.CreateDirectory(moduleBinaryDir);
            }

            Dictionary<string, string> msdkDlls = new Dictionary<string, string>() {
				{"libcrypto-1_1.dll", Path.GetFullPath(Path.Combine(libraryDir, "libcrypto-1_1.dll"))},
            	{"libcurl.dll", Path.GetFullPath(Path.Combine(libraryDir, "libcurl.dll"))},
				{"libssh2.dll", Path.GetFullPath(Path.Combine(libraryDir, "libssh2.dll"))},
				{"MSDKCore.dll", Path.GetFullPath(Path.Combine(libraryDir, "MSDKCore.dll"))},
                {"libssl-1_1.dll", Path.GetFullPath(Path.Combine(libraryDir, "libssl-1_1.dll"))},
                {"pthreadGC2.dll", Path.GetFullPath(Path.Combine(libraryDir, "pthreadGC2.dll"))},
                {"pthreadVC2.dll", Path.GetFullPath(Path.Combine(libraryDir, "pthreadVC2.dll"))},
                {"steam_api64.dll", Path.GetFullPath(Path.Combine(libraryDir, "steam_api64.dll"))},
                {"zlibwapi.dll", Path.GetFullPath(Path.Combine(libraryDir, "zlibwapi.dll"))},


                // webview related
                {"msvcr100.dll", Path.GetFullPath(Path.Combine(libraryDir, "msvcr100.dll"))},
                {"libcef_msdk.dll", Path.GetFullPath(Path.Combine(libraryDir, "libcef_msdk.dll"))},
                {"libGLESv2.dll", Path.GetFullPath(Path.Combine(libraryDir, "libGLESv2.dll"))},
                {"libEGL.dll", Path.GetFullPath(Path.Combine(libraryDir, "libEGL.dll"))},
                {"d3dcompiler_47.dll", Path.GetFullPath(Path.Combine(libraryDir, "d3dcompiler_47.dll"))},
                {"chrome_elf.dll", Path.GetFullPath(Path.Combine(libraryDir, "chrome_elf.dll"))},
                {"WebView2Loader.dll", Path.GetFullPath(Path.Combine(libraryDir, "WebView2Loader.dll"))},
                {"MSDKUnityAdapter.dll", Path.GetFullPath(Path.Combine(libraryDir, "MSDKUnityAdapter.dll"))},
                {"MSDKCefWebView.dll", Path.GetFullPath(Path.Combine(libraryDir, "MSDKCefWebView.dll"))},
                {"EOSSDK-Win64-Shipping.dll", Path.GetFullPath(Path.Combine(libraryDir, "EOSSDK-Win64-Shipping.dll"))}

            };
            try {
                foreach (KeyValuePair<string, string> msdkDll in msdkDlls) {
					if (Target.bBuildEditor) {
						File.Copy(msdkDll.Value, Path.Combine(moduleBinaryDir, msdkDll.Key), true);
					}
#if UE_4_20_OR_LATER
					RuntimeDependencies.Add(msdkDll.Value);
#else
					RuntimeDependencies.Add(new RuntimeDependency(msdkDll.Value));
#endif
                }
            } catch (Exception e) {
                System.Console.WriteLine("MSDKPC copy dll exception, maybe the file already exists and be occupied, err=" + e.ToString());
            }

			Dictionary<string, string> msdkResources = new Dictionary<string, string>() {
				{"cacert.pem", Path.GetFullPath(Path.Combine(libraryDir, "cacert.pem"))},
				{"MSDKConfig.ini", Path.GetFullPath(Path.Combine(libraryDir, "MSDKConfig.ini"))},
				{"MSDKRetMsg.json", Path.GetFullPath(Path.Combine(libraryDir, "MSDKRetMsg.json"))},
				{"steam_appid.txt", Path.GetFullPath(Path.Combine(libraryDir, "steam_appid.txt"))},
				{"MSDKCore.pdb", Path.GetFullPath(Path.Combine(libraryDir, "MSDKCore.pdb"))},

				// webview related
				{"v8_context_snapshot.bin", Path.GetFullPath(Path.Combine(libraryDir, "v8_context_snapshot.bin"))},
				{"snapshot_blob.bin", Path.GetFullPath(Path.Combine(libraryDir, "snapshot_blob.bin"))},
				{"icudtl.dat", Path.GetFullPath(Path.Combine(libraryDir, "icudtl.dat"))},
				{"devtools_resources.pak", Path.GetFullPath(Path.Combine(libraryDir, "devtools_resources.pak"))},
				{"cef_extensions.pak", Path.GetFullPath(Path.Combine(libraryDir, "cef_extensions.pak"))},
				{"cef_200_percent.pak", Path.GetFullPath(Path.Combine(libraryDir, "cef_200_percent.pak"))},
				{"cef_100_percent.pak", Path.GetFullPath(Path.Combine(libraryDir, "cef_100_percent.pak"))},
				{"cef.pak", Path.GetFullPath(Path.Combine(libraryDir, "cef.pak"))},
				{"MSDKWebViewRender.pdb", Path.GetFullPath(Path.Combine(libraryDir, "MSDKWebViewRender.pdb"))},
				{"MSDKWebViewRender.exe", Path.GetFullPath(Path.Combine(libraryDir, "MSDKWebViewRender.exe"))},
				{"MSDKCefWebView.pdb", Path.GetFullPath(Path.Combine(libraryDir, "MSDKCefWebView.pdb"))}

			};
			try {
					foreach (KeyValuePair<string, string> msdkResource in msdkResources) {
							if (Target.bBuildEditor) {
								File.Copy(msdkResource.Value, Path.Combine(moduleBinaryDir, msdkResource.Key), true);
							}
#if UE_4_20_OR_LATER
							RuntimeDependencies.Add(msdkResource.Value);
#else
							RuntimeDependencies.Add(new RuntimeDependency(msdkResource.Value));
#endif
					}
			} catch (Exception e) {
					System.Console.WriteLine("MSDKPC copy res exception, maybe the file already exists and be occupied, err=" + e.ToString());
			}


			// Copy directory
			Dictionary<string, string> directories = new Dictionary<string, string>() {
					{"locales", Path.GetFullPath(Path.Combine(libraryDir, "locales"))}
			};

			try
			{
					foreach(KeyValuePair<string, string> dir in directories)
					{
							if (Target.bBuildEditor)
							{
									CopyDirectory(dir.Value, moduleBinaryDir);
							}
							AddRuntimeDependencies(dir.Value);
					}
			} catch (Exception e) {
					System.Console.WriteLine("MSDKPC copy plugin sub directory failed, err = " + e.ToString());
			}

			System.Console.WriteLine("--------------Add Win64 MSDKPlugin done");
		}
	}

	private void CopyDirectory(string sourcePath, string destPath)
	{
			string floderName = Path.GetFileName(sourcePath);
			DirectoryInfo di = Directory.CreateDirectory(Path.Combine(destPath, floderName));
			string[] files = Directory.GetFileSystemEntries(sourcePath);

			foreach (string file in files)
			{
					if (Directory.Exists(file))
					{
							CopyDirectory(file, di.FullName);
					}
					else
					{
							File.Copy(file, Path.Combine(di.FullName, Path.GetFileName(file)), true);
					}
			}
	}

	private void AddRuntimeDependencies(string directory)
	{
			string[] files = Directory.GetFileSystemEntries(directory);
			foreach(string file in files)
			{
					if (Directory.Exists(file))
					{
							AddRuntimeDependencies(file);
					}
					else
					{
							System.Console.WriteLine("--------------AddRuntimeDependencies file: " + file);

#if UE_4_20_OR_LATER
			RuntimeDependencies.Add(file);
#else
							RuntimeDependencies.Add(new RuntimeDependency(file));
#endif
					}
			}
	}

}
