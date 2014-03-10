#ifndef __Srolling_Background_H__
#define __Srolling_Background_H__

/// <description>
/// scrolling background
/// </description>
class ScrollingBackground : public cocos2d::Node
{
public:
    CREATE_FUNC(ScrollingBackground);
    virtual ~ScrollingBackground();

    /// <description>
    /// Update method will be called automatically every frame if "scheduleUpdate" is called, and the node is "live"
    /// </description>
    virtual void update(float delta) override;

protected:
    /// <description>
    /// init the instance
    /// </description>
    virtual bool init() override;

    /// <description>
    /// Event callback that is invoked every time when Node enters the 'stage'.
    /// If the Node enters the 'stage' with a transition, this event is called when the transition starts.
    /// During onEnter you can't access a "sister/brother" node.
    /// If you override onEnter, you shall call its parent's one, e.g., Node::onEnter().
    /// </description>
    virtual void onEnter() override;

    /// <description>
    /// Event callback that is invoked every time the Node leaves the 'stage'.
    /// If the Node leaves the 'stage' with a transition, this event is called when the transition finishes.
    /// During onExit you can't access a sibling node.
    /// If you override onExit, you shall call its parent's one, e.g., Node::onExit().
    /// </description>
    virtual void onExit() override;

    /// <description>
    /// load TMX file from 
    /// </description>
    TMXTiledMap* loadStage(const char* filename);

    /// <description>
    /// constructors
    /// </description>
    ScrollingBackground();

private:    
    /// <description>
    /// 2 backgrounds for the scrolling 
    /// </description>
    TMXTiledMap* mBackground1;
    TMXTiledMap* mBackground2;
};

#endif // __Srolling_Background_H__
