#ifndef MNA_EXPORT_C_API_MNA_H
#define MNA_EXPORT_C_API_MNA_H

#include <inttypes.h>
#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__clang__) || (defined(__GNUC__) && __GNUC__ >= 4)
#define MNA_EXPORT __attribute__((visibility("default")))
#define MNA_LOCAL __attribute__((visibility("hidden")))
#else
#define MNA_EXPORT
#define MNA_LOCAL
#endif

// ------------------- MNA API FOR OUTER -------------------

MNA_EXPORT
void mna_api_SetAuxFlowEnable(bool enable_send, bool enable_recv);

MNA_EXPORT
void mna_api_TransportInfo(int msgType, const char *msg);

MNA_EXPORT
void mna_api_SetUserName(int userType, const char *openid, const char *userId, const char *worldId);


}  // extern "C"

#endif  // MNA_EXPORT_C_API_MNA_H
