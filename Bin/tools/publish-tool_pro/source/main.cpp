#ifdef __cplusplus
extern "C" {
#endif

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "lfs/lfs.h"
#include "cjson/lua_cjson.h"

#ifdef __cplusplus
}
#endif

#include "lua_function/tolua_ext.h"
#include "lua-modules/lua_export.h"


#define RUN_MUGEN_TEST 0

#if RUN_MUGEN_TEST
#include "MugenTest.h"
#endif


const char script[] =
{
	"local function entry()\n"
	"	require(\"main\")"
	"end\n"
	""
	"local function traceback(msg)\n"
	"	print(\"LUA ERROR : \" ..msg)\n"
	"	print(debug.traceback())"
	"end\n"
	""
	"xpcall(entry, traceback)"
};

static luaL_Reg modules[] = {
	{ "cjson", luaopen_cjson_safe },
	{ NULL, NULL }
};

int main(int argc, char** argv)
{
#if RUN_MUGEN_TEST
	MugenTest test;
	test.testMain();
#else

	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	luaopen_lfs(L);
	tolua_ext_open(L);
	luaopen_export(L);

	// load extensions
	luaL_Reg* lib = modules;
	lua_getglobal(L, "package");
	lua_getfield(L, -1, "preload");
	for (; lib->func; lib++)
	{
		lua_pushcfunction(L, lib->func);
		lua_setfield(L, -2, lib->name);
	}
	lua_pop(L, 2);

	// args
	lua_newtable(L);
	for (int i = 0; i < argc; ++i)
	{
		lua_pushnumber(L, i + 1);
		lua_pushstring(L, argv[i]);
		lua_settable(L, -3);
	}
	lua_setglobal(L, "args");

	// entry
	luaL_dostring(L, script);

	lua_close(L);
#endif

	return 0;
}


