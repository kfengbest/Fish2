//
//  PauseScene.cpp
//  Fish
//
//  Created by Kaven Feng on 3/7/14.
//
//

#include "PauseScene.h"

using namespace cocos2d;

PauseScene* PauseScene::create()
{
    PauseScene* scene = new PauseScene();
    if (scene && scene->init())
    {
        return scene;
    }
    
    scene = nullptr;
    return nullptr;
}

PauseScene::PauseScene()
: m_pLayer(nullptr)
{
    
}

PauseScene::~PauseScene()
{
    
}

bool PauseScene::init()
{
    m_pLayer = cocos2d::Layer::create();
    this->addChild(m_pLayer);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    auto sprite = Sprite::create("PauseScene.PNG");
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    m_pLayer->addChild(sprite, 0);
    
    
    return true;
}
