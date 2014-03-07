//
//  GameOverScene.cpp
//  Fish
//
//  Created by Kaven Feng on 3/7/14.
//
//

#include "GameOverScene.h"

GameOverScene* GameOverScene::create()
{
    GameOverScene* scene = new GameOverScene();
    if (scene && scene->init())
    {
        return scene;
    }
    
    scene = nullptr;
    return nullptr;
}

GameOverScene::GameOverScene()
: m_pLayer(nullptr)
{
    
}

GameOverScene::~GameOverScene()
{
    
}

bool GameOverScene::init()
{
    m_pLayer = cocos2d::Layer::create();
    this->addChild(m_pLayer);
    
    return true;
}
