//
//  MyMNAObserver.h
//  UE4Demo
//
//  Created by Mike on 4/12/16.
//  Copyright © 2016 Tencent. All rights reserved.
//
#pragma once

#include "CoreMinimal.h"
#if PLATFORM_IOS
#include <MNA/MNAObserver.h>

class MyMNAObserver : public MNAObserver {
private:
  static MyMNAObserver *m_pInst;

public:
  static MyMNAObserver *GetInstance();

  void OnStartSpeedNotify(const char *startSpeedString);
  void OnQueryKartinNotify(const char *queryKartinString);
  void OnBatteryChangedNotify(const char *batteryChangedString);
  void OnStartRecord(const char *startRecordString);
  void OnQueryNetworkNotify(const char *networkInfoString);
  void OnQueryRouterNotify(const char *routerRetString);
  void OnBindNotify(const char *bindString);
  void OnGetIpGroupDelaysNotify(const char *delayString);
  void OnGetIpGroupDelaysTCPNotify(const char *delayString);
  void OnGetIpGroupDelaysWithBindingNotify(const char *delayString);
  void OnQueryPreciseKartinNotify(const char *kartinString);
  void OnPingNotify(const char *pingString);
};
#endif
