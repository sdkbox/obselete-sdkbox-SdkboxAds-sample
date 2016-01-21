/****************************************************************************

 Copyright (c) 2014-2015 Chukong Technologies

 ****************************************************************************/

#ifndef _PLUGIN_SDKBOXADS_H_
#define _PLUGIN_SDKBOXADS_H_


#include <vector>
#include <string>
#include <map>
#include <sdkbox/Sdkbox.h>

namespace sdkbox {

    typedef std::map<std::string,std::string> AdUnitParams;

    class PluginSdkboxAdsListener {
    public:

        virtual void onAdAction( const std::string& ad_unit_id, sdkbox::AdType ad_type, sdkbox::AdActionType action_type) = 0;
        virtual void onRewardAction( const std::string& ad_unit_id, const std::string& reward_name, float reward_amount, bool reward_succeed, const std::string& zone_id) = 0;
    };

    class PluginSdkboxAds {

    private:

        static PluginSdkboxAdsListener * _listener;

    public:

        static void init();

        static void setListener(sdkbox::PluginSdkboxAdsListener *listener);
        static PluginSdkboxAdsListener * getListener();

        static void playAd(const std::string& ad_unit, AdType type, const AdUnitParams& params );
        static void playAd(AdType, const AdUnitParams& params );
        static void playAd();
        
        static void placement(const std::string& placement);

    };

}

#endif
