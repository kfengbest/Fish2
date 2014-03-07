#ifndef __StaticBackground_H__
#define __StaticBackground_H__

#include "cocos2d.h"

USING_NS_CC;

/// <description>
/// static background layer is a simple class, which contains the farthest background 
/// image which won't be scrolled
/// </description>
class StaticBKGLayer : public cocos2d::Layer
{
public:
    /// function 
    static StaticBKGLayer* create(const std::string& filename);
    virtual ~StaticBKGLayer();

protected:
    /// <description>
    /// init the layer instance
    /// </description>
    virtual bool init() override;

    /// <description>
    /// clients need to use the create function
    /// </description>
    StaticBKGLayer(const std::string& filename);

private:
    /// <description>
    /// filename for background image 
    /// </description>    
    std::string mFilename;
};

#endif // __StaticBackground_H__
