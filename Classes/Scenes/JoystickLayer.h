#ifndef __KOGO_JOYSTICKLAYER_H__
#define __KOGO_JOYSTICKLAYER_H__

#include "cocos2d.h"
#include "Joystick.h"

/// <description>
/// separate layer for joystick 
/// </description>
class JoystickLayer : public cocos2d::Layer
{
public:
    //Public methods	
    JoystickLayer();
    virtual ~JoystickLayer();
    CREATE_FUNC(JoystickLayer);

public:
	CC_SYNTHESIZE_READONLY(cocos2d::Sprite *, backgroundSprite, BackgroundSprite);
	CC_SYNTHESIZE_READONLY(cocos2d::Sprite *, thumbSprite, ThumbSprite);
	CC_SYNTHESIZE_READONLY(Joystick *, joystick, Joystick);
    
public:
    /// <description>
    /// init the layer
    /// </description>
	bool init() override;

    /// <description>
    /// update the position of thumb 
    /// </description>
	void updatePositions(float delta);

    /// <description>
    /// 
    /// </description>
	void setContentSize(cocos2d::Size s);

private:
    void setBackgroundSprite(cocos2d::Sprite *aSprite);
	void setThumbSprite(cocos2d::Sprite *aSprite); 
    void setJoystick(Joystick *aJoystick);
};

#endif
