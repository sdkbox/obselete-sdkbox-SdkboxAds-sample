#include "HelloWorldScene.h"

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#else
#include <io.h>
#include <WS2tcpip.h>
#endif

USING_NS_CC;

using namespace sdkbox;

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

    Size size = CCDirector::getInstance()->getWinSize();
    std::string defaultFont("arial.ttf");
    int defaultFontSize = 32;
    
    Menu* menu = Menu::create(
                      MenuItemFont::create("AdColony Interstital",  CC_CALLBACK_1(HelloWorld::onAdColonyIntestitial, this)),
                      MenuItemFont::create("AdColony Reward",       CC_CALLBACK_1(HelloWorld::onAdColonyReward, this)),
                      MenuItemFont::create("Fyber Interstital",     CC_CALLBACK_1(HelloWorld::onFyberIntestitial, this)),
                      MenuItemFont::create("Fyber Reward",          CC_CALLBACK_1(HelloWorld::onFyberReward, this)),
                      MenuItemFont::create("Default Ad",            CC_CALLBACK_1(HelloWorld::onDefaultAd, this)),
                        MenuItemFont::create("Placement 1",            CC_CALLBACK_1(HelloWorld::onPlacement1, this)),
                      MenuItemFont::create("Placement 2",            CC_CALLBACK_1(HelloWorld::onPlacement2, this)),
                      NULL
                              );
    
    menu->alignItemsVerticallyWithPadding(5);
    menu->setPosition(size.width/2, size.height/2);
    addChild(menu);
    
    sdkbox::PluginSdkboxAds::setListener(this);
    sdkbox::PluginSdkboxAds::init();
    
    return true;
}

void HelloWorld::onPlacement1(cocos2d::CCObject *sender) {
    sdkbox::PluginSdkboxAds::placement("placement-1");
}

void HelloWorld::onPlacement2(cocos2d::CCObject *sender) {
    sdkbox::PluginSdkboxAds::placement("placement-2");
}


void HelloWorld::onAdColonyIntestitial(cocos2d::CCObject *sender) {
    
    sdkbox::AdUnitParams params;
    params.insert( std::pair<std::string,std::string>("zone-name","video") );
    sdkbox::PluginSdkboxAds::playAd("AdColony", sdkbox::AdType::INTERSTITIAL, params );
    
}
void HelloWorld::onAdColonyReward(cocos2d::CCObject *sender) {
    sdkbox::AdUnitParams params;
    params.insert( std::pair<std::string,std::string>("zone-name","v4vc") );
    sdkbox::PluginSdkboxAds::playAd("AdColony", sdkbox::AdType::REWARDED, params );
}
void HelloWorld::onFyberIntestitial(cocos2d::CCObject *sender) {
    sdkbox::PluginSdkboxAds::playAd("Fyber", sdkbox::AdType::INTERSTITIAL, sdkbox::AdUnitParams() );
}
void HelloWorld::onFyberReward(cocos2d::CCObject *sender) {
    sdkbox::PluginSdkboxAds::playAd("Fyber", sdkbox::AdType::REWARDED, sdkbox::AdUnitParams() );
}
void HelloWorld::onDefaultAd(cocos2d::CCObject *sender) {
    sdkbox::PluginSdkboxAds::playAd();
}

void HelloWorld::onAdAction( const std::string& ad_unit_id, sdkbox::AdType ad_type, sdkbox::AdActionType action_type) {
    
}

void HelloWorld::onRewardAction( const std::string& ad_unit_id, const std::string& reward_name, float reward_amount, bool reward_succeed, const std::string& zone_id) {
    
}