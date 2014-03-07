#include "NagaLib.h"
#include "Cocos2D.h"
#include "StaticBackground.h"

USING_NS_CC;

/// <description>
/// clients need to use the create function
/// </description>
StaticBKGLayer::StaticBKGLayer(const std::string& filename)
    : mFilename(filename)
{
}

/// <description>
/// destructor
/// </description>
StaticBKGLayer::~StaticBKGLayer()
{
}

/// <description>
/// create function
/// </description>
StaticBKGLayer* StaticBKGLayer::create(const std::string& filename)
{
    StaticBKGLayer *pRet = new StaticBKGLayer(filename);
    if (pRet && pRet->init()) 
    { 
        pRet->autorelease();
        return pRet;
    } 

    delete pRet; 
    pRet = nullptr; 
    return pRet; 
}

bool StaticBKGLayer::init()
{    
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    Sprite* bkgSprite = Sprite::createWithSpriteFrameName(mFilename);
    if (bkgSprite)
    {
        bkgSprite->setPosition(winSize.width*.5f, winSize.height*.5f);

        // add the sprite as a child to this layer
        this->addChild(bkgSprite, 0);
        return true;
    }   

    return false;
}
