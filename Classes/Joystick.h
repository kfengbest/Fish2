#ifndef __KOGO_JOYSTICK_H__
#define __SNEAKY_JOYSTICK_H__

#include "cocos2d.h"

/// <description>
/// Joystick is an abstract controller for specified layer where
/// thumb/image is provided
///
/// for the entire application, only one Joystick instance is needed
/// and be added into running layers dynamically
/// </description>
class Joystick : public cocos2d::Node
{
protected:
	float joystickRadiusSq;
	float thumbRadiusSq;
	float deadRadiusSq;
    cocos2d::EventListener* m_pTouchListener;

	CC_SYNTHESIZE_READONLY(cocos2d::Point, stickPosition, StickPosition);
	CC_SYNTHESIZE_READONLY(float, degrees, Degrees);
	CC_SYNTHESIZE_READONLY(cocos2d::Point, velocity, Velocity);
	CC_SYNTHESIZE(bool, autoCenter, AutoCenter);
	CC_SYNTHESIZE_READONLY(bool, isDPad, IsDPad);
	CC_SYNTHESIZE(bool, hasDeadzone, HasDeadzone);
	CC_SYNTHESIZE(int, numberOfDirections, NumberOfDirections);

	CC_SYNTHESIZE_READONLY(float, joystickRadius, JoystickRadius);
	CC_SYNTHESIZE_READONLY(float, thumbRadius, ThumbRadius);
	CC_SYNTHESIZE_READONLY(float, deadRadius, DeadRadius);

    ///<description>
    /// constructors & destructors
    ///</description>
    Joystick();
	virtual ~Joystick();
    
private:
	void updateVelocity(cocos2d::Point point);
	void setTouchRadius();

public:
    CREATE_FUNC(Joystick);

    /// <description>
    /// initialized the Joystick within specified rect in the screen
    /// </description>
    bool initWithRect(cocos2d::Rect rect);
    
    /// <description>
    /// invoked by addChild, if the Node/Layer is running
    /// </description>
	virtual void onEnterTransitionDidFinish() override;
    
    /// <description>
    /// invoked by detachChild
    /// </description>
	virtual void onExit() override;
    
public:
	void setIsDPad(bool b);
	void setJoystickRadius(float r);
	void setThumbRadius(float r);
	void setDeadRadius(float r);
    
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event);
};

#endif
