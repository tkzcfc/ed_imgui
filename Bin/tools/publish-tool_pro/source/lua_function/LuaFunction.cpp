﻿#include "LuaFunction.h"
#include <assert.h>

LuaRef::LuaRef() 
	: L(nullptr)
	, m_ref(LUA_NOREF)
{
}

LuaRef::LuaRef(lua_State* aL, int index) 
	: L(aL)
	, m_ref(LUA_NOREF)
{
	lua_pushvalue(L, index);
	m_ref = luaL_ref(L, LUA_REGISTRYINDEX);
}

LuaRef::~LuaRef()
{
	unref();
}

LuaRef::LuaRef(const LuaRef& other) 
	: L(nullptr)
	, m_ref(LUA_NOREF)
{
	*this = other;
}

LuaRef& LuaRef::operator=(const LuaRef& rhs)
{
	if (this != &rhs)
	{
		rhs.push();
		reset(rhs.L, -1);
		lua_pop(L, 1);
	}
	return *this;
}

LuaRef::LuaRef(LuaRef&& other) 
	: L(nullptr)
	, m_ref(LUA_NOREF)
{
	*this = std::move(other);
}

LuaRef& LuaRef::operator=(LuaRef&& rhs)
{
	if (this != &rhs)
	{
		unref();

		L = rhs.L;
		m_ref = rhs.m_ref;

		rhs.L = nullptr;
		rhs.m_ref = LUA_NOREF;
	}
	return *this;
}

LuaRef::operator bool() const
{
	return m_ref != LUA_NOREF;
}

void LuaRef::reset(lua_State* aL, int index)
{
	unref();
	if (aL != nullptr) 
	{
		L = aL;
		lua_pushvalue(L, index);
		m_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
}

void LuaRef::push() const
{
	lua_rawgeti(L, LUA_REGISTRYINDEX, m_ref);
}

void LuaRef::unref() const
{
	if (L && m_ref != LUA_NOREF && m_ref != LUA_REFNIL)
	{
		luaL_unref(L, LUA_REGISTRYINDEX, m_ref);
	}
}



LuaFunction::LuaFunction()
	: LuaRef()
	, m_trackback(0)
	, m_isValid(true)
{
}

LuaFunction::LuaFunction(lua_State* aL, int index, int) 
	: LuaRef(aL, index)
	, m_trackback(0)
	, m_isValid(true)
{
	luaL_checktype(aL, index, LUA_TFUNCTION);
}

LuaFunction::LuaFunction(const LuaFunction& other) 
	: LuaRef()
	, m_isValid(true)
{
	*this = other;
}

LuaFunction& LuaFunction::operator=(const LuaFunction& rhs)
{
	if (this != &rhs)
	{
		rhs.push();
		luaL_checktype(rhs.L, -1, LUA_TFUNCTION);
		reset(rhs.L, -1);
		lua_pop(L, 1);

		m_isValid = rhs.m_isValid;
	}
	return *this;
}

LuaFunction::LuaFunction(LuaFunction&& other) 
	: LuaRef()
	, m_isValid(true)
{
	*this = std::move(other);
}

LuaFunction::~LuaFunction()
{
	clear_ret();
}

LuaFunction& LuaFunction::operator=(LuaFunction&& rhs)
{
	if (this != &rhs)
	{
		unref();

		L = rhs.L;
		m_ref = rhs.m_ref;

		rhs.L = nullptr;
		rhs.m_ref = LUA_NOREF;

		m_isValid = rhs.m_isValid;
	}
	return *this;
}

void LuaFunction::operator()()
{
	ppush();
	pcall();
}

void LuaFunction::ppush()
{
	lua_getglobal(L, "__G__TRACKBACK__");
	m_trackback = lua_gettop(L);
	push();
	luaL_checktype(L, -1, LUA_TFUNCTION);
}

void LuaFunction::pcall(int nresults/* = 0*/)
{
	assert(nresults <= MAX_RET_ARGS_COUNT);
	clear_ret();

	int argc = lua_gettop(L) - m_trackback - 1;
	int r = lua_pcall(L, argc, nresults, m_trackback);

	m_retCount = nresults;
	if (r == 0 && nresults > 0)
	{
		int index = 0;
		for (int i = -nresults; i < 0; ++i)
		{
			int type = lua_type(L, i);
			switch (type)
			{
			case LUA_TNIL: 
			{
				m_retValues[index].type = type;
			}break;
			case LUA_TBOOLEAN: 
			{
				m_retValues[index].type = type;
				m_retValues[index].value.boolValue = (bool)lua_toboolean(L, i);
			}break;
			case LUA_TLIGHTUSERDATA:
			{
				m_retValues[index].type = type;
				m_retValues[index].value.userdata = *((void**)lua_touserdata(L, i));
			}break;
			case LUA_TNUMBER: 
			{
				m_retValues[index].type = type;
				m_retValues[index].value.numberValue = lua_tonumber(L, i);
			}break;
			case LUA_TSTRING: 
			{
				m_retValues[index].type = type;
				m_retValues[index].value.stringValue = new std::string(lua_tostring(L, i));
			}break;
			case LUA_TUSERDATA:
			{
				m_retValues[index].type = type;
				m_retValues[index].value.userdata = *((void**)lua_touserdata(L, i));
			}break;
			default:
				assert(0);
				break;
			}
			index++;
		}
	}

	// remove trackback and any thing above it.
	lua_settop(L, m_trackback - 1); 
}

void LuaFunction::pusharg(bool v)
{
	lua_pushboolean(L, v);
}

void LuaFunction::pusharg(float v)
{
	lua_pushnumber(L, v);
}

void LuaFunction::pusharg(double v)
{
	lua_pushnumber(L, v);
}

void LuaFunction::pusharg(int v)
{
	lua_pushinteger(L, v);
}

void LuaFunction::pusharg(unsigned int v)
{
	lua_pushinteger(L, v);
}

void LuaFunction::pusharg(const std::string& v)
{
	lua_pushlstring(L, v.data(), v.size());
}

void LuaFunction::pusharg(const char* v)
{
	lua_pushstring(L, v);
}

void LuaFunction::pushlstring(const char* v, unsigned int len)
{
	lua_pushlstring(L, v, len);
}

void LuaFunction::pushusertype(void* v, const char* type)
{
	tolua_pushusertype(L, (void*)v, type);
}

void LuaFunction::clear_ret()
{
	for (int i = 0; i < MAX_RET_ARGS_COUNT; ++i)
	{
		if (m_retValues[i].type == LUA_TSTRING)
		{
			delete m_retValues[i].value.stringValue;
		}
		m_retValues[i].type = LUA_TNONE;
	}
	m_retCount = 0;
}

bool LuaFunction::retbool(int index/* = 0*/, bool defaultvalue/* = false*/)
{
	assert(index < MAX_RET_ARGS_COUNT && index >= 0);
	if (index >= m_retCount)
	{
		return defaultvalue;
	}
	if (m_retValues[index].type == LUA_TBOOLEAN)
	{
		return m_retValues[index].value.boolValue;
	}
	if (m_retValues[index].type == LUA_TNIL)
	{
		return false;
	}
	return defaultvalue;
}

int LuaFunction::retint(int index/* = 0*/, int defaultvalue/* = 0*/)
{
	assert(index < MAX_RET_ARGS_COUNT && index >= 0);
	if (index >= m_retCount)
	{
		return defaultvalue;
	}
	if (m_retValues[index].type == LUA_TNUMBER)
	{
		return m_retValues[index].value.numberValue;
	}
	return defaultvalue;
}

std::string LuaFunction::retstring(int index/* = 0*/, const std::string& defaultvalue/* = ""*/)
{
	assert(index < MAX_RET_ARGS_COUNT && index >= 0);
	if (index >= m_retCount)
	{
		return defaultvalue;
	}
	if (m_retValues[index].type == LUA_TSTRING)
	{
		return *m_retValues[index].value.stringValue;
	}
	return defaultvalue;
}

void* LuaFunction::retuserdata(int index/* = 0*/)
{
	assert(index < MAX_RET_ARGS_COUNT && index >= 0);
	if (index >= m_retCount)
	{
		return NULL;
	}
	if (m_retValues[index].type == LUA_TUSERDATA)
	{
		return m_retValues[index].value.userdata;
	}
	return NULL;
}

void* LuaFunction::retlightuserdata(int index/* = 0*/)
{
	assert(index < MAX_RET_ARGS_COUNT && index >= 0);
	if (index >= m_retCount)
	{
		return NULL;
	}
	if (m_retValues[index].type == LUA_TLIGHTUSERDATA)
	{
		return m_retValues[index].value.userdata;
	}
	return NULL;
}

int LuaFunction::checktype(int index/* = 0*/)
{
	assert(index < MAX_RET_ARGS_COUNT && index >= 0);
	return m_retValues[index].type;
}