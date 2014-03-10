#ifndef __KOGO_Studio_Impl__
#define __KOGO_Studio_Impl__

#include "cocos2d.h"
USING_NS_CC;

/// <description>
/// object tag 
/// </description>
enum ObjectTag
{
    TAG_LOGO        = 1000,    
    TAG_PLAYER      ,
    TAG_BACKGROUND  ,
    TAG_SCROLLBAKG  , 
    TAG_GAMEOVER    , 
    TAG_SCORE       ,
    TAG_MENU        ,
    TAG_START_BTN   ,
    TAG_PAUSE_BTN   ,
};

/// <description>
/// default depth arrangement
/// </description>
enum ObjectDepth 
{
    /// the basic background
    DEPTH_BACKGROUND    = 0,
    /// the parallax background for slow movement 
    DEPTH_PARALLAX_BKG1 = 5, 
    /// the parallax background for slow movement 
    DEPTH_PARALLAX_BKG2 = 10, 
    /// the game layer
    DEPTH_GAME_LAYER    = 20,
    /// the foreground, which includes bubbles, coral reef or anything else  
    DEPTH_FOREGROUND    = 40,
    /// the UI Layer
    DEPTH_UI            = 80,
};

/// <description>
/// internal game status definition
/// </description>
enum GameStatus 
{
    GAME_STATUS_WELCOME    = 0,
    GAME_STATUS_PLAYING    = 10,
    GAME_STATUS_GAME_OVER  = 20,
    GAME_STATUS_RESTART    = 30
};

#endif // #if!def __KOGO_Studio_Impl__
