#pragma once

#if PLATFORM_IOS

#ifdef USE_TGPA_DYNAMIC
#import <kgvmp_dy/kgvmp.h>
#else
#import <kgvmp/kgvmp.h>
#endif

#endif

#include "ITGPAService.h"

using namespace GCloud::TGPA;

class TGPAServiceiOS : public ITGPAService 
{
private:
    int fpsCount = 0;
    float fpsTotal = 0;

    FString ConvertTMap2JsonStr (const TMap<FString, FString>& mapData);

public:
    static ITGPACallback *sTGPACallback;

public: 
    TGPAServiceiOS();

    void EnableLog(bool enable);

    void EnableDebugMode();

    void Init();

    void RegisterCallback(ITGPACallback *callback);

    void UpdateGameFps (float value);

    void UpdateGameInfo(const int key, const int value);

    void UpdateGameInfo(const int key, const FString& value);

    void UpdateGameInfo(const FString& key, const FString& value);

    void UpdateGameInfo(const FString& key, const TMap<FString, FString>& mapData);

    FString GetOptCfgStr();
	
    FString CheckDeviceIsReal();

    FString GetDataFromTGPA(const FString& key, const FString& value);

    int CheckHapticPlayerSupport(HapticPlayerType playerType);

    int CheckHapticAmplitudeSupport();

    void SetCurrentHapticPlayerType(HapticPlayerType playerType);

    void HapticPlay(const FString& heJson, int loop, int interval, int amplitude);

    void HapticPlayWithFile(const FString& heFilePath, int loop, int interval, int amplitude);

    void HapticStop();
};


