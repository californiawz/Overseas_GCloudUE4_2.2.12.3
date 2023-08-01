//
// Created by jaredhuang on 2023/2/20.
//
#ifndef MNA_MNAMESSAGECENTER_H
#define MNA_MNAMESSAGECENTER_H

#if PLATFORM_ANDROID

#if PLATFORM_WINDOWS
#define __mna_dllcall __declspec(dllexport)
#else
#define __mna_dllcall
#endif

typedef int (*MNASendToUnreal)(const char *jsonStr);

class MNAMessageCenter {
public:
    static void __mna_dllcall MNASetBridge(MNASendToUnreal ptr);

    static int __mna_dllcall MNAMessageConsumer(const char *str);
private:
    static int __mna_dllcall MNAParseCallbackString(const char *str);
};

#endif


#endif  // MNA_MNAMESSAGECENTER_H
