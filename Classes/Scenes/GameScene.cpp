#include "NagaLib.h"
#include "NagaAdapter.h"
#include "GameScene.h"
#include "JoystickLayer.h"
#include "PauseScene.h"
#include "Constants.h"
#include "ScrollingBackground.h"
#include "Player.h"

USING_NS_CC;

cocos2d::Scene* GameLayer::createScene()
{
    auto scene = cocos2d::Scene::createWithPhysics();
    
    auto world = scene->getPhysicsWorld();
    /// draw all the debug info 
#ifdef _DEBUG
    world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
#endif 
    world->setGravity(Vect(0,0));
    
    // 'layer' is an autorelease object
    auto layer = GameLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer,10);
    
    return scene;
}

/// <description>
/// constructor
/// </description>
GameLayer::GameLayer() 
    : mpBackground(nullptr)
{
    auto cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("fish/fish_resource.plist");
}

/// <description>
/// destructor
/// </description>
GameLayer::~GameLayer()
{
    auto cache = SpriteFrameCache::getInstance();
    cache->removeSpriteFramesFromFile("fish/fish_resource.plist");
}

/// <description>
/// on "init" you need to initialize your instance
/// </description>
bool GameLayer::init()
{    
    // 1. super init first
    if ( !Layer::init() )
        return false;
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
 
    /// setup the background, UI and create the player
    if (!setupBackground() || !initUI())
        return false;

    /// setup the scrolling background
    mpBackground = ScrollingBackground::create();
    if (!mpBackground)
        return false;
    
    mpBackground->setAnchorPoint(Point(.5f,.5f));
    mpBackground->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(mpBackground, DEPTH_GAME_LAYER, TAG_SCROLLBAKG);
     
    return true;
}

/// <description>
/// setup the background layer
/// </description>
bool GameLayer::setupBackground()
{
    /// currently, a single background is used as being lack of suitable resources
    /// change to use Parallax Node soon
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto cache = SpriteFrameCache::getInstance();    
    SpriteFrame* bkgFrame = cache->getSpriteFrameByName("background.png");
    if (!bkgFrame)
        return false;

    Sprite* sprite = Sprite::createWithSpriteFrame(bkgFrame);
    /// for now, we need to rotate 90 degrees and do scale...
    {
        sprite->setRotation(-90);
        auto sz = sprite->getContentSize();
        sprite->setScale(2.0f, 2.0f);
    }

    // position the sprite on the center of the screen
    sprite->setPosition(
        Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, DEPTH_BACKGROUND, TAG_BACKGROUND);

    return true;
}

/// <description>
/// create the player 
/// </description>
bool GameLayer::createPlayer()
{
    auto player = Player::create();
    if (!player)
        return false;

    Size sz  = Director::getInstance()->getVisibleSize();
    Point org= Director::getInstance()->getVisibleOrigin();
    player->setPosition(Point(sz.width/2 + org.x, sz.height/3 + org.y));
    player->setVisible(true);
    this->addChild(player, DEPTH_GAME_LAYER, TAG_PLAYER);

    return true;
}

/// <description>
/// init the UI widgets
/// </description>
bool GameLayer::initUI()
{
    Size sz     = Director::getInstance()->getVisibleSize();
    Point org   = Director::getInstance()->getVisibleOrigin();

    auto pauseBtn = MenuItemImage::create(
        "pausebtn.png","pausebtn.png", CC_CALLBACK_1(GameLayer::menuPauseCallback, this));

    pauseBtn->setAnchorPoint(Point(1,1));
    pauseBtn->setPosition(Point::ZERO);
    pauseBtn->setVisible(true);

    // create menu, it's an autorelease object
    auto menu = Menu::create(pauseBtn, nullptr);
    menu->setAnchorPoint(Point(1,1));
    menu->setPosition(Point(sz.width, sz.height));
    this->addChild(menu, DEPTH_UI, TAG_MENU);

    return true;
}

/// <description>
/// Event callback for pause button is clicked
/// </description>
void GameLayer::menuPauseCallback(Object* pSender)
{
    PauseScene* scene = PauseScene::create();
    Director::getInstance()->pushScene(scene);
}

/// <description>
/// Event callback that is invoked every time when Node enters the 'stage'.
/// If the Node enters the 'stage' with a transition, this event is called when the transition starts.
/// During onEnter you can't access a "sister/brother" node.
/// If you override onEnter, you shall call its parent's one, e.g., Node::onEnter().
/// </description>
void GameLayer::onEnter() 
{
    Layer::onEnter();
     
    if (createPlayer())
    {
        Player::InstancePtr()->setVelocity(40.f);
        /// schedule timely update when the layer is entering the stages
        this->scheduleUpdate();
    }           

    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto contact = EventListenerPhysicsContact::create();
    contact->onContactBegin = CC_CALLBACK_2(GameLayer::onContactBegin,this);
    dispatcher->addEventListenerWithSceneGraphPriority(contact, this);
}

/// <description>
/// Event callback that is invoked every time the Node leaves the 'stage'.
/// If the Node leaves the 'stage' with a transition, this event is called when the transition finishes.
/// During onExit you can't access a sibling node.
/// If you override onExit, you shall call its parent's one, e.g., Node::onExit().
/// </description>
void GameLayer::onExit()
{
    Layer::onExit();

    /// unschedule the update when the layer is leaving
    this->unscheduleUpdate();
}

/// <description>
/// Update method will be called automatically every frame if "scheduleUpdate" is called, and the node is "live"
/// </description>
void GameLayer::update(float delta)
{
    Layer::update(delta);

    Size    sz = Director::getInstance()->getVisibleSize();
    Point   org= Director::getInstance()->getVisibleOrigin();

    mpBackground->update(delta);
}

/// <description>
/// collision detection event
/// </description>
bool GameLayer::onContactBegin(EventCustom* event, const PhysicsContact& contact)
{
    Node* pNodeA = contact.getShapeA()->getBody()->getNode();
    Node* pNodeB = contact.getShapeB()->getBody()->getNode();

    auto player = Player::InstancePtr();
    if (pNodeA == player || pNodeB == player)
    {
        
    }

    return true;
}
