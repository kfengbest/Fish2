//
//  Achievement.h
//  Fish
//
//  Created by Kaven Feng on 3/9/14.
//
//

#ifndef Fish_Achievement_h
#define Fish_Achievement_h

#include <vector>
#include <map>
#include "GameCenterIDs.h"

using namespace std;

typedef vector<EAchievementID> AchievementIDVec;

class Achievement
{
public:
    Achievement();
    virtual ~Achievement();
    
public:
    static Achievement* instance();
    void registerAchievementController();
    
    void showAchievmentBoard();
    void unlockAchievement(EAchievementID theId);
    
    const AchievementIDVec getAllLockedAchievement();
    const AchievementIDVec getAllUnlockedAchievement();
    
protected:
    bool isAchievementUnlocked(EAchievementID theId);
    
private:
    
};

#endif
