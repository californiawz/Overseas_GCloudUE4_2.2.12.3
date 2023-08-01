#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Engine/World.h"
#include <string>
#include <sstream>
#include <vector>

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidPlatform.h"
#endif

class StartSpeedRet
{
public:
	int type;
	int flag;
	std::string desc;
};
typedef void (*SpeedObserver)(const StartSpeedRet &ret);

class KartinRet
{
public:
	std::string tag;
	int flag;
	std::string desc;
	int jump_network;
	int jump_signal;
	int jump_router;
	int router_status;
	std::string router_desc;
	int jump_export;
	int export_status;
	std::string export_desc;
	int jump_terminal;
	int terminal_status;
	std::string terminal_desc;
	int jump_proxy;
	int jump_edge;
	std::string signal_desc;
	int signal_status;
	int jump_direct;
	int direct_status;
	std::string direct_desc;
	int network_status;
	std::string network_desc;
	int wifi_num;
};
typedef void (*KartinObserver)(const KartinRet &ret);

class QueryPreciseKartinRet {
public:
    int errCode;
    std::string jsonResult;
};
typedef void (*QueryPreciseKartinObserver)(const QueryPreciseKartinRet &ret);

class BatteryInfo
{
public:
    // 电量，0到100
    int level;
    // 是否在充电，1表示正在充电，0表示没有充电
    int charging;
};
typedef void (*BatteryObserver)(const BatteryInfo &ret);

class GetIpGroupDelaysRet {
public:
    std::string tag;
    std::string ipGroupDelaysResult;
};
typedef void (*GetIpGroupDelaysObserver)(const GetIpGroupDelaysRet &ret);

class MNAPingRet
{
public:
    std::string tag;
    int flag;
    std::string ip;
    std::string pingResult;
};
typedef void (*MNAPingObserver)(const MNAPingRet &ret);

class QueryConnectionInfoRet
{
public:
    int netType = -1;  // 网络类型
    // WiFi
    std::string bssID = "-1";  // 路由器的mac地址，单独云控控制
    int rssi = 65535;  // wifi的信号强度值
    int rssiLevel = -1;   // wifi的信号强度格数;
    int frequency = -1;  // 频率，单位MHz
    int channel = -1;  // 信道
    int linkSpeed = -1;  // 协商速率，单位 Mbps
    int wifiStandard = -1;  // wifi标准
    // 4G
    std::string cellID = "-1"; // 基站ID
    int dbm = 65535;  // 4G的信号接收信号强度值
    int dbmLevel = -1;  // 4G的信号强度格数
    int rsrp = 65535;  // 4G接收信号功率
    int rsrq = 65535; // 4G接收信号质量
    int sinr = 65535; // 4G信噪比
    int cqi = 65535; // 4G信道指标
};
typedef void (*QueryConnectionInfoObserver)(const QueryConnectionInfoRet &ret);

enum class AuxWifiSupportFlag
{
    // 当前非WiFi
    MNA_AUX_WIFI_SUPPORT_FLAG_NOT_WIFI = -1,
    // 不支持双WiFi
    MNA_AUX_WIFI_SUPPORT_FLAG_NOT_SUPPORT = 0,
    // 没有打开辅WiFi
    MNA_AUX_WIFI_SUPPORT_FLAG_NOT_ENABLE = 1,
    // 没有连接辅Wifi
    MNA_AUX_WIFI_SUPPORT_FLAG_NOT_CONNECT = 2,
    // 支持并已连接辅Wifi
    MNA_AUX_WIFI_SUPPORT_FLAG_ALL_PASS = 3,
};

enum class IpProto
{
    // TCP
    IP_PROTO_TCP = 6,
    // UDP
    IP_PROTO_UDP = 17,
};

enum class BindNetType
{
    // 表示不开启双通道
    BIND_NET_TYPE_NONE = -1,
    // WiFi-4G
    BIND_NET_TYPE_WIFI_4G = 0,
    // 有线-WiFi
    BIND_NET_TYPE_ETH_WIFI = 1,
    // 双WiFi
    BIND_NET_TYPE_WIFI_WIFI = 3,
};

enum class TransportInfoMsgType
{
	MNA_MSG_TYPE_ON_AIRPLANE = 301,
	MNA_MSG_TYPE_ON_GROUND = 302,
	MNA_MSG_TYPE_IN_BOMBING_AREA = 303,
	MNA_MSG_TYPE_ON_NARROW_ZONE = 304,
	MNA_MSG_TYPE_FRIENDS_INVITED = 305
};

enum class ReportChannelType
{
	// 使用灯塔上报
	CHANNEL_BEACON = 0,
	// 使用TDM上报
	CHANNEL_TDM = 1,
    // 使用INTL-SDK上报
    CHANNEL_INTL = 2
};

class MNA_Platform
{

#if PLATFORM_WINDOWS
#define __mna_dllcall __declspec(dllexport)
#else
#define __mna_dllcall
#endif

public:
    static void __mna_dllcall MNA_SetControlDomain(std::string controlDomain, int controlPort);
	static void __mna_dllcall MNA_Init(std::string qqappid, bool debug, int zoneid, ReportChannelType reportChannelType = ReportChannelType::CHANNEL_BEACON);
    static void __mna_dllcall MNA_Init(std::string qqappid, bool debug, int zoneid,
                                       bool isReleaseEnv, bool useBatteryNotify,
                                       ReportChannelType reportChannelType,
                                       std::string tCloudKey);
	static void __mna_dllcall MNA_SetUserName(int userType, std::string openid);
	static void __mna_dllcall MNA_SetUserName(int userType, std::string openid, std::string userId, std::string worldId);
	static void __mna_dllcall MNA_SetZoneId(int zoneid);
	static void __mna_dllcall MNA_StartSpeed(std::string vip, int vport,
											 int htype, std::string hookModules, int zoneid, int stopMNA, std::string pvpid, int timeout = 0);
	static void __mna_dllcall MNA_SetGameIp(std::string gameIp);
	static void __mna_dllcall MNA_StopMNA(std::string vip, int vport);
	static void __mna_dllcall MNA_EndSpeed(std::string vip, int vport);
	static void __mna_dllcall MNA_EndSpeed(std::string vip, int vport, std::string extrainfo);
    static void __mna_dllcall MNA_EndSpeed(std::string vip, int vport, std::string extrainfo, int gameWin);
	static int __mna_dllcall MNA_IsQOSWork();
	static void __mna_dllcall MNA_GoBack();
	static void __mna_dllcall MNA_GoFront();
	static void __mna_dllcall MNA_SetObserver(SpeedObserver speedObserver, KartinObserver kartinObserver);
    static void __mna_dllcall MNA_SetBatteryObserver(BatteryObserver batteryObserver);
	static void __mna_dllcall MNA_QueryKartin(std::string tag);
	static void __mna_dllcall MNA_TransportInfo(TransportInfoMsgType msgType, std::string msg);
    static void __mna_dllcall MNA_SetQueryPreciseKartinObserver(QueryPreciseKartinObserver observer);
	static void __mna_dllcall MNA_QueryPreciseKartin(int64_t curServTime, int64_t pvpDurationTime, std::string triggerDelay);

    static void __mna_dllcall MNA_SetGetIpGroupDelaysObserver(GetIpGroupDelaysObserver observer);
    static void __mna_dllcall MNA_SetGetIpGroupDelaysTCPObserver(GetIpGroupDelaysObserver observer);
    static void __mna_dllcall MNA_SetGetIpGroupDelaysWithBindingObserver(GetIpGroupDelaysObserver observer);
    static void __mna_dllcall MNA_GetIpGroupDelays(std::string tag, std::string ipPortGroup,
                                               int intervalMills, int count, int pkgTimeoutMills);
    static void __mna_dllcall MNA_GetIpGroupDelaysForTest(std::string tag, std::string ipPortGroup,
                                                   int intervalMills, int count, int pkgTimeoutMills);
    static void __mna_dllcall MNA_GetIpGroupDelaysUseTCP(std::string tag, std::string ipPortGroup,
                                                   int intervalMills, int count, int pkgTimeoutMills);
    static void __mna_dllcall MNA_GetIpGroupDelaysForTestUseTCP(std::string tag, std::string ipPortGroup,
                                                          int intervalMills, int count, int pkgTimeoutMills);
    static void __mna_dllcall MNA_GetIpGroupDelaysWithBinding(std::string tag, std::string ipPortGroup,
                                                         int intervalMills, int count, int pkgTimeoutMills,
                                                         IpProto ipProto, BindNetType bindNetType);

    static void __mna_dllcall MNA_SetMNAPingObserver(MNAPingObserver observer);
    static void __mna_dllcall MNA_PingGateway(std::string tag, int intervalMills, int count,
                                       int pkgTimeoutMills, bool onlyWifi);
    static void __mna_dllcall MNA_Ping(std::string ip, std::string tag, int intervalMills, int count,
                                       int pkgTimeoutMills, bool onlyWifi);
    static void __mna_dllcall MNA_SetPvpSpeedIp(std::string speedIp, int port);
    static bool __mna_dllcall MNA_IsAnyVPNOpen();
    static bool __mna_dllcall MNA_IsHarmonyOS();
    static bool __mna_dllcall MNA_IsAuxWifiAccelerated();
    static AuxWifiSupportFlag __mna_dllcall MNA_GetAuxWifiSupportFlag();
    static void __mna_dllcall MNA_SetAuxWifiUserAllow(bool isAllow);
    static void __mna_dllcall MNA_SetDualTunnelBindNetType(BindNetType bindNetType, bool useSaveFlow);
    static void __mna_dllcall MNA_SetAuxFlowEnable(bool enableSend, bool enableRecv);
    static void __mna_dllcall MNA_SetQueryConnectionInfoObserver(QueryConnectionInfoObserver observer);
    static void __mna_dllcall MNA_QueryConnectionInfo();
    static int __mna_dllcall MNA_GetWifiLinkSpeed();
    static std::string __mna_dllcall MNA_GetMobileActiveSimCountInfo();
    static int __mna_dllcall MNA_GetNetworkType();
    static int __mna_dllcall MNA_GetTelephonyType();
    static void __mna_dllcall MNA_EnterMapLoading();
    static int __mna_dllcall MNA_GetSpeedDelay();
    static BatteryInfo __mna_dllcall MNA_GetBatteryLevelAndCharging();

    // visible for plugin internal
    static void MNA_AddData(std::string fps);

	static void __mna_dllcall MNA_ReceiveInfoFromMNA(const char *fpsString);
	static void __mna_dllcall MNA_KartinNotifyFromMNA(const KartinRet &ret);
	static void __mna_dllcall MNA_StartNotifyFromMNA(const StartSpeedRet &ret);
    static void __mna_dllcall OnStartSpeedNotify(const char *str);
    static void __mna_dllcall OnQueryKartinNotify(const char *str);
    static void __mna_dllcall OnQueryPreciseKartinNotify(const char *str);
    static void __mna_dllcall OnGetIpGroupDelaysNotify(const char *str);
    static void __mna_dllcall OnGetIpGroupDelaysTCPNotify(const char *str);
    static void __mna_dllcall OnGetIpGroupDelaysWithBindingNotify(const char *str);
    static void __mna_dllcall OnMNAPingNotify(const char *str);
    static void __mna_dllcall OnConnectionInfoNotify(const char *str);
    static void __mna_dllcall OnBatteryChangedNotify(const char *str);

private:
	static void OnStartSpeedNotify(int type, int flag, const char *desc);
	static void OnQueryKartinNotify(const char *tag, int flag, const char *desc, int jump_network,
									int jump_signal, int jump_router, int router_status, const char *router_desc,
									int jump_export, int export_status, const char *export_desc, int jump_terminal,
									int terminal_status, const char *terminal_desc, int jump_proxy, int jump_edge,
									const char *signal_desc, int signal_status, int jump_direct, int direct_status,
									const char *direct_desc, int network_status, const char *network_desc, int wifi_num);
    static void HandleOnGetIpGroupDelays(const char *str, GetIpGroupDelaysObserver observer);
    static bool isFirstSetObserver;
    static bool isInit;
	static SpeedObserver sSpeedObserver;
	static KartinObserver sKartinObserver;
    static BatteryObserver sBatteryObserver;
    static QueryPreciseKartinObserver sQueryPreciseKartinObserver;
    static GetIpGroupDelaysObserver sGetIpGroupDelaysObserver;
    static GetIpGroupDelaysObserver sGetIpGroupDelaysTCPObserver;
    static GetIpGroupDelaysObserver sGetIpGroupDelaysWithBindingObserver;
    static MNAPingObserver sMNAPingObserver;
    static QueryConnectionInfoObserver sQueryConnectionInfoObserver;
};
