#include "NagaLib.h"
#include "Cocos2D.h"
#include "NagaAdapter.h"
#include "ScrollingBackground.h"
#include "Player.h"

USING_NS_CC;

/// <description>
/// clients need to use the create function
/// </description>
ScrollingBackground::ScrollingBackground()
    : mBackground1(nullptr)
    , mBackground2(nullptr)
{
}

/// <description>
/// destructor
/// </description>
ScrollingBackground::~ScrollingBackground()
{
}

/// <description>
/// init the layer instance
/// </description>
bool ScrollingBackground::init()
{    
    if ( !Node::init() )
    {
        return false;
    }
    
    mBackground1 = loadStage("path1.tmx");
    mBackground2 = loadStage("path2.tmx");
    if (!mBackground1 || !mBackground2)
        return false;

    Size scSize = mBackground1->getContentSize();
    Size scSize2= mBackground2->getContentSize();
    mBackground1->setAnchorPoint(Point(0.5f,0.5f));
    mBackground1->setPosition(0, 0);    // relative to parent position    
    mBackground2->setAnchorPoint(Point(0.5f,0.5f));
    mBackground2->setPosition(0, scSize.height/2 + scSize2.height/2);

    this->addChild(mBackground1);
    this->addChild(mBackground2);
    
    return true;
}

/// <description>
/// load TMX file from 
/// </description>
TMXTiledMap* ScrollingBackground::loadStage(const char* filename)
{
    TMXTiledMap* tmx = TMXTiledMap::create(filename);
    TMXLayer* layer = tmx ? tmx->getLayer("Layer1") : nullptr;
    if (!layer)  {
        if (tmx)
            tmx->release();
        return nullptr;
    }

    Size sz  = layer->getLayerSize();
    for (int i=0;i<sz.width;++i)
    {
        for (int j=0;j<sz.height;++j)
        {
            auto item = layer->getTileAt(Point(i,j));
            if (!item) 
                continue;

            auto body = PhysicsBody::create();            
            body->createBox(item->getContentSize());
            // not affected by the gravity
            body->setDynamic(false);            
            item->setPhysicsBody(body);
        }
    }
    
    return tmx;
}

/// <description>
/// Event callback that is invoked every time when Node enters the 'stage'.
/// If the Node enters the 'stage' with a transition, this event is called when the transition starts.
/// During onEnter you can't access a "sister/brother" node.
/// If you override onEnter, you shall call its parent's one, e.g., Node::onEnter().
/// </description>
void ScrollingBackground::onEnter() 
{
    Node::onEnter();
    
}

/// <description>
/// Event callback that is invoked every time the Node leaves the 'stage'.
/// If the Node leaves the 'stage' with a transition, this event is called when the transition finishes.
/// During onExit you can't access a sibling node.
/// If you override onExit, you shall call its parent's one, e.g., Node::onExit().
/// </description>
void ScrollingBackground::onExit()
{
    Node::onExit();

}

/// <description>
/// Update method will be called automatically every frame if "scheduleUpdate" is called, and the node is "live"
/// </description>
void ScrollingBackground::update(float delta)
{
    Node::update(delta);

    Size    sz = Director::getInstance()->getVisibleSize();
    Point   org= Director::getInstance()->getVisibleOrigin();
    
    Player* player = Player::InstancePtr();
    // if not in correct status 
    if (!player)    
        return;

    float velocity = player->getVelocity();
    float dist = velocity * delta;
    {
        Point pos = mBackground1->getPosition();
        mBackground1->setPosition(Point(pos.x, pos.y - dist));

        pos = mBackground2->getPosition();
        mBackground2->setPosition(Point(pos.x, pos.y - dist));
    }    

    /// if the current stage is out of screen, set it to correct position
    Point pos = mBackground1->getPosition();
    Size sz1 = mBackground1->getContentSize();
    if (pos.y <= -sz1.height)
    {
        Size  sz2 = mBackground2->getContentSize();        
        Point pos2= mBackground2->getPosition();
        mBackground2->setPosition(Point(pos2.x,(int)(pos2.y)));

        mBackground1->setPosition(Point(pos.x, (int)(pos2.y)+sz2.height));
        std::swap(mBackground1, mBackground2);
    }
}
