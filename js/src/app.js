
var AdType = {
  BANNER :        0,
  VIDEO :         1,
  INTERSTITIAL :  2,
  REWARDED :      3,
  ADTYPE_UNKNOWN :4
};

var AdActionType = {
  LOADED : 0,             // content loaded
  LOAD_FAILED : 1,        // content failed to load
        
  CLICKED : 2,            // clicked on content
        
  REWARD_STARTED : 3,
  REWARD_ENDED : 4,       // reward achieved
  REWARD_CANCELED : 5,    // reward aborted
        
  AD_STARTED : 6,         // start showing.
  AD_CANCELED : 7,        // start showing.
  AD_ENDED : 8,            // content shown
        
  ADACTIONTYPE_UNKNOWN  : 9
};

var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();
        var size = cc.winSize;

        sdkbox.PluginSdkboxAds.init();
        sdkbox.PluginSdkboxAds.setListener({

            onAdAction : function( ad_unit_id, zone_place_location, ad_action_number ) {
              cc.log("OnAdAction from unit: "+ad_unit_id+" "+zone_place_location+" "+ad_action_number);
            },

            onRewardAction : function( ad_unit_id, zone_place_location, reward_amount_float, reward_succeed_bool) {
              cc.log("OnRewardAction from unit: "+ad_unit_id+" reward:"+zone_place_location+" amount:"+reward_amount_float+" success:"+reward_succeed_bool);
            }

        });

        var b0 = new cc.MenuItemFont("AdColony Video", function(){
          sdkbox.PluginSdkboxAds.playAd("AdColony", "video", {} );
        }, this);
        var b1 = new cc.MenuItemFont("AdColony Reward", function(){
          sdkbox.PluginSdkboxAds.playAd("AdColony", "v4vc", {} );
        }, this);

        var b2 = new cc.MenuItemFont("Fyber Video", function(){
                                    sdkbox.PluginSdkboxAds.playAd("Fyber", "INTERSTITIAL", {});
        }, this);
        var b3 = new cc.MenuItemFont("Fyber Reward", function(){
                                     sdkbox.PluginSdkboxAds.playAd("Fyber", "REWARDED", {});
        }, this);

        var b4 = new cc.MenuItemFont("Default Ad", function(){
          sdkbox.PluginSdkboxAds.playAd();
        }, this);

        var b5 = new cc.MenuItemFont("Placement 1", function(){
          sdkbox.PluginSdkboxAds.placement("placement-1");
        }, this);

        var b6 = new cc.MenuItemFont("Placement 2", function(){
          sdkbox.PluginSdkboxAds.placement("placement-2");
        }, this);


        var menu = new cc.Menu(b0, b1, b2, b3, b4, b5, b6);
        menu.x = size.width/2;
        menu.y = size.height/2;
        menu.alignItemsVerticallyWithPadding(5);
        this.addChild(menu);

        // add a "close" icon to exit the progress. it's an autorelease object
        var closeItem = new cc.MenuItemImage(
            res.CloseNormal_png,
            res.CloseSelected_png,
            function () {
                cc.log("Menu is clicked!");
            }, this);
        closeItem.attr({
            x: size.width - 20,
            y: 20,
            anchorX: 0.5,
            anchorY: 0.5
        });

        var cl_menu = new cc.Menu(closeItem);
        cl_menu.x = 0;
        cl_menu.y = 0;
        this.addChild(cl_menu, 1);

        return true;
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});
