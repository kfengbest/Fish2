/*
 Copyright 2012 NAGA.  All Rights Reserved.
 
 The source code contained or described herein and all documents related
 to the source code ("Material") are owned by NAGA or its suppliers or
 licensors.  Title to the Material remains with NAGA or its suppliers and
 licensors.  The Material is protected by worldwide copyright laws and
 treaty provisions.  No part of the Material may be used, copied, reproduced,
 modified, published, uploaded, posted, transmitted, distributed, or
 disclosed in any way without NAGA's prior express written permission.
 
 No license under any patent, copyright, trade secret or other
 intellectual property right is granted to or conferred upon you by
 disclosure or delivery of the Materials, either expressly, by
 implication, inducement, estoppel or otherwise.  Any license under such
 intellectual property rights must be express and approved by NAGA in
 writing.
 */

/*
 Author         :	Yu Li
 Description	:	the hero fish
 History		:	2012, Initial implementation.
 */
#include "NagaAdapter.h"
#include "Player.h"

/// <description>
/// we would like the player to be a singleton for global usages
/// </description>
Player* Player::create()
{
    Player* player = InstancePtr();
    if (player->init())
        return player;

    delete player;
    return nullptr;
}

/// <description>
/// constructor
/// </description>
Player::Player() 
    : mSprite(nullptr)
    , mpAccEvent(nullptr)
    , mVelocity(0.f)
{
}

/// <description>
/// destructor
/// </description>
Player::~Player()
{
    
}

/// <description>
/// player initialization
/// </description>
bool Player::init()
{
    const char* fileName[] = { 
        "fish_1_0.png", 
        "fish_1_1.png",
        "fish_1_2.png",
        "fish_1_3.png",
        "fish_1_4.png",
        "fish_1_5.png",
        "fish_1_6.png",
        "fish_1_7.png"
    };
    auto sf = SpriteFrameCache::getInstance()->getSpriteFrameByName(fileName[0]);
    if (!sf)
        return false;
    
    mSprite = Sprite::createWithSpriteFrame(sf);
    auto body = PhysicsBody::create();
    body->createBox(mSprite->getContentSize());
    mSprite->setPhysicsBody(body);

    auto anim = Animation::create();
    for (int i=0;i<sizeof(fileName)/sizeof(fileName[0]);++i)
    {
        auto sf = SpriteFrameCache::getInstance()->getSpriteFrameByName(fileName[i]);
        if (!sf)
            return false;

        anim->addSpriteFrame(sf);
    }

    anim->setDelayPerUnit(0.5f / 3.0f);
    Animate* an = Animate::create(anim);
    mSprite->runAction(RepeatForever::create(an));

    this->addChild(mSprite);
    
    return true;
}

/// <description>
/// return the physical body 
/// </description>   
PhysicsBody* Player::getPhysicsBody()
{
    return mSprite->getPhysicsBody();
}

/// <description>
/// get the vertical velocity
/// </description>   
float Player::getVelocity()
{
    return mVelocity;
}

/// <description>
/// get the vertical velocity
/// </description>   
void Player::setVelocity(float v)
{
    mVelocity = v;   
}

/// <description>
/// let the acceleration event dispatched from the layer to Player
/// </description>   
void Player::onAcceleration(cocos2d::Acceleration* acc, cocos2d::Event* unused_event)
{
    CCLOG("%f, %f, %f", acc->x, acc->y, acc->z);
    Point pos = mSprite->getPosition();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    pos.x += (acc->x * 150) * 1;
    if (pos.x < 0) {
        pos.x = 0;
    }
    if (pos.x > visibleSize.width) {
        pos.x = visibleSize.width;
    }
    
    mSprite->setPosition(pos);
}


/// <description>
/// Event callback that is invoked every time when Node enters the 'stage'.
/// If the Node enters the 'stage' with a transition, this event is called when the transition starts.
/// During onEnter you can't access a "sister/brother" node.
/// If you override onEnter, you shall call its parent's one, e.g., Node::onEnter().
/// </description>
void Player::onEnter() 
{
    Node::onEnter();

    Device::setAccelerometerEnabled(true);
    Device::setAccelerometerInterval(0.07);

    // Setup the event dispatcher for Accelerometer
    auto dispatch = Director::getInstance()->getEventDispatcher();
    mpAccEvent = EventListenerAcceleration::create(CC_CALLBACK_2(Player::onAcceleration, Player::InstancePtr()));
    dispatch->addEventListenerWithSceneGraphPriority(mpAccEvent,this);    
}

/// <description>
/// Event callback that is invoked every time the Node leaves the 'stage'.
/// If the Node leaves the 'stage' with a transition, this event is called when the transition finishes.
/// During onExit you can't access a sibling node.
/// If you override onExit, you shall call its parent's one, e.g., Node::onExit().
/// </description>
void Player::onExit()
{
    Node::onExit();

    auto dispatch = Director::getInstance()->getEventDispatcher();    
    dispatch->removeEventListener(mpAccEvent);   
}

/// <description>
/// Update method will be called automatically every frame if "scheduleUpdate" is called, and the node is "live"
/// </description>
void Player::update(float delta)
{
    Node::update(delta);

    Size    sz = Director::getInstance()->getVisibleSize();
    Point   org= Director::getInstance()->getVisibleOrigin();    
}
