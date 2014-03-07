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
    
    auto sprite = Sprite::create("PauseScene.PNG");
    sprite->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    m_pLayer->addChild(sprite, 0);
    
    auto btn1 = MenuItemImage::create(
                                              "transparentbutton.png",
                                              "transparentbutton.png",
                                              CC_CALLBACK_1(PauseScene::menuResumeCallback, this));
    
    btn1->setPosition(Point(-50,-70));
    
    auto btn2 = MenuItemImage::create(
                                      "transparentbutton.png",
                                      "transparentbutton.png",
                                      CC_CALLBACK_1(PauseScene::menuRestartCallback, this));
    
    btn2->setPosition(Point(-10,-230));
    
    auto btn3 = MenuItemImage::create(
                                      "transparentbutton.png",
                                      "transparentbutton.png",
                                      CC_CALLBACK_1(PauseScene::menuMainMenuCallback, this));
    
    btn3->setPosition(Point(30,-350));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(btn1,btn2, btn3, NULL);
    menu->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    this->addChild(menu, 1);
    
    
    return true;
}

void PauseScene::menuResumeCallback(Object* pSender)
{
    Director::getInstance()->popScene();
}

void PauseScene::menuRestartCallback(Object* pSender)
{
    Director::getInstance()->popScene();

}

void PauseScene::menuMainMenuCallback(Object* pSender)
{
    Director::getInstance()->popToRootScene();
}
