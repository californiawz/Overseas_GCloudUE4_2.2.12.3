//
//  MyObserver.hpp
//  APM
//
//  Created by 雍鹏亮 on 2019/10/30.
//  Copyright © 2019 xianglin. All rights reserved.
//

#ifndef MyObserver_hpp
#define MyObserver_hpp
#if PLATFORM_IOS
#include "GPMApiInterfaceObject.h"

class MyObserver : public GPMObserver{
private:
    static MyObserver * m_pInst;
public:
    static MyObserver *GetInstance();
    
    void GPMOnMarkLevelLoad(const char *sceneId);

    void GPMOnSetQulaity(const char *quality);

    void GPMOnLog(const char *log);

    void GPMOnFpsNotify(const char *fpsString);
    
};
#endif

#endif /* MyObserver_hpp */
