#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "PluginSdkboxAds/PluginSdkboxAds.h"

class HelloWorld : public cocos2d::Layer, public sdkbox::PluginSdkboxAdsListener
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    void runtests(int fd, const std::string& args);

    virtual void onAdAction( const std::string& ad_unit_id, sdkbox::AdType ad_type, sdkbox::AdActionType action_type);
    virtual void onRewardAction( const std::string& ad_unit_id, const std::string& reward_name, float reward_amount, bool reward_succeed, const std::string& zone_id);
    
    void onAdColonyIntestitial(cocos2d::CCObject *sender);
    void onAdColonyReward(cocos2d::CCObject *sender);
    void onFyberIntestitial(cocos2d::CCObject *sender);
    void onFyberReward(cocos2d::CCObject *sender);
    void onDefaultAd(cocos2d::CCObject *sender);
    void onPlacement1(cocos2d::CCObject *sender);
    void onPlacement2(cocos2d::CCObject *sender);
    
private:
    int _coins;
    cocos2d::Label * _txtCoin;
    cocos2d::Label * _txtStat;
};

#endif // __HELLOWORLD_SCENE_H__
