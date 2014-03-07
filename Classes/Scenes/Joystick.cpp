#include "Joystick.h"

using namespace cocos2d;

#define SJ_PI 3.14159265359f
#define SJ_PI_X_2 6.28318530718f
#define SJ_RAD2DEG 180.0f/SJ_PI
#define SJ_DEG2RAD SJ_PI/180.0f

/// <description>
/// constructor
/// </description>
Joystick::Joystick()
 : m_pTouchListener(nullptr) , stickPosition(Point::ZERO), joystickRadiusSq(0.0f), thumbRadiusSq(0.f), deadRadiusSq(0.f)
{
}

Joystick::~Joystick()
{
}

bool Joystick::initWithRect(Rect rect)
{
	bool pRet = false;
	//if(CCSprite::init()){
		stickPosition = Point::ZERO;
		degrees = 0.0f;
		velocity = Point::ZERO;
		autoCenter = true;
		isDPad = false;
		hasDeadzone = false;
		numberOfDirections = 4;
		
		this->setJoystickRadius(rect.size.width/2);
		this->setThumbRadius(32.0f);
		this->setDeadRadius(0.0f);
		
		//Cocos node stuff
		setPosition(rect.origin);
		pRet = true;
	//}
	return pRet;
}

void Joystick::onEnterTransitionDidFinish()
{
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();
    
    listener->onTouchBegan = CC_CALLBACK_2(Joystick::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(Joystick::onTouchEnded, this);
    listener->onTouchMoved   = CC_CALLBACK_2(Joystick::onTouchMoved, this);
    listener->onTouchCancelled = CC_CALLBACK_2(Joystick::onTouchCancelled, this);
    
    m_pTouchListener = listener;
    dispatcher->addEventListenerWithSceneGraphPriority(m_pTouchListener, this);
}

void Joystick::onExit()
{
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    dispatcher->removeEventListener(m_pTouchListener);
}

float round(float r) {
    return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}

void Joystick::updateVelocity(Point point)
{
	// Calculate distance and angle from the center.
	float dx = point.x;
	float dy = point.y;
	float dSq = dx * dx + dy * dy;
	
	if(dSq <= deadRadiusSq){
		velocity = Point::ZERO;
		degrees = 0.0f;
		stickPosition = point;
		return;
	}

	float angle = atan2f(dy, dx); // in radians
	if(angle < 0){
		angle		+= SJ_PI_X_2;
	}
	float cosAngle;
	float sinAngle;
	
	if(isDPad){
		float anglePerSector = 360.0f / numberOfDirections * SJ_DEG2RAD;
		angle = round(angle/anglePerSector) * anglePerSector;
	}
	
	cosAngle = cosf(angle);
	sinAngle = sinf(angle);
	
	// NOTE: Velocity goes from -1.0 to 1.0.
	if (dSq > joystickRadiusSq || isDPad) {
		dx = cosAngle * joystickRadius;
		dy = sinAngle * joystickRadius;
	}
	
	velocity = Point(dx/joystickRadius, dy/joystickRadius);
	degrees = angle * SJ_RAD2DEG;
	
	// Update the thumb's position
	stickPosition = Point(dx, dy);
}

void Joystick::setIsDPad(bool b)
{
	isDPad = b;
	if(isDPad){
		hasDeadzone = true;
		this->setDeadRadius(10.0f);
	}
}

void Joystick::setJoystickRadius(float r)
{
	joystickRadius = r;
	joystickRadiusSq = r*r;
}

void Joystick::setThumbRadius(float r)
{
	thumbRadius = r;
	thumbRadiusSq = r*r;
}

void Joystick::setDeadRadius(float r)
{
	deadRadius = r;
	deadRadiusSq = r*r;
}

bool Joystick::onTouchBegan(Touch *touch, Event *event)
{
	Point location = touch->getLocation();

	location = this->convertToNodeSpace(location);
	//Do a fast rect check before doing a circle hit check:
	if(location.x < -joystickRadius || location.x > joystickRadius || location.y < -joystickRadius || location.y > joystickRadius){
		return false;
	}else{
		float dSq = location.x*location.x + location.y*location.y;
		if(joystickRadiusSq > dSq){
			this->updateVelocity(location);
			return true;
		}
	}
	return false;
}

void Joystick::onTouchMoved(Touch *touch, Event *event)
{
	Point location = Director::getInstance()->convertToGL(touch->getLocationInView());
	location = this->convertToNodeSpace(location);
	this->updateVelocity(location);
}

void Joystick::onTouchEnded(Touch *touch, Event *event)
{
	Point location = Point::ZERO;
	if(!autoCenter){
		Point location = Director::getInstance()->convertToGL(touch->getLocationInView());
		location = this->convertToNodeSpace(location);
	}
	this->updateVelocity(location);
}

void Joystick::onTouchCancelled(Touch *touch, Event *event)
{
	this->onTouchEnded(touch, event);
}
