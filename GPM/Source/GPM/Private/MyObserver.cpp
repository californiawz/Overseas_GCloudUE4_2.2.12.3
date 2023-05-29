//
//  MyObserver.cpp
//  APM
//
//  Created by 雍鹏亮 on 2019/10/30.
//  Copyright © 2019 xianglin. All rights reserved.
//

#include "MyObserver.h"
#include "GPMHelper.h"

using namespace GCloud::GPM;

#if PLATFORM_IOS

MyObserver* MyObserver::m_pInst = NULL;
MyObserver* MyObserver::GetInstance()
{
    if(!m_pInst){
        m_pInst = new MyObserver();
    }
    return m_pInst;
}

void MyObserver::GPMOnMarkLevelLoad(const char *sceneId){
    if (sceneId != NULL)
    {

    }
}

void MyObserver::GPMOnSetQulaity(const char *quality)
{
    if (quality != NULL)
    {

    }
}

void MyObserver::GPMOnLog(const char *log){
    if (log != NULL)
    {
        if (GPMHelper::sLogObserver)
        {
            GPMHelper::sLogObserver(log);
        }
        else
        {
            NSLog(@"sLogObserver is NULL");
        }
    }
}

void MyObserver::GPMOnFpsNotify(const char *fpsString){
    if (fpsString != NULL)
    {

    }
}
#endif
