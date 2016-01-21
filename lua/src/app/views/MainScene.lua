
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
                        local args = {}
                        args.zone_name = "video"
                        sdkboxads:playAd("AdColony", 2, args )
                    end),
                   cc.MenuItemFont:create("AdColony Reward"):onClicked(function()
                        local args = {}
                        args.zone_name = "v4vc"
                        sdkboxads:playAd("AdColony", 3, args )
                    end),
                    cc.MenuItemFont:create("Fyber Video"):onClicked(function()
                        local args = {}
                        sdkboxads:playAd("Fyber", 2, args )
                    end),
                    cc.MenuItemFont:create("Fyber Reward"):onClicked(function()
                        local args = {}
                        sdkboxads:playAd("Fyber", 3, args )
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
