/*!
 * @Module MSDK
 *
 * @Header MSDKFileUtils.h
 * @Author developer
 * @Date 2018/4/10
 * @Abstract
 * 文件功能的声明，需要根据具体的平台进行实现。
 * 比如 Android 的具体实现在目录： ${base/main/cpp/jni/MSDKFileUtils.cpp}
 *
 * @Copyright
 * Copyright © company. All rights reserved.
 */

#ifndef MSDK_FILE_UTILS_H
#define MSDK_FILE_UTILS_H

#include "MSDKMacros.h"
#include "MSDKSingleton.h"

NS_MSDK_BEGIN

#define MSDKV3_GUEST_UUID         "MSDKGuestUUID"
#define MSDKV3_GUEST_GUESTID      "MSDKGuestID"
#define MSDKV3_GUEST_TOKEN        "MSDKGuestToken"
#define MSDKV3_GUEST_REQID        "MSDKGuestReqId"


class MSDKFileUtils : public MSDKSingleton<MSDKFileUtils>
{
    friend class MSDKSingleton<MSDKFileUtils>;

private:
    MSDKFileUtils() {}

public:

    /*!
     * 获取文件存储路径
     * @param isInternal 文件放置的位置，true 是内部存储， false 是外部存储
     * @return 文件存在就返回文件的绝对路径，文件不存在返回字符串""
     */
    std::string FilePathForMSDK(bool isInternal = true);

    /*!
     * 判断文件是否为空
     *
     * @param fileName   文件名
     * @param isInternal 文件放置的位置，true 是内部存储， false 是外部存储
     * @param isCreateIfNotExist 文件不存在的情况，默认创建文件
     * @return 文件存在就返回文件的绝对路径，文件不存在返回字符串""
     */
    std::string IsFileExist(const std::string &fileName, bool isInternal = true,
        bool isCreateIfNotExist = true);


    /*!
     * 向文件名为 fileName 的文件写内容
     *
     * @param fileName   文件名
     * @param data       要写入文件的内容
     * @param isInternal 文件放置的位置，true 是内部存储， false 是外部存储
     * （例如 Android 的内部存储地址：data/data/package-name/files/fileName
     *       Android 的外部存储地址：sdcard/Android/data/package-name/files/fileName）
     * @return 操作成功标示
     */
    bool WriteFile(const std::string &fileName, const std::string &data, bool isInternal = true);

    /*!
     * 从文件 fileName 中读取内容
     *
     * @param fileName   文件名
     * @param isInternal 文件放置的位置，true 是内部存储， false 是外部存储
     * @return 返回文件的内容
     */
    std::string ReadFile(const std::string &fileName, bool isInternal = true);

    /*!
     * 重命名文件
     *
     * @param oldFileName 旧的文件名
     * @param newFileName 新文件名
     * @param isInternal 文件放置的位置，true 是内部存储， false 是外部存储
     * @return true 文件命名成功，否则为 false
     */
    bool RenameFile(const std::string &oldFileName, const std::string &newFileName,
        bool isInternal = true);

#if MSDK_PLATFORM_WINDOWS
    /*!
	 * 删除文件
	 *
	 * @param filePath   文件路径
	 * @return true 删除文件成功，否则为 false
	 */
	bool DeleteFileAtPath(const std::string &filePath);

	/*!
	 * 获取文件大小
	 *
	 * @param filePath   文件路径
	 */
	int64_t GetFileSize(const std::string &filePath);

	/*!
	 * 获取Windows系统临时文件路径，存储MSDK日志
	 *
	 * 
	 */
	std::string GetTempDirPath();

    /*!
     * Set Game ID for file utils
     * @param gameId  game id
     */
    void SetGameID(std::string gameId);
#else
    //DeleteFile与windows平台系统函数冲突
    /*!
     * 删除文件
     *
     * @param fileName   文件名
     * @param isInternal 文件放置的位置，true 是内部存储， false 是外部存储
     * @return true 删除文件成功，否则为 false
     */
    bool DeleteFile(const std::string &fileName, bool isInternal = true);
#endif // !MSDK_PLATFORM_WINDOWS

	/*!
	 * 设置默认偏好
	 *
	 * @param key   偏好的键值
	 * @param value 偏好的数值
	 * @param isUserDefault iOS使用这个字段，true UserDefault存储 ，false  keychain存储
	 * @return true 保存成功， false 保存失败
	 */
	bool SetDefaultPreference(const std::string &key, const std::string &value,
		bool isUserDefault = true);

    /*!
     * 根据键值获取默认偏好
     *
     * @param key 偏好的键值
     * @param isUserDefault iOS使用这个字段，true UserDefault存储 ，false  keychain存储
     * @return 返回键值对应的内容
     */
    std::string GetDefaultPreferenceByKey(const std::string &key, bool isUserDefault = true);


    /*!
     * 根据键值,删除默认偏好里面的项
     *
     * @param key 偏好的键值
     * @param isUserDefault iOS使用这个字段，true UserDefault存储 ，false  keychain存储
     */
    void DeleteDefaultPreferenceItem(const std::string &key, bool isUserDefault = true);


    /*!
     * 清空所有偏好设置
     *
     * @param isUserDefault iOS使用这个字段，true UserDefault存储 ，false  keychain存储
     */
    void DeleteDefaultPreference(bool isUserDefault = true);

    /*!
     *
     * 读取 MSDK 配置文件，不支持音视频以及图片的读取（Android 获取 Asset 目录下的文件内容；iOS 获取 MSDKAppSetting.bundle 文件中的内容）
     *
     * @param file 文件名称
     */
    std::string ReadConfigFile(const std::string &file);
    bool SetPreference(const std::string preference, const std::string &key, const std::string &value, bool isInternal, bool base64encode = true);
    
    /*!
     *
     * 获取MSDKV3的设备信息
     *
     */
    std::string GetMSDKV3GuestidInfo();
    
    /*!
     *
     * 重置当前用到过的（至少访问一次）的keychain数据
     *
     */
    void resetAllKeychainData();
    
    /*!
    *
    * 尝试迁移V3老版本Guest登录数据
    *
    */
    bool migrateMSDKV3GuestData();
    
    /*!
     *
     * 获取原先iTOP1.0的设备信息，确保升级到MSDK5.0之后游客不丢失
     *
     */
    std::string GetMSDKV1GuestidInfo();

    /*!
     * 将text进行base64编码
     */
    std::string Base64DecodeString(const std::string &text);

    /*！
     * 将text进行base64解码
     */
    std::string Base64EncodeString(const std::string &text);
    
    /**
     * 获取外部存储器目录，例如获取Android Sd卡目录
     * 路径为：/sdcard/MSDK/package_name/{subDir}
     * subDir为空，则获取前面的路径
     */
    std::string GetExternalStoragePath(const std::string &subDirName);
    /**
     * 读取文本文件内容
     * @param path  文件路径
     * @return  读取成功返回结果，读取失败返回空字符串
     */
    static std::string ReadText(const std::string &path);
    /**
     * 写入文本到指定文件
     * 如果文件不存在，则创建，如果存在截断为0后继续写入
     * @param path 文件路径
     * @param content 文本内容
     * @return 成功返回true，失败返回false
     */
    static bool WriteText(const std::string &path, std::string &content);
    static bool HasReadPermission(const std::string& path);
    static bool HasWritePermission(const std::string& path);
    static bool IsExisted(const std::string& path);
    
private:
    /*!
     *
     * 获取MSDKV3的AppId参数，用于从keychain中读取数据
     *
     */
    std::string getMSDKV3GuestAppIdWithoutPrefix();
    
    /*!
    *
    * 获取MSDKV3的AppId参数(2.30到2.40版本)，用于从keychain中读取数据
    *
    */
    std::string getMSDKV3GuestBetween230And240AppId();
    
    std::string keychainGuestIdBetween230And240();
    std::string keychainGuestTokenBetween230And240();
    std::string keychainGuestHKeyBetween230And240();
    
    /*!
    *
    * 保存V3的老版本的数据到新的V3的位置
    *
    */
    void saveGuestID(const std::string& guestId);
    void saveGuestToken(const std::string& guestToken);
    void saveGuestHKey(const std::string& guestHKey);
	
#if MSDK_PLATFORM_WINDOWS
	std::string msdk_core_dll_path_;
    std::string gameId;
#endif // MSDK_PLATFORM_WINDOWS
    
};

NS_MSDK_END

NS_MSDK_SPACE_NO_STL_BEGIN

using MSDKFileUtils = MSDK::MSDKFileUtils;

NS_MSDK_SPACE_NO_STL_END
#endif //MSDK_FILE_UTILS_H
