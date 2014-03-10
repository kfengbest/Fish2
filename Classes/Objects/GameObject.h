/*
 Copyright 2012 NAGA.  All Rights Reserved.
 
 The source code contained or described herein and all documents related
 to the source code ("Material") are owned by NAGA or its suppliers or
 licensors.  Title to the Material remains with NAGA or its suppliers and
 licensors.  The Material is protected by worldwide copyright laws and
 treaty provisions.  No part of the Material may be used, copied, reproduced,
 modified, published, uploaded, posted, transmitted, distributed, or
 disclosed in any way without NAGA's prior express written permission.
 
 No license under any patent, copyright, trade secret or other
 intellectual property right is granted to or conferred upon you by
 disclosure or delivery of the Materials, either expressly, by
 implication, inducement, estoppel or otherwise.  Any license under such
 intellectual property rights must be express and approved by NAGA in
 writing.
 */

/*
 Author         :	Yu Li
 Description	:	the general game objects definition
 History		:	2012, Initial implementation.
 */
#ifndef __Fish__GameObject__
#define __Fish__GameObject__

#include <cocos2d.h>

/// <description>
/// general
/// </description>
class GameObject : public cocos2d::Node
{
public:
    GameObject();
    virtual ~GameObject();
    
protected:
    /// node initialization
    virtual bool init() override;
};

#endif /* defined(__Fish__GameObject__) */
