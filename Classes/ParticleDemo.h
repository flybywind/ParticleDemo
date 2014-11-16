//
//  ParticleDemo.h
//  ParticleDemo
//
//  Created by flybywind on 14/11/16.
//
//

#ifndef ParticleDemo_ParticleDemo_h
#define ParticleDemo_ParticleDemo_h
#include "cocos2d.h"

class ParticleDemo : public cocos2d::Layer {
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    CREATE_FUNC(ParticleDemo);
private:
    cocos2d::Label* label_title;
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    
    
    void backMain(cocos2d::Ref*);
    virtual void onEnterTransitionDidFinish();
    
    
};


#endif
