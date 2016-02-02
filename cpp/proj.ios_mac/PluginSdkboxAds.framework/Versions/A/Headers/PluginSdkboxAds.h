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

        virtual void onAdAction( const std::string& ad_unit_id, const std::string& zone, sdkbox::AdActionType action_type) = 0;
        virtual void onRewardAction( const std::string& ad_unit_id, const std::string& zone_id, float reward_amount, bool reward_succeed) = 0;
    };

    class PluginSdkboxAds {

    private:

        static PluginSdkboxAdsListener * _listener;

    public:

        /**
         * Initialize the plugin instance. 
         * The plugin initializes from the sdkbox_config.json file and reads configuration of the form:
         *    "SdkboxAds": {
         *        "units": [ "AdColony", "Fyber" ],
         *        "placements": [ {} ]
         *    } 
         *
         * The "units" array references other plugins' configuration. Sdkboxads mediates between other plugins
         * and/or simplifies interaction with them.
         * The "placements" block will be of the form:
         *     {
         *          “id” : “placement_id”,
         *          "strategy" : "round-robin", // only value by now.
         *          “units” : [
         *              <UnitDefinition>
         *          ]
         *      }
         *
         * and each UnitDefinition as:
         *
         *      {
         *          “Unit” : result_of_AdUnit.getId(),
         *          “type” : “REWARDED” | “INTERSTITIAL” | “VIDEO” | “BANNER”,
         *          “params” : json_object
         *      }
         *
         * For a sample Sdkboxads config, check the example at Sdkbox github public repository.
         */ 
        static void init();

        /**
         * Set Sdkboxads' plugin listener.
         * This listener will expose for each registered AdUnits events related to Ads and Rewards.
         * Note that some ad units may have only Ads.
         */
        static void setListener(sdkbox::PluginSdkboxAdsListener *listener);

        /**
         * Retrieve plugin's listener.
         */ 
        static PluginSdkboxAdsListener * getListener();

        /**
         * Play an Ad identified by its zone/location/place with optional parameters.
         * AdUnits like Fyber which don't have zones, will use common placeholders like "INTERSTITIAL" or "REWARDED".
         * Some AdUnits may require extra information to play an Ad, and should use the params for that purpose.
         * You should refer to the documentation of each specific AdUnit about what parameters will accept.
         * 
         * The ad will be played for a specific AdUnit based on its identifier. The identifiers are the
         * values in the "units" node of the sdkbox_config.json file.
         * For example: "AdColony" or "Fyber".
         */
        static void playAd(const std::string& ad_unit, const std::string& zone_place_location, const AdUnitParams& params );
        static void playAd(const std::string& ad_unit, const std::string& zone_place_location );


        /**
         * Like the 3 parameter playAd method, this one plays an Ad for the default AdUnit.
         * Currently the default AdUnit is the first defined one in the sdkbox_config.json file.
         */
        static void playAd(const std::string&, const AdUnitParams& params );
        static void playAd(const std::string& );

        /**
         * Play a default Ad with the default AdUnit.
         * Each AdUnit knows how to play an Ad by default.
         * For example, AdColony will play the first video zone, or the first Reward if there's no one.
         */
        static void playAd();
        
        /**
         * A placement is a collection of mediated AdUnits.
         * The placement will cycle throughout all the AdUnits it references, in a 
         */
        static void placement(const std::string& placement);

        /**
         * Manage cache control policies.
         * Not all AdUnits expose cache control.
         *
         * cacheOpts for Chartboost:
         *
         *      element : bool
         *          Element corresponds to an identifiable CBLocation (ChartBoost)
         *
         *      e.g:
         *
         *      {
         *          "Default" : "true",
         *          "Level complete" : false
         *      }
         */
        static void cacheControl( const std::string& ad_unit, const std::map<std::string, std::string>& cacheOpts );

    };

}

#endif
