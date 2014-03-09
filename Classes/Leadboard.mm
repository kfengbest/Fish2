//
//  Leadboard.m
//  Fish
//
//  Created by Kaven Feng on 3/9/14.
//
//

#import "Leadboard.h"
#include "NGGameCenter.h"

Leadboard::Leadboard()
{
}

Leadboard::~Leadboard()
{
}

Leadboard* Leadboard::instance()
{
    static Leadboard theOnlyOne;
    return &theOnlyOne;
}

void Leadboard::registerLeadboardController()
{
    [[NGGameCenter sharedGameCenter] authenticateLocalUser];
}

void Leadboard::showLeadboard()
{
    [[NGGameCenter sharedGameCenter] showLeaderboard];
}

