//
//  MainMenuScene.h
//  Fish
//
//  Created by Kaven Feng on 3/7/14.
//
//

#ifndef __Fish__MainMenuScene__
#define __Fish__MainMenuScene__

#include <iostream>
#include <cocos2d.h>

class MainMenuScene
: public cocos2d::Scene
{
    
public:
    static MainMenuScene* create();
    
    MainMenuScene();
    virtual ~MainMenuScene();
    
    bool init();
    
protected:
    
    cocos2d::Layer* m_pLayer;
    
};

#endif /* defined(__Fish__MainMenuScene__) */
