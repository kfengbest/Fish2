//
//  GameOverScene.h
//  Fish
//
//  Created by Kaven Feng on 3/7/14.
//
//

#ifndef __Fish__GameOverScene__
#define __Fish__GameOverScene__

#include <iostream>

#include <cocos2d.h>

class GameOverScene
: public cocos2d::Scene
{
    
public:
    static GameOverScene* create();
    
    GameOverScene();
    virtual ~GameOverScene();
    
    bool init();
    
protected:
    
    cocos2d::Layer* m_pLayer;
    
};

#endif /* defined(__Fish__GameOverScene__) */
