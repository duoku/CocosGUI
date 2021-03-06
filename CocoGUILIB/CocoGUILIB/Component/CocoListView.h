/*
 * Copyright (c) 2012 Chukong Technologies, Inc.
 *
 * http://www.sweetpome.com
 * http://tools.cocoachina.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do so, subject to the
 * following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
 * NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __Test__CocoListView__
#define __Test__CocoListView__

#include <iostream>
#include "CocoScrollView.h"

namespace cs
{
    typedef void (cocos2d::CCObject::*SEL_InitChildEvent)(cocos2d::CCObject*);
    typedef void (cocos2d::CCObject::*SEL_UpdateChildEvent)(cocos2d::CCObject*);
    #define coco_InitChildSelector(_SELECTOR) (cs::SEL_InitChildEvent)(&_SELECTOR)
    #define coco_UpdateChildSelector(_SELECTOR) (cs::SEL_UpdateChildEvent)(&_SELECTOR)
    
    class CocoListView : public CocoScrollView
    {
    public:
        CocoListView();
        virtual ~CocoListView();
        static CocoListView* create();
        virtual bool init();
        virtual bool addChild(CocoWidget* widget);
//        virtual void removeChildMoveToTrash(CocoWidget* child);
//        virtual void removeChildReferenceOnly(CocoWidget* child);
//        virtual void removeAllChildrenAndCleanUp(bool cleanup);
//        CocoWidget* getCheckPositionChild();
        
    protected:
        cocos2d::CCObject* m_pInitChildListener;
        SEL_InitChildEvent m_pfnInitChildSelector;
        cocos2d::CCObject* m_pUpdateChildListener;
        SEL_UpdateChildEvent m_pfnUpdateChildSelector;
    };
}


#endif /* defined(__Test__CocoListView__) */
