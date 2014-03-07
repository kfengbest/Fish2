//
//  MainMenuScene.cpp
//  Fish
//
//  Created by Kaven Feng on 3/7/14.
//
//

#include "MainMenuScene.h"

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
    m_pLayer = cocos2d::Layer::create();
    this->addChild(m_pLayer);
    
    return true;
}
