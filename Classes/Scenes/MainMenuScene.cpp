//
//  MainMenuScene.cpp
//  Fish
//
//  Created by Kaven Feng on 3/7/14.
//
//
#include "cocos2d.h"
#include "NagaLib.h"
#include "NagaAdapter.h"
#include "MainMenuScene.h"
#include "GameScene.h"
#include "PauseScene.h"

#if PLATFORM == PLATFORM_IOS
#include "Achievement.h"
#include "Leadboard.h"
#endif 

USING_NS_CC;
USING_NAGA;

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

    // leadboard button.
    auto leadboardGameBtn = MenuItemImage::create(
                                              "transparentbutton.png",
                                              "transparentbutton.png",
                                              CC_CALLBACK_1(MainMenuScene::menuLeadboardCallback, this));
    leadboardGameBtn->setPosition(Point(20, -80));
    
    // achievement button.
    auto achievementGameBtn = MenuItemImage::create(
                                              "transparentbutton.png",
                                              "transparentbutton.png",
                                              CC_CALLBACK_1(MainMenuScene::menuAchievementCallback, this));
    achievementGameBtn->setPosition(Point(50, -160));

    
    // create menu, it's an autorelease object
    auto menu = Menu::create(startGameBtn, leadboardGameBtn, achievementGameBtn, NULL);
    menu->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    this->addChild(menu, 1);

    return true;
}

void MainMenuScene::menuStartCallback(Object* pSender)
{
    Scene* sc = GameLayer::createScene();
    Director::getInstance()->pushScene(sc);
}

void MainMenuScene::menuAchievementCallback(Object* pSender)
{
#if PLATFORM == PLATFORM_IOS
    Achievement::instance()->showAchievmentBoard();
#endif
}

void MainMenuScene::menuLeadboardCallback(Object* pSender)
{
#if PLATFORM == PLATFORM_IOS
    Leadboard::instance()->showLeadboard();
#endif 
}

