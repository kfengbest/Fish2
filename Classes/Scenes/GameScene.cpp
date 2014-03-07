#include "GameScene.h"
#include "JoystickLayer.h"
#include "NagaLib.h"
#include "PauseScene.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool GameLayer::init()
{    
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
        
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("MainSceneBG.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

    
    // start game button.
    auto startGameBtn = MenuItemImage::create(
                                              "pausebtn.png",
                                              "pausebtn.png",
                                              CC_CALLBACK_1(GameLayer::menuPauseCallback, this));
    startGameBtn->setAnchorPoint(Point(1,1));
    startGameBtn->setPosition(Point::ZERO);
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(startGameBtn, NULL);
    menu->setAnchorPoint(Point(1,1));
    menu->setPosition(Point(visibleSize.width, visibleSize.height));
    this->addChild(menu, 20);
    
    return true;
}

void GameLayer::menuPauseCallback(Object* pSender)
{
    PauseScene* scene = PauseScene::create();
    Director::getInstance()->pushScene(scene);
}

GameScene* GameScene::create()
{
    GameScene* scene = new GameScene();
    if (scene && scene->init())
    {
        return scene;
    }
    
    scene = nullptr;
    return nullptr;
}

GameScene::GameScene()
: m_pLayer(nullptr)
{
    
}

GameScene::~GameScene()
{
    
}

bool GameScene::init()
{
    // Game layer
    m_pLayer = GameLayer::create();
    this->addChild(m_pLayer,10);
    
    return true;
}



