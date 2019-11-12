
#include "lua_modules.h"

#if __cplusplus
extern "C" {
#endif

//lfs
#include "lfs/lfs.h"

#if __cplusplus
} /// extern "C"
#endif

#include "imgui_lua/imgui_tolua.h"
#include "game/lua_game.h"

#include "cocos2d.h"

using namespace cocos2d;

namespace Lua_Print {

	int get_string_for_print(lua_State * L, std::string* out)
	{
		int n = lua_gettop(L);  /* number of arguments */
		int i;

		lua_getglobal(L, "tostring");
		for (i = 1; i <= n; i++) {
			const char *s;
			lua_pushvalue(L, -1);  /* function to be called */
			lua_pushvalue(L, i);   /* value to print */
			lua_call(L, 1, 1);
			size_t sz;
			s = lua_tolstring(L, -1, &sz);  /* get result */
			if (s == NULL)
				return luaL_error(L, LUA_QL("tostring") " must return a string to "
					LUA_QL("print"));
			if (i > 1) out->append("\t");
			out->append(s, sz);
			lua_pop(L, 1);  /* pop result */
		}
		return 0;
	}

	int lua_print(lua_State * L)
	{
		std::string t;
		get_string_for_print(L, &t);
		CCLOG("[LUA-print] %s", t.c_str());
		t.append("\n");
		lua_pushstring(L, t.c_str());
		return 1;
	}

	int lua_release_print(lua_State * L)
	{
		std::string t;
		get_string_for_print(L, &t);
		log("[LUA-print] %s", t.c_str());
		t.append("\n");
		lua_pushstring(L, t.c_str());
		return 1;
	}
}

void preload_lua_modules(lua_State *L)
{
	//lfs
	luaopen_lfs(L);

	luaopen_main(L);

	luaopen_game(L);

	// Register our version of the global "print" function
	const luaL_reg global_functions[] = {
		{ "print", Lua_Print::lua_print },
		{ "release_print",Lua_Print::lua_release_print },
		{ nullptr, nullptr }
	};
	luaL_register(L, "_G", global_functions);
}
