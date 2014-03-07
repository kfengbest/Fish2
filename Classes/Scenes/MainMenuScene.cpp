//
//  MainMenuScene.cpp
//  Fish
//
//  Created by Kaven Feng on 3/7/14.
//
//

#include "MainMenuScene.h"
#include "GameScene.h"
#include "PauseScene.h"

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
    // top layer.
    m_pLayer = cocos2d::LayerColor::create(cocos2d::Color4B(255,0,0,255));
    this->addChild(m_pLayer);

    // size
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // background
    auto sprite = Sprite::create("mainmenuscenebg.png");
    sprite->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    m_pLayer->addChild(sprite, 0);
    
    // start game button.
    auto startGameBtn = MenuItemImage::create(
                                           "transparentbutton.png",
                                           "transparentbutton.png",
                                           CC_CALLBACK_1(MainMenuScene::menuStartCallback, this));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(startGameBtn, NULL);
    menu->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    this->addChild(menu, 1);

    
    return true;
}

void MainMenuScene::menuStartCallback(Object* pSender)
{
    GameScene* scene = GameScene::create();
    Director::getInstance()->pushScene(scene);
}

