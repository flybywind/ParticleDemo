#include "HelloWorldScene.h"

USING_NS_CC;
using std::string;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("ParticalDemo", "Arial", 45);
    int height_up = origin.y + visibleSize.height - label->getContentSize().height;
    int width_center = origin.x + visibleSize.width*0.5;
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            height_up));
    this->addChild(label, 1);

    Vector<MenuItem*> menu_items;
    menu_items.pushBack(createMenuLabel(kExplosion, "Explosion"));
    menu_items.pushBack(createMenuLabel(kFire, "Fire"));
    menu_items.pushBack(createMenuLabel(kFireworks, "FireWorks"));
    menu_items.pushBack(createMenuLabel(kFlower, "Flower"));
    menu_items.pushBack(createMenuLabel(kGalaxy, "Galaxy"));
    menu_items.pushBack(createMenuLabel(kMeteor, "Meteor"));
    menu_items.pushBack(createMenuLabel(kRain, "Rain"));
    menu_items.pushBack(createMenuLabel(kSmoke, "Smoke"));
    menu_items.pushBack(createMenuLabel(kSnow, "Snow"));
    menu_items.pushBack(createMenuLabel(kSpiral, "Spiral"));
    menu_items.pushBack(createMenuLabel(kSun, "Sun"));

    auto menu_effect = Menu::createWithArray(menu_items);
    menu_effect->alignItemsInColumns(2, 2, 2, 2, 2, 1, NULL);
//    menu_effect->alignItemsVertically();
//    menu_effect->setAnchorPoint(Vec2(0, 0 ));  // 没用！
//    CCLOG("menu_effect size: (%d, %d)", menu_effect->getContentSize().width, menu_effect->getContentSize().height);
    menu_effect->setPosition(Vec2(width_center,
                                height_up - label->getContentSize().height*4));
//                                height_up));
    addChild(menu_effect, 0);
    return true;
}

MenuItemLabel* HelloWorld::createMenuLabel(ParticleType type, string name) {
    auto lable = Label::create(name, "Arial", 36);
    lable->setColor(Color3B::YELLOW);
    auto menu_item = MenuItemLabel::create(lable, startEffect);
    menu_item->setTag(type);
    return menu_item;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void startEffect(Ref* pSender) {
    auto type = ((MenuItemLabel*)pSender)->getTag();
    CCLOG("enter startEffect: tag = %d", type);
    auto particle = ParticleDemo::create();
    particle->setTag(type);
    auto scene = Scene::create();
    scene->addChild(particle);
    Director::getInstance()->replaceScene(scene);
}