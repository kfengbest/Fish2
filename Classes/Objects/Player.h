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
#ifndef __Fish__Player__
#define __Fish__Player__

#include <cocos2d.h>

/// <description>
/// init the instance
/// </description>
class Player : public cocos2d::Node, public NAGA Singleton<Player>
{
public:        
    static Player* create();
    Player();
    virtual ~Player();
    
public:
    /// <description>
    /// return the physical body 
    /// </description>   
    PhysicsBody* getPhysicsBody();

    /// <description>
    /// get the vertical velocity
    /// </description>   
    float getVelocity();

    /// <description>
    /// get the vertical velocity
    /// </description>   
    void setVelocity(float v);

    /// <description>
    /// let the acceleration event dispatched from the layer to Player
    /// </description>    
    void onAcceleration(cocos2d::Acceleration* acc, cocos2d::Event* unused_event);

protected:   
    /// <description>
    /// layer initialization
    /// </description>
    virtual bool init() override;

    /// <description>
    /// Event callback that is invoked every time when Node enters the 'stage'.
    /// If the Node enters the 'stage' with a transition, this event is called when the transition starts.
    /// During onEnter you can't access a "sister/brother" node.
    /// If you override onEnter, you shall call its parent's one, e.g., Node::onEnter().
    /// </description>
    virtual void onEnter() override;

    /// <description>
    /// Update method will be called automatically every frame if "scheduleUpdate" is called, and the node is "live"
    /// </description>
    virtual void update(float delta) override;

    /// <description>
    /// Event callback that is invoked every time the Node leaves the 'stage'.
    /// If the Node leaves the 'stage' with a transition, this event is called when the transition finishes.
    /// During onExit you can't access a sibling node.
    /// If you override onExit, you shall call its parent's one, e.g., Node::onExit().
    /// </description>
    virtual void onExit() override;

    /// <description>
    /// only vertical velocity is needed 
    /// </description>
    float mVelocity;
    
    /// <description>
    /// the render info
    /// </description>
    cocos2d::Sprite *mSprite;

    /// <description>
    /// acceleration event listener 
    /// </description>
    EventListenerAcceleration* mpAccEvent;
};

#endif /* defined(__Fish__GameOverScene__) */
