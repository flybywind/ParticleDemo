#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include <vector>
#include <string>
#include "ParticleDemo.h"
enum ParticleType {
     kExplosion = 1
    ,kFire  
    ,kFireworks  
    ,kFlower  
    ,kGalaxy  
    ,kMeteor  
    ,kRain  
    ,kSmoke  
    ,kSnow  
    ,kSpiral  
    ,kSun
};
class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    cocos2d::MenuItemLabel* createMenuLabel(ParticleType type, std::string name);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

void startEffect(cocos2d::Ref* pSender);
#endif // __HELLOWORLD_SCENE_H__
