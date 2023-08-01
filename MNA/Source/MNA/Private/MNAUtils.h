//
// Created by jaredhuang on 2023/2/21.
//

#ifndef MNA_MNAUTILS_H
#define MNA_MNAUTILS_H

#include <string>
#include <sstream>
#include <vector>

class MNAUtils {
public:
#if PLATFORM_ANDROID
    static JNIEnv *WrapGetJavaEnv();
#endif
    static bool Contains(std::string &str, const char *token);

    static bool StartsWith(std::string &str, const char *token);

    static void Split(const std::string &str, const char *delimiter,
                         std::vector<std::string> *result);

    static std::string CPtrToStringThenFree(const char *ptr);
};

#endif //MNA_MNAUTILS_H
