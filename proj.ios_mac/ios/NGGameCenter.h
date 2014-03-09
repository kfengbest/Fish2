//
//  NGGameCenter.h
//  FishShot
//
//  Created by Kaven Feng on 3/9/14.
//  Copyright (c) 2014 Kaven Feng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <GameKit/GameKit.h>
#include <string>

@interface NGGameCenter : NSObject <GKLeaderboardViewControllerDelegate,
                                    GKAchievementViewControllerDelegate,
                                    GKMatchmakerViewControllerDelegate,
                                    GKMatchDelegate>
{
    BOOL gameCenterAvailable;
    BOOL userAuthenticated;
}

@property (assign, readonly) BOOL gameCenterAvailable;
@property (nonatomic, copy) NSString* leaderboardName;
@property (nonatomic, retain) NSMutableDictionary* achievementDictionary;

// authenticate.
+(NGGameCenter*) sharedGameCenter;
-(void) authenticateLocalUser;
-(void) registerForAuthenticationNotification;

// leadboard
-(void) showLeaderboard;
-(void) reportScore:(int64_t)score forIdentifier:(NSString*)identifier;
-(void) retrieveTopXScores:(int)number forLeadboard : (NSString*) leaderboardID;
-(void) leaderboardViewControllerDidFinish:(GKLeaderboardViewController *)viewController;

// achievement
-(void) showAchievementboard;
-(void) achievementViewControllerDidFinish:(GKAchievementViewController *)achievementController;
-(void) loadAchievement;
-(void) clearAchievements;
-(void) reportAchievement:(NSString*)id percent:(float)percent;
-(void) unlockAchievement:(GKAchievement*)achievement percent:(float)percent;
-(GKAchievement*) getAchievementForID:(NSString*)id;


@end
