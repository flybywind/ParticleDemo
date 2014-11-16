//
//  ParticleDemo.cpp
//  ParticleDemo
//
//  Created by flybywind on 14/11/16.
//
//

#include "ParticleDemo.h"
#include "HelloWorldScene.h"
USING_NS_CC;


Scene* ParticleDemo::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ParticleDemo::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool ParticleDemo::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    
    label_title = Label::create("Init", "Arial", 45);
    auto label_back = Label::create("<Back", "Arial", 50);
    auto menu_back = MenuItemLabel::create(label_back, CC_CALLBACK_1(ParticleDemo::backMain, this));
    auto menu = Menu::createWithItem(menu_back);
    menu->setPosition(Vec2(origin.x + visibleSize.width,
                           origin.y ));
    menu_back->setAnchorPoint(Vec2(1,0));
    addChild(menu, 1);
    addChild(label_title, 2);
    return true;
}

void ParticleDemo::onEnterTransitionDidFinish(){
    Layer::onEnterTransitionDidFinish();
    
    ParticleSystem* particle_effect;
    CCLOG("tag of layer: %d", this->getTag());
    switch (this->getTag()) {
        case kExplosion:
            particle_effect = ParticleExplosion::create();
            label_title->setString("Explosion ");
            break;
        case kFire:
            particle_effect = ParticleFire::create();
            label_title->setString("Fire");
            break;
        case kFireworks:
            particle_effect = ParticleFireworks::create();
            label_title->setString("Fireworks");
            break;
        case kFlower:
            particle_effect = ParticleFlower::create();
            label_title->setString("Flower");
            break;
        case kGalaxy:
            particle_effect = ParticleGalaxy::create();
            label_title->setString("Galaxy");
            break;
        case kMeteor:
            particle_effect = ParticleMeteor::create();
            label_title->setString("Meteor");
            particle_effect->setStartColor(Color4F::GREEN);
            particle_effect->setEndColor(Color4F::BLACK);
//            particle_effect->setAngle(45);   // 试验证明，这个angle没用！
//            CCLOG("effect angle: %f", particle_effect->getAngle());
            particle_effect->setRotation(45);
            particle_effect->setStartSize(45);
            
            break;
        case kRain:
            particle_effect = ParticleRain::create();
            label_title->setString("Rain");
            break;
        case kSmoke:
            particle_effect = ParticleSmoke::create();
            label_title->setString("Smoke");
            break;
        case kSnow:
            particle_effect = ParticleSnow::create();
            label_title->setString("Snow");
            break;
        case kSpiral:
            particle_effect = ParticleSpiral::create();
            label_title->setString("Spiral");
            break;
        case kSun:
            particle_effect = ParticleSun::create();
            label_title->setString("Sun");
            break;
    }
    label_title->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    particle_effect->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    // 流星加上下降的move，看起来效果很诡异！
//    particle_effect->runAction(MoveBy::create(3, Vec2(0, -visibleSize.height)));
    this->addChild(particle_effect);
}

void ParticleDemo::backMain(Ref* pSender) {
    Director::getInstance()->replaceScene(HelloWorld::createScene());
}