//------------------------------------------------------------------------------
//
// File: OneSDKTss.h
// Module: TssSDK
// Version: 3.0
// Author: TssSDK Dev Team
//
//------------------------------------------------------------------------------

#ifndef __ONE_SDK_TSS_H__
#define __ONE_SDK_TSS_H__

#include <stdio.h>
#include <stdint.h>


#define __ACE_EXPORT__


#if !defined(TP_EXPORT)
    #if !defined(__ACE_EXPORT__)
        #if defined(_MSC_VER) || defined(__SCE__)
            #define TP_EXPORT __declspec(dllexport)
        #else
            #define TP_EXPORT __attribute__ ((visibility ("default")))
        #endif
    #else
        #define TP_EXPORT
    #endif
#endif

#if !defined(ACE_EXPORT)
    #if defined(__ACE_EXPORT__)
        #if defined(_MSC_VER) || defined(__SCE__)
            #define ACE_EXPORT __declspec(dllexport)
        #else
            #define ACE_EXPORT __attribute__ ((visibility ("default")))
        #endif
    #else
        #define ACE_EXPORT
    #endif
#endif

#pragma pack(push, 1)

struct OneSDKTssSdkAntiDataInfo
{
    unsigned short AntiDataLen;   /* [in] length of anti data */
    const unsigned char *AntiData; /* [in] anti data buffer */
};


enum TssSDKEntryId
{
    kTssSDKEntryIdQQ = 1,
    kTssSDKEntryIdMM = 2,
    kTssSDKEntryIdFaceBook = 3,
    kTssSDKEntryIdTWITTER = 4,
    kTssSDKEntryIdLINE = 5,
    kTssSDKEntryIdWHATSAPP = 6,
    kTssSDKEntryIdGAMECENTER = 7,
    kTssSDKEntryIdGOOGLEPLAY = 8,
    kTssSDKEntryIdVK = 9,
    kTssSDKEntryIdKuaiShou = 10,
    kTssSDKEntryIdApple = 11,
    kTssSDKEntryIdNexon = 12,
    kTssSDKEntryIdNaver = 13,
    kTssSDKEntryIdGarena = 14,
    kTssSDKEntryIdHuaWei = 15,
    kTssSDKEntryIdRiot = 16,
    kTssSDKEntryIdNintendo = 17,
    kTssSDKEntryIdPSN = 18,
    kTssSDKEntryIdMicrosoft = 19,
    kTssSDKEntryIdEA        = 20,
    kTssSDKEntryIdCustom    = 21,
    kTssSDKEntryIdOthers = 99,
};

enum TssSDKRequestCmdId
{
    kTssSDKRequestCmdIdIsEmulator = 10,
    kTssSDKRequestCmdIdCommQuery = 18,
    kTssSDKRequestCmdIdInitSwitchStr = 45,
};

enum TssSDKLocaleId
{
    ACE_LOCALE_CN = 1,
    ACE_LOCALE_EN = 2,
    ACE_LOCALE_RU = 3,
    ACE_LOCALE_US = 4,
    ACE_LOCALE_EU = 5,
    ACE_LOCALE_IN = 6,
    ACE_LOCALE_JP = 7,
    ACE_LOCALE_KR = 8,
    ACE_LOCALE_TW = 9,
    ACE_LOCALE_VN = 10,
    ACE_LOCAL_GLOBAL = 998,
    ACE_LOCAL_OTHERS = 999,
};

typedef void (*OnRecvBroadcastFpn)(int type, const char *info);

#define AceSDKMethod(name) AnoSDK##name

#pragma pack(pop)

#ifdef __cplusplus
extern "C"
{
#endif

    TP_EXPORT void TssSDKInit(int game_id);
    TP_EXPORT void TssSDKInitEx(int game_id, const char *key);
    TP_EXPORT void TssSDKSetUserInfo(int entry_id, const char *open_id);
    TP_EXPORT void TssSDKSetUserInfoWithLicense(int entry_id, const char *open_id, const char* license);
    TP_EXPORT void TssSDKOnPause();
    TP_EXPORT void TssSDKOnResume();
    TP_EXPORT uintptr_t TssSDKGetReportData();
    TP_EXPORT void TssSDKDelReportData(uintptr_t data);
    TP_EXPORT void TssSDKOnRecvData(const unsigned char *data, int data_len);

    //
    TP_EXPORT int TssSDKIoctlOld(int request, const void *param, /*[out]*/char *buf, size_t buf_size, /*[out]*/size_t *used_buf_len);
    TP_EXPORT uintptr_t TssSDKIoctl(int request, const char *cmd);
    TP_EXPORT void TssSDKFree(uintptr_t info);
    TP_EXPORT uintptr_t TssSDKGetReportData2();
    TP_EXPORT uintptr_t TssSDKGetReportData3();
    TP_EXPORT void TssSDKDelReportData3(uintptr_t info);
    TP_EXPORT int TssSDKOnRecvSignature(const char* name, const unsigned char *buf, uint32_t buf_len, uint32_t crc);
    TP_EXPORT int TssSDKRegistInfoListener(OnRecvBroadcastFpn callback);

    //
    TP_EXPORT void TssSDKForExport();

    int TssSDKIsMTP();
    const char *TssSDKGetMTPMarcoStr();

    inline int TssSDKSetLocale(int locale_id)
    {
        const char* locale_cmd_fmt = "SetLocaleId:%d";
        char locale_cmd[64] = {0};
        int sz = snprintf(locale_cmd, sizeof(locale_cmd), locale_cmd_fmt, locale_id);
        if (sz < 0)
        {
            return -1;
        }
        char buf[32] = {0};
        size_t used_buf_len = 0;
        return TssSDKIoctlOld(kTssSDKRequestCmdIdCommQuery, locale_cmd, buf, sizeof(buf), &used_buf_len);
    }

    inline void TssSDKEnableGameReport()
    {
        char buf[32] = {0};
        size_t used_buf_len = 0;
        TssSDKIoctlOld(kTssSDKRequestCmdIdCommQuery, "EnableGameReport", buf, sizeof(buf), &used_buf_len);
    }

    ACE_EXPORT void AceSDKMethod(Init)(int game_id);
    ACE_EXPORT void AceSDKMethod(InitEx)(int game_id, const char *key);
    ACE_EXPORT void AceSDKMethod(SetUserInfo)(int entry_id, const char *open_id);
    ACE_EXPORT void AceSDKMethod(SetUserInfoWithLicense)(int entry_id, const char *open_id, const char* license);
    ACE_EXPORT void AceSDKMethod(OnPause)();
    ACE_EXPORT void AceSDKMethod(OnResume)();
    ACE_EXPORT uintptr_t AceSDKMethod(GetReportData)();
    ACE_EXPORT void AceSDKMethod(DelReportData)(uintptr_t data);
    ACE_EXPORT void AceSDKMethod(OnRecvData)(const unsigned char *data, int data_len);
    ACE_EXPORT int AceSDKMethod(IoctlOld)(int request, const void *param, /*[out]*/char *buf, size_t buf_size, /*[out]*/size_t *used_buf_len);
    ACE_EXPORT uintptr_t AceSDKMethod(Ioctl)(int request, const char *cmd);
    ACE_EXPORT void AceSDKMethod(Free)(uintptr_t info);
    ACE_EXPORT uintptr_t AceSDKMethod(GetReportData2)();
    ACE_EXPORT uintptr_t AceSDKMethod(GetReportData3)();
    ACE_EXPORT void AceSDKMethod(DelReportData3)(uintptr_t info);
    ACE_EXPORT int AceSDKMethod(OnRecvSignature)(const char* name, const unsigned char *buf, uint32_t buf_len, uint32_t crc);
    ACE_EXPORT int AceSDKMethod(RegistInfoListener)(OnRecvBroadcastFpn callback);
    ACE_EXPORT void AceSDKMethod(ForExport)();
    inline int AceSDKMethod(SetLocale)(int locale_id)
    {
        const char* locale_cmd_fmt = "SetLocaleId:%d";
        char locale_cmd[64] = {0};
        int sz = snprintf(locale_cmd, sizeof(locale_cmd), locale_cmd_fmt, locale_id);
        if (sz < 0)
        {
            return -1;
        }
        char buf[32] = {0};
        size_t used_buf_len = 0;
        return AceSDKMethod(IoctlOld)(kTssSDKRequestCmdIdCommQuery, locale_cmd, buf, sizeof (buf), &used_buf_len);
    }

    inline void AceSDKMethod(EnableGameReport)()
    {
        char buf[32] = {0};
        size_t used_buf_len = 0;
        AceSDKMethod(IoctlOld)(kTssSDKRequestCmdIdCommQuery, "EnableGameReport", buf, sizeof (buf), &used_buf_len);
    }

#ifdef __cplusplus
}
#endif

#endif
