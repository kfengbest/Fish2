//
//  Leadboard.h
//  Fish
//
//  Created by Kaven Feng on 3/9/14.
//
//

#include <vector>
#include <map>
#include "GameCenterIDs.h"

using namespace std;
class Leadboard
{
public:
    Leadboard();
    virtual ~Leadboard();
    
public:
    static Leadboard* instance();
    void registerLeadboardController();
    
    void showLeadboard();

private:
    
};