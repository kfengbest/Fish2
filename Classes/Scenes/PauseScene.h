//
//  PauseScene.h
//  Fish
//
//  Created by Kaven Feng on 3/7/14.
//
//

#ifndef __Fish__PauseScene__
#define __Fish__PauseScene__

#include <iostream>
#include <cocos2d.h>

class PauseScene
: public cocos2d::Scene
{
    
public:
    static PauseScene* create();
    
    PauseScene();
    virtual ~PauseScene();
    
    bool init();
private:
    void menuResumeCallback(Object* pSender);
    void menuRestartCallback(Object* pSender);
    void menuMainMenuCallback(Object* pSender);

protected:
    
    cocos2d::Layer* m_pLayer;
    
};

#endif /* defined(__Fish__PauseScene__) */
