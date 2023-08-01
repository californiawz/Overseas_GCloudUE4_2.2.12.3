//
// Created by jaredhuang on 2023/2/21.
//

#include "MNAUtils.h"

#include <memory>


#if PLATFORM_ANDROID
JNIEnv *MNAUtils::WrapGetJavaEnv() {
  JNIEnv *Env = FAndroidApplication::GetJavaEnv();
  if (Env && Env->ExceptionCheck()) {
    Env->ExceptionDescribe();
    Env->ExceptionClear();
  }
  return Env;
}
#endif

bool MNAUtils::Contains(std::string &str, const char *token)
{
    std::string::size_type pos = str.find(token);
    return pos != std::string::npos;
}

bool MNAUtils::StartsWith(std::string &str, const char *token)
{
    if (token == nullptr) {
        return false;
    }
    return strncmp(token, str.c_str(), strlen(token)) == 0;
}

void MNAUtils::Split(const std::string &str, const char *delimiter,
                     std::vector <std::string> *result)
{
    if (nullptr == result)
    {
        return;
    }

    if (nullptr == delimiter)
    {
        result->push_back(str);
    } else
    {
        size_t pos_start = 0;
        size_t pos_end = 0;
        size_t delimiter_len = strlen(delimiter);
        std::string token;
        // 遍历
        if (delimiter_len > 0)
        {
            while ((pos_end = str.find(delimiter, pos_start)) != std::string::npos)
            {
                token = str.substr(pos_start, pos_end - pos_start);
                pos_start = pos_end + delimiter_len;
                result->push_back(token);
            }
        }
        // 添加剩下的
        result->push_back(str.substr(pos_start));
    }
}

std::string MNAUtils::CPtrToStringThenFree(const char *ptr)
{
    if (!ptr) {
        return "";
    }
    std::string result(ptr);
    free((void *)ptr);
    return result;
}