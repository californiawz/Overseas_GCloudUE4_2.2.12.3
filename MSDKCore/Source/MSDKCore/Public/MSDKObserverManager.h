/*!
 * @header MSDKObserverManager.h 
 * @author developer
 * @date 2018/4/28
 * @abstract
 * 通用的观察者模型声明
 * 
 * @copyright
 * Copyright © company. All rights reserved.
 */

#ifndef MSDK_OBSERVER_MANAGER_H
#define MSDK_OBSERVER_MANAGER_H

#include "MSDKLog.h"
#include "MSDKMacros.h"
#include "MSDKMutex.h"

NS_MSDK_BEGIN

class IObserver
{
public:
    virtual void Change(const std::string &tag) = 0;
};


class MSDKObserverManager
{
private:
    static std::set<IObserver *> mObserverQueue;
    MSDKMutex m_observerMutex;
public:
    void AddObserver(IObserver *observer);

    void RemoveObserver(IObserver *observer);

    void Update(const std::string &tag);
};

NS_MSDK_END

#endif //MSDK_OBSERVER_MANAGER_H
