
local MainScene = class("MainScene", cc.load("mvc").ViewBase)


-- MainScene.RESOURCE_FILENAME = "MainScene.csb"

function MainScene:onCreate()
    local sdkboxads = sdkbox.PluginSdkboxAds
    sdkboxads:init()
    sdkboxads:setListener(function(event)
        dump(event)
        local funcname = event.name
    end)

	cc.MenuItemFont:setFontName("Arial")
    cc.Menu:create(
                   cc.MenuItemFont:create("AdColony Video"):onClicked(function()
                        sdkboxads:playAd("AdColony", "video", {} )
                    end),
                   cc.MenuItemFont:create("AdColony Reward"):onClicked(function()
                        sdkboxads:playAd("AdColony", "v4vc", {} )
                    end),
                    cc.MenuItemFont:create("Fyber Video"):onClicked(function()
                        sdkboxads:playAd("Fyber", "INTERSTITIAL", {} )
                    end),
                    cc.MenuItemFont:create("Fyber Reward"):onClicked(function()
                        local args = {}
                        sdkboxads:playAd("Fyber", "REWARDED", {} )
                    end),
                    cc.MenuItemFont:create("Default ad"):onClicked(function()
                        sdkboxads:playAd()
                    end),
                    cc.MenuItemFont:create("Placement 1"):onClicked(function()
                        sdkboxads:placement("placement-1")
                    end),
                    cc.MenuItemFont:create("Placement 2"):onClicked(function()
                        sdkboxads:placement("placement-2")
                    end)

                   )
        :move(display.cx, display.cy)
        :addTo(self)
        :alignItemsVerticallyWithPadding(20)
end

return MainScene
