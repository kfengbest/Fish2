#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() 
{
    // initialize director
    auto director = Director::getInstance();
    auto eglView = EGLView::getInstance();

    director->setOpenGLView(eglView);

    // set the design resolution to what we would expect for vertical preferences
    eglView->setDesignResolutionSize(480,640, ResolutionPolicy::FIXED_HEIGHT);
    // set the scale factor to fit the screen : Resource Height / Design Height
    director->setContentScaleFactor(1136.0/640.0);
    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // add search paths
    FileUtils::getInstance()->addSearchPath("Joystick");
    FileUtils::getInstance()->addSearchPath("TileMaps");
    FileUtils::getInstance()->addSearchPath("ParallaxBackgrounds");

    // create a scene. it's an autorelease object
    auto scene = MainMenuScene::create();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
