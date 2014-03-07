#include "JoystickLayer.h"

using namespace cocos2d;

/// <description>
/// constructor
/// </description>
JoystickLayer::JoystickLayer()
    : backgroundSprite(nullptr)
    , thumbSprite(nullptr)
    , joystick(nullptr)
{
}

JoystickLayer::~JoystickLayer()
{
	if (backgroundSprite)
	{
		backgroundSprite->release();
		backgroundSprite = NULL;
	}

	if (thumbSprite)
	{
		thumbSprite->release();
		thumbSprite = NULL;
	}

	if (joystick)
	{
		joystick->release();
		joystick = NULL;
	}
}

bool JoystickLayer::init()
{
	bool pRet = false;
	if(Layer::init())
    {
		this->backgroundSprite = nullptr;
		this->thumbSprite = nullptr;
    
        Size screenSize = Director::getInstance()->getWinSize();
        Rect joystickBaseDimensions = Rect(0, 0, 128.0f, 128.0f);
        
        Point joystickBasePosition;
        if (1)
        {
            // The device is an iPhone or iPod touch.
            joystickBasePosition = Point(screenSize.width*0.07f,screenSize.height*0.11f);
        }
        
        setPosition(joystickBasePosition);
        setBackgroundSprite(Sprite::create("dpadDown-hd.png"));
        setThumbSprite(Sprite::create("joystickDown-hd.png"));
        
        Joystick* pJoystick = Joystick::create();
        if (pJoystick->initWithRect(joystickBaseDimensions))
        {
            setJoystick(pJoystick);
        }
        
        this->schedule(schedule_selector(JoystickLayer::updatePositions));
        pRet = true;
    }
	return pRet;
}

void JoystickLayer::updatePositions(float delta)
{
	if(joystick && thumbSprite) {
		thumbSprite->setPosition(joystick->getStickPosition());
    }
}

void JoystickLayer::setContentSize(Size s)
{
	Layer::setContentSize(s);
	backgroundSprite->setContentSize(s);	
}

void JoystickLayer::setBackgroundSprite(Sprite *aSprite)
{
	if(backgroundSprite)
    {
		if(backgroundSprite->getParent())
			backgroundSprite->getParent()->removeChild(backgroundSprite, true);
		backgroundSprite->release();
        backgroundSprite=nullptr;
	}

	if(aSprite)
    {
        aSprite->retain();
        backgroundSprite = aSprite;
        
		this->addChild(backgroundSprite, 0);
		this->setContentSize(backgroundSprite->getContentSize());
	}
}

void JoystickLayer::setThumbSprite(Sprite *aSprite)
{
	if(thumbSprite)
    {
		if(thumbSprite->getParent())
			thumbSprite->getParent()->removeChild(thumbSprite, true);
		thumbSprite->release();
	}
	
	if(aSprite)
    {
        aSprite->retain();
        thumbSprite = aSprite;
        
		this->addChild(thumbSprite, 1);
		//joystick->setThumbRadius(thumbSprite->getContentSize().width/2);
	}
}

void JoystickLayer::setJoystick(Joystick *aJoystick)
{
	if(joystick){
		if(joystick->getParent())
			joystick->getParent()->removeChild(joystick, true);
		joystick->release();
	}
    
	if(aJoystick)
    {
        aJoystick->retain();
        joystick = aJoystick;

		this->addChild(aJoystick, 2);
		if(thumbSprite) {
			joystick->setThumbRadius(thumbSprite->getBoundingBox().size.width/2);
        }
		else {
			joystick->setThumbRadius(0);
        }
		
		if(backgroundSprite) {
			joystick->setJoystickRadius(backgroundSprite->getBoundingBox().size.width/2);
        }
	}
}
