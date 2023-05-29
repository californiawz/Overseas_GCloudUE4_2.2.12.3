#include "TGPAHelper.h"
#include "ITGPAService.h"

static GCloud::TGPA::ITGPAService *GlobalTGPAService = nullptr;

#if PLATFORM_ANDROID
#include "Android/TGPAServiceAndroid.h"

GCloud::TGPA::ITGPAService *GetTGPAServiceInstance() {
    if (GlobalTGPAService == nullptr) {
        UE_LOG(LogTemp, Warning, TEXT("GetTGPAServiceInstance in Android platform first."));
        GlobalTGPAService = new TGPAServiceAndroid();
    }
    return GlobalTGPAService;
}

#elif PLATFORM_IOS
#include "iOS/TGPAServiceiOS.h"

GCloud::TGPA::ITGPAService *GetTGPAServiceInstance() {
    if (GlobalTGPAService == nullptr) {
        UE_LOG(LogTemp, Warning, TEXT("GetTGPAServiceInstance in iOS platform first."));
        GlobalTGPAService = new TGPAServiceiOS();
    }
    return GlobalTGPAService;
}

#else

GCloud::TGPA::ITGPAService *GetTGPAServiceInstance() { return nullptr; }

#endif

bool IsTGPAServiceAvailable() { return GetTGPAServiceInstance() != nullptr; }

void GCloud::TGPA::TGPAHelper::EnableLog(bool enable) {
    if (IsTGPAServiceAvailable()) {
        GetTGPAServiceInstance()->EnableLog(enable);
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Platform is not available."));
    }
}

void GCloud::TGPA::TGPAHelper::EnableDebugMode() {
    if (IsTGPAServiceAvailable()) {
        GetTGPAServiceInstance()->EnableDebugMode();
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Platform is not available."));
    }
}

void GCloud::TGPA::TGPAHelper::Init() {
    if (IsTGPAServiceAvailable()) {
        GetTGPAServiceInstance()->Init();
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Platform is not available."));
    }
}

void GCloud::TGPA::TGPAHelper::RegisterCallback(GCloud::TGPA::ITGPACallback *callback) {
    if (IsTGPAServiceAvailable()) {
        GetTGPAServiceInstance()->RegisterCallback(callback);
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Platform is not available."));
    }
}

void GCloud::TGPA::TGPAHelper::UpdateGameFps(float fps) {
    if (IsTGPAServiceAvailable()) {
        GetTGPAServiceInstance()->UpdateGameFps(fps);
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Platform is not available."));
    }
}

void GCloud::TGPA::TGPAHelper::UpdateGameInfo(const int key, const FString& value) {
    if (IsTGPAServiceAvailable()) {
        GetTGPAServiceInstance()->UpdateGameInfo(key, value);
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Platform is not available."));
    }
}

void GCloud::TGPA::TGPAHelper::UpdateGameInfo(const int key, const int value) {
    if (IsTGPAServiceAvailable()) {
        GetTGPAServiceInstance()->UpdateGameInfo(key, value);
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Platform is not available."));
    }
}

void GCloud::TGPA::TGPAHelper::UpdateGameInfo(const FString& key, const FString& value) {
    if (IsTGPAServiceAvailable()) {
        GetTGPAServiceInstance()->UpdateGameInfo(key, value);
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Platform is not available."));
    }
}

void GCloud::TGPA::TGPAHelper::UpdateGameInfo(const FString& key, const TMap<FString, FString>& mapData) {
    if (IsTGPAServiceAvailable()) {
        GetTGPAServiceInstance()->UpdateGameInfo(key, mapData);
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Platform is not available."));
    }
}

FString GCloud::TGPA::TGPAHelper::GetOptCfgStr() {
    if (IsTGPAServiceAvailable()) {
        return GetTGPAServiceInstance()->GetOptCfgStr();
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Platform is not available."));
        return FString(TEXT("-1"));
    }
}

FString GCloud::TGPA::TGPAHelper::CheckDeviceIsReal() {
    if (IsTGPAServiceAvailable()) {
        return GetTGPAServiceInstance()->CheckDeviceIsReal();
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Platform is not available."));
        return FString(TEXT("{\"result\":0}"));
    }
}

FString GCloud::TGPA::TGPAHelper::GetDataFromTGPA(const FString& key, const FString& value) {
    if (IsTGPAServiceAvailable()) {
        return GetTGPAServiceInstance()->GetDataFromTGPA(key, value);
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Platform is not available."));
        return FString(TEXT("-1"));
    }
}

int GCloud::TGPA::TGPAHelper::CheckHapticPlayerSupport(HapticPlayerType playerType) {
    if (IsTGPAServiceAvailable()) {
        return GetTGPAServiceInstance()->CheckHapticPlayerSupport(playerType);
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Platform is not available."));
        return 0;
    }
}

int GCloud::TGPA::TGPAHelper::CheckHapticAmplitudeSupport() {
    if (IsTGPAServiceAvailable()) {
        return GetTGPAServiceInstance()->CheckHapticAmplitudeSupport();
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Platform is not available."));
        return 0;
    }
}

void GCloud::TGPA::TGPAHelper::SetCurrentHapticPlayerType(HapticPlayerType playerType) {
    if (IsTGPAServiceAvailable()) {
        GetTGPAServiceInstance()->SetCurrentHapticPlayerType(playerType);
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Platform is not available."));
    }
}

void GCloud::TGPA::TGPAHelper::HapticPlay(const FString& heJson) {
    HapticPlay(heJson, DEFAULT_LOOP, DEFAULT_INTERVAL, DEFAULT_AMPLITUDE);
}

void GCloud::TGPA::TGPAHelper::HapticPlay(const FString& heJson, int loop, int interval, int amplitude) {
    if (IsTGPAServiceAvailable()) {
        GetTGPAServiceInstance()->HapticPlay(heJson, loop, interval, amplitude);
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Platform is not available."));
    }
}

void GCloud::TGPA::TGPAHelper::HapticPlayWithFile(const FString& heFilePath) {
    HapticPlayWithFile(heFilePath, DEFAULT_LOOP, DEFAULT_INTERVAL, DEFAULT_AMPLITUDE);
}

void GCloud::TGPA::TGPAHelper::HapticPlayWithFile(const FString& heFilePath, int loop, int interval, int amplitude) {
    if (IsTGPAServiceAvailable()) {
        GetTGPAServiceInstance()->HapticPlayWithFile(heFilePath, loop, interval, amplitude);
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Platform is not available."));
    }
}

void GCloud::TGPA::TGPAHelper::HapticStop() {
    if (IsTGPAServiceAvailable()) {
        GetTGPAServiceInstance()->HapticStop();
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Platform is not available."));
    }
}


