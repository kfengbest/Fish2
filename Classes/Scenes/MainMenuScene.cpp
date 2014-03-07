//
//  MainMenuScene.cpp
//  Fish
//
//  Created by Kaven Feng on 3/7/14.
//
//

#include "MainMenuScene.h"
USING_NS_CC;

MainMenuScene* MainMenuScene::create()
{
    MainMenuScene* scene = new MainMenuScene();
    if (scene && scene->init())
    {
        return scene;
    }
    
    scene = nullptr;
    return nullptr;
}

MainMenuScene::MainMenuScene()
: m_pLayer(nullptr)
{
    
}

MainMenuScene::~MainMenuScene()
{
    
}

bool MainMenuScene::init()
{
    m_pLayer = cocos2d::LayerColor::create(cocos2d::Color4B(255,0,0,255));
    this->addChild(m_pLayer);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    auto sprite = Sprite::create("mainmenuscenebg.png");
    sprite->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    
    m_pLayer->addChild(sprite, 0);
    
    return true;
}
