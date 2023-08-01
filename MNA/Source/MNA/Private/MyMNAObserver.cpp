//
//  MyMNAObserver.cpp
//  MSDKDnsDevDemo
//
//  Created by Mike on 4/12/16.
//  Copyright © 2016 Tencent. All rights reserved.
//

#include "MyMNAObserver.h"

#if PLATFORM_IOS
#include "MNA_Platform.h"

MyMNAObserver *MyMNAObserver::m_pInst = NULL;
MyMNAObserver *MyMNAObserver::GetInstance() {
  if (!m_pInst) {
    m_pInst = new MyMNAObserver();
  }
  return m_pInst;
}

void MyMNAObserver::OnStartSpeedNotify(const char *startSpeedString) {
  UE_LOG(LogTemp, Log, TEXT("OnStartSpeedNotify -- %s"),
         UTF8_TO_TCHAR(startSpeedString));
  // Convert const char to string
  std::string configStr = std::string(startSpeedString);
  if (configStr.empty()) {
    return;
  }
  // parse string to vector
  std::stringstream ss;
  std::vector<std::string> configList;
  std::string configItem;
  ss.str(configStr);
  while (std::getline(ss, configItem, ';')) {
    configList.push_back(configItem);
  }
  // retrieve fps_cycle
  if (configList.size() != 3) {
    return;
  }

  int type = atoi(configList[0].c_str());
  int flag = atoi(configList[1].c_str());
  std::string desc = configList[2];
  StartSpeedRet ret;
  ret.type = type;
  ret.flag = flag;
  ret.desc = desc;
  MNA_Platform::MNA_StartNotifyFromMNA(ret);
}

void MyMNAObserver::OnQueryKartinNotify(const char *queryKartinString) {
  UE_LOG(LogTemp, Log, TEXT("OnQueryKartinNotify -- %s"),
         UTF8_TO_TCHAR(queryKartinString));
  // Convert const char to string
  std::string configStr = std::string(queryKartinString);
  if (configStr.empty()) {
    return;
  }
  // parse string to vector
  std::stringstream ss;
  std::vector<std::string> configList;
  std::string configItem;
  ss.str(configStr);
  while (std::getline(ss, configItem, ';')) {
    configList.push_back(configItem);
  }
  // retrieve fps_cycle
  if (configList.size() != 22) {
    return;
  }
  std::string tag = configList[0];
  int flag = atoi(configList[1].c_str());
  std::string desc = configList[2];
  int jump_network = atoi(configList[3].c_str());
  int jump_signal = atoi(configList[4].c_str());
  int jump_router = atoi(configList[5].c_str());
  int router_status = atoi(configList[6].c_str());
  std::string router_desc = configList[7];
  int jump_export = atoi(configList[8].c_str());
  int export_status = atoi(configList[9].c_str());
  std::string export_desc = configList[10];
  int jump_terminal = atoi(configList[11].c_str());
  int terminal_status = atoi(configList[12].c_str());
  std::string terminal_desc = configList[13];
  int jump_proxy = atoi(configList[14].c_str());
  int jump_edge = atoi(configList[15].c_str());
  std::string signal_desc = configList[16];
  int signal_status = atoi(configList[17].c_str());
  int jump_direct = atoi(configList[18].c_str());
  int direct_status = atoi(configList[19].c_str());
  std::string direct_desc = configList[20];
  int network_status = 0;
  std::string network_desc = "";
  int wifi_num = atoi(configList[21].c_str());

  KartinRet ret;
  ret.tag = tag;
  ret.flag = flag;
  ret.desc = desc;
  ret.jump_network = jump_network;
  ret.jump_signal = jump_signal;
  ret.jump_router = jump_router;
  ret.router_status = router_status;
  ret.router_desc = router_desc;
  ret.jump_export = jump_export;
  ret.export_status = export_status;
  ret.export_desc = export_desc;
  ret.jump_terminal = jump_terminal;
  ret.terminal_status = terminal_status;
  ret.terminal_desc = terminal_desc;
  ret.jump_proxy = jump_proxy;
  ret.jump_edge = jump_edge;
  ret.signal_desc = signal_desc;
  ret.signal_status = signal_status;
  ret.jump_direct = jump_direct;
  ret.direct_status = direct_status;
  ret.direct_desc = direct_desc;
  ret.network_status = network_status;
  ret.network_desc = network_desc;
  ret.wifi_num = wifi_num;
  MNA_Platform::MNA_KartinNotifyFromMNA(ret);
}

void MyMNAObserver::OnBatteryChangedNotify(const char *batteryChangedString) {
  UE_LOG(LogTemp, Log, TEXT("OnBatteryChangedNotify -- %s"),
         UTF8_TO_TCHAR(batteryChangedString));
  MNA_Platform::OnBatteryChangedNotify(batteryChangedString);
}

void MyMNAObserver::OnStartRecord(const char *startRecordString) {
  UE_LOG(LogTemp, Log, TEXT("OnStartRecord -- %s"),
         UTF8_TO_TCHAR(startRecordString));
  if (startRecordString != NULL) {
    MNA_Platform::MNA_ReceiveInfoFromMNA(startRecordString);
  }
}

void MyMNAObserver::OnQueryNetworkNotify(const char *networkInfoString) {
  UE_LOG(LogTemp, Log, TEXT("OnQueryNetworkNotify -- %s"),
         UTF8_TO_TCHAR(networkInfoString));
}

void MyMNAObserver::OnQueryRouterNotify(const char *routerInfoString) {
  UE_LOG(LogTemp, Log, TEXT("OnQueryRouterNotify -- %s"),
         UTF8_TO_TCHAR(routerInfoString));
}

void MyMNAObserver::OnBindNotify(const char *bindString) {
  UE_LOG(LogTemp, Log, TEXT("OnBindNotify -- %s"), UTF8_TO_TCHAR(bindString));
}

void MyMNAObserver::OnGetIpGroupDelaysNotify(const char *delayString) {
  UE_LOG(LogTemp, Log, TEXT("OnGetIpGroupDelaysNotify -- %s"),
         UTF8_TO_TCHAR(delayString));
  MNA_Platform::OnGetIpGroupDelaysNotify(delayString);
}

void MyMNAObserver::OnGetIpGroupDelaysTCPNotify(const char *delayString) {
  UE_LOG(LogTemp, Log, TEXT("OnGetIpGroupDelaysTCPNotify -- %s"),
         UTF8_TO_TCHAR(delayString));
  MNA_Platform::OnGetIpGroupDelaysTCPNotify(delayString);
}

void MyMNAObserver::OnGetIpGroupDelaysWithBindingNotify(const char *delayString) {
  UE_LOG(LogTemp, Log, TEXT("OnGetIpGroupDelaysWithBindingNotify -- %s"),
         UTF8_TO_TCHAR(delayString));
  MNA_Platform::OnGetIpGroupDelaysWithBindingNotify(delayString);
}

void MyMNAObserver::OnQueryPreciseKartinNotify(const char *kartinString) {
  UE_LOG(LogTemp, Log, TEXT("OnQueryPreciseKartinNotify -- %s"),
         UTF8_TO_TCHAR(kartinString));
  MNA_Platform::OnQueryPreciseKartinNotify(kartinString);
}

void MyMNAObserver::OnPingNotify(const char *pingString) {
  UE_LOG(LogTemp, Log, TEXT("OnPingNotify -- %s"), UTF8_TO_TCHAR(pingString));
  MNA_Platform::OnMNAPingNotify(pingString);
}

#endif
