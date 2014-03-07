#include "GameScene.h"
#include "JoystickLayer.h"
#include "NagaLib.h"
#include "PauseScene.h"

USING_NS_CC;

GameLayer::GameLayer()
: m_pActor(nullptr)
{
    
}

GameLayer::~GameLayer()
{
}

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

    m_pActor = Sprite::create("billiard.png");
    m_pActor->setPosition(Point(100,100));
    m_pActor->setScale(0.5);
    this->addChild(m_pActor, 10);
    
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
    
    // Accelerometer
    this->setAccelerometerEnabled(true);
    this->setAccelerometerInterval(0.07);
    
    return true;
}


void GameLayer::onAcceleration(cocos2d::Acceleration* acc, cocos2d::Event* unused_event)
{
    cocos2d::log("%f, %f, %f", acc->x, acc->y, acc->z);
    Point pos = m_pActor->getPosition();
    Size visibleSize = Director::getInstance()->getVisibleSize();

    pos.x += (acc->x * 150) * 1;
    if (pos.x < 0) {
        pos.x = 0;
    }
    if (pos.x > visibleSize.width) {
        pos.x = visibleSize.width;
    }

    m_pActor->setPosition(pos);
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



