
#include "PluginSdkboxAdsLuaHelper.h"
#include "PluginSdkboxAds/PluginSdkboxAds.h"
#include "CCLuaEngine.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"

class SdkboxAdsListenerLua : public sdkbox::PluginSdkboxAdsListener {
public:
	SdkboxAdsListenerLua(): mLuaHandler(0) {

	}
	~SdkboxAdsListenerLua() {
		resetHandler();
	}

	void setHandler(int luaHandler) {
		if (mLuaHandler == luaHandler) {
			return;
		}
		resetHandler();
		mLuaHandler = luaHandler;
	}

	void resetHandler() {
		if (0 == mLuaHandler) {
			return;
		}

        LUAENGINE->removeScriptHandler(mLuaHandler);
		mLuaHandler = 0;
	}


    virtual void onAdAction( const std::string& ad_unit_id, sdkbox::AdType ad_type, sdkbox::AdActionType action_type) {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onAdAction")));
        dict.insert(std::make_pair("ad_unit_id", LuaValue::stringValue(ad_unit_id)));
        dict.insert(std::make_pair("ad_type", LuaValue::intValue((int)ad_type)));
        dict.insert(std::make_pair("ad_action_type", LuaValue::intValue((int)ad_type)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    
    virtual void onRewardAction( 
        const std::string& ad_unit_id, 
        const std::string& reward_name, 
        float reward_amount, 
        bool reward_succeed, 
        const std::string& zone_id) {

        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onRewardAction")));
        dict.insert(std::make_pair("ad_unit_id", LuaValue::stringValue(ad_unit_id)));
        dict.insert(std::make_pair("reward_name", LuaValue::stringValue(reward_name)));
        dict.insert(std::make_pair("reward_amount", LuaValue::floatValue(reward_amount)));
        dict.insert(std::make_pair("reward_succeed", LuaValue::booleanValue(reward_succeed)));
        dict.insert(std::make_pair("zone_id", LuaValue::stringValue(zone_id)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);

    }

private:
	int mLuaHandler;
};

int lua_PluginSdkboxAdsLua_PluginSdkboxAds_setListener(lua_State* tolua_S) {
	int argc = 0;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSdkboxAds",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S, 2 , "LUA_FUNCTION",0,&tolua_err))
        {
            goto tolua_lerror;
        }
#endif
        LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
        SdkboxAdsListenerLua* lis = static_cast<SdkboxAdsListenerLua*> (sdkbox::PluginSdkboxAds::getListener());
        if (nullptr == lis) {
        	lis = new SdkboxAdsListenerLua();
        }
        lis->setHandler(handler);
        sdkbox::PluginSdkboxAds::setListener(lis);

        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSdkboxAds::setListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxAdsLua_PluginSdkboxAds_setListener'.",&tolua_err);
#endif
    return 0;
}


int lua_PluginSdkboxAdsLua_PluginSdkboxAds_playAd(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSdkboxAds",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            sdkbox::AdType arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginSdkboxAds:playAd");
            if (!ok) { break; }
            
            std::map<std::string,std::string> arg1;
            ok&=luaval_to_std_map_string_string( tolua_S, 3, &arg1, "sdkbox.PluginSdkboxAds:playAd");
            
            if (!ok) { break; }
            sdkbox::PluginSdkboxAds::playAd(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginSdkboxAds:playAd");
            if (!ok) { break; }
            sdkbox::AdType arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "sdkbox.PluginSdkboxAds:playAd");
            if (!ok) { break; }
            std::map<std::string,std::string> arg2;
            ok&=luaval_to_std_map_string_string( tolua_S, 4, &arg2, "sdkbox.PluginSdkboxAds:playAd");
            if (!ok) { break; }
            sdkbox::PluginSdkboxAds::playAd(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            sdkbox::PluginSdkboxAds::playAd();
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "sdkbox.PluginSdkboxAds:playAd",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSdkboxAdsLua_PluginSdkboxAds_playAd'.",&tolua_err);
#endif
    return 0;
}

int extern_PluginSdkboxAds(lua_State* L) {
	if (nullptr == L) {
		return 0;
	}

	lua_pushstring(L, "sdkbox.PluginSdkboxAds");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"setListener", lua_PluginSdkboxAdsLua_PluginSdkboxAds_setListener);
        tolua_function(L,"playAd", lua_PluginSdkboxAdsLua_PluginSdkboxAds_playAd);
    }
     lua_pop(L, 1);

    return 1;
}

TOLUA_API int register_all_PluginSdkboxAdsLua_helper(lua_State* L) {
	tolua_module(L,"sdkbox",0);
	tolua_beginmodule(L,"sdkbox");

	extern_PluginSdkboxAds(L);

	tolua_endmodule(L);
	return 1;
}


