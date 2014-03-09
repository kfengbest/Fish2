//
//  Achievement.m
//  Fish
//
//  Created by Kaven Feng on 3/9/14.
//
//

#include"Achievement.h"
#include "NGGameCenter.h"

Achievement::Achievement()
{
}

Achievement::~Achievement()
{
}

Achievement* Achievement::instance()
{
    static Achievement theOnlyOne;
    return &theOnlyOne;
}

void Achievement::registerAchievementController()
{
    [[NGGameCenter sharedGameCenter] authenticateLocalUser];
}

void Achievement::showAchievmentBoard()
{
    [[NGGameCenter sharedGameCenter] showAchievementboard];
}

bool Achievement::isAchievementUnlocked(EAchievementID theId)
{
    bool ret = true;
    
    std::string strID; // from theID
    NSString* identifier = [[NSString alloc] initWithUTF8String:strID.c_str()];
    GKAchievement* achive = [[NGGameCenter sharedGameCenter] getAchievementForID:identifier];
    if (achive) {
        ret = achive.completed;
    }
    return ret;
}

void Achievement::unlockAchievement(EAchievementID theId)
{
    std::string strID; // from theID
    NSString* identifier = [[NSString alloc] initWithUTF8String:strID.c_str()];
    GKAchievement* achive = [[NGGameCenter sharedGameCenter] getAchievementForID:identifier];
    if (achive){
        [[NGGameCenter sharedGameCenter] unlockAchievement:achive percent:100.0];
    }
}





