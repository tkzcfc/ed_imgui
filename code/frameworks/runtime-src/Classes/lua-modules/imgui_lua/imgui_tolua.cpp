/*
** Lua binding: main
** Generated automatically by tolua++-1.0.92 on Tue Oct  8 18:07:40 2019.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_main_open (lua_State* tolua_S);

#include "imgui.h"
#include "lua_function/LuaFunction.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_ImVec4 (lua_State* tolua_S)
{
 ImVec4* self = (ImVec4*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_ImVec2 (lua_State* tolua_S)
{
 ImVec2* self = (ImVec2*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"ImFont");
 tolua_usertype(tolua_S,"ImVec4");
 tolua_usertype(tolua_S,"ImGuiIO");
 tolua_usertype(tolua_S,"ImVec2");
 tolua_usertype(tolua_S,"ImDrawList");
 tolua_usertype(tolua_S,"ImGuiStyle");
}

/* get function: ConfigFlags of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_ConfigFlags
static int tolua_get_ImGuiIO_ConfigFlags(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ConfigFlags'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ConfigFlags);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ConfigFlags of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_ConfigFlags
static int tolua_set_ImGuiIO_ConfigFlags(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ConfigFlags'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ConfigFlags = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: BackendFlags of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_BackendFlags
static int tolua_get_ImGuiIO_BackendFlags(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'BackendFlags'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->BackendFlags);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: BackendFlags of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_BackendFlags
static int tolua_set_ImGuiIO_BackendFlags(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'BackendFlags'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->BackendFlags = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DisplaySize of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_DisplaySize
static int tolua_get_ImGuiIO_DisplaySize(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'DisplaySize'",NULL);
#endif
   tolua_ext_imvec2_value_to_luaval(tolua_S,self->DisplaySize,"ImVec2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: DisplaySize of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_DisplaySize
static int tolua_set_ImGuiIO_DisplaySize(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'DisplaySize'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->DisplaySize = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DeltaTime of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_DeltaTime
static int tolua_get_ImGuiIO_DeltaTime(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'DeltaTime'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->DeltaTime);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: DeltaTime of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_DeltaTime
static int tolua_set_ImGuiIO_DeltaTime(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'DeltaTime'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->DeltaTime = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: IniSavingRate of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_IniSavingRate
static int tolua_get_ImGuiIO_IniSavingRate(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'IniSavingRate'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->IniSavingRate);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: IniSavingRate of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_IniSavingRate
static int tolua_set_ImGuiIO_IniSavingRate(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'IniSavingRate'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->IniSavingRate = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: IniFilename of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_IniFilename
static int tolua_get_ImGuiIO_IniFilename(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'IniFilename'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->IniFilename);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: LogFilename of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_LogFilename
static int tolua_get_ImGuiIO_LogFilename(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LogFilename'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->LogFilename);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MouseDoubleClickTime of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_MouseDoubleClickTime
static int tolua_get_ImGuiIO_MouseDoubleClickTime(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MouseDoubleClickTime'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->MouseDoubleClickTime);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MouseDoubleClickTime of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_MouseDoubleClickTime
static int tolua_set_ImGuiIO_MouseDoubleClickTime(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MouseDoubleClickTime'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MouseDoubleClickTime = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MouseDoubleClickMaxDist of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_MouseDoubleClickMaxDist
static int tolua_get_ImGuiIO_MouseDoubleClickMaxDist(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MouseDoubleClickMaxDist'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->MouseDoubleClickMaxDist);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MouseDoubleClickMaxDist of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_MouseDoubleClickMaxDist
static int tolua_set_ImGuiIO_MouseDoubleClickMaxDist(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MouseDoubleClickMaxDist'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MouseDoubleClickMaxDist = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MouseDragThreshold of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_MouseDragThreshold
static int tolua_get_ImGuiIO_MouseDragThreshold(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MouseDragThreshold'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->MouseDragThreshold);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MouseDragThreshold of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_MouseDragThreshold
static int tolua_set_ImGuiIO_MouseDragThreshold(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MouseDragThreshold'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MouseDragThreshold = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KeyMap of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_main_ImGuiIO_KeyMap
static int tolua_get_main_ImGuiIO_KeyMap(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=ImGuiKey_COUNT)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->KeyMap[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: KeyMap of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_main_ImGuiIO_KeyMap
static int tolua_set_main_ImGuiIO_KeyMap(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=ImGuiKey_COUNT)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->KeyMap[tolua_index] = ((int)  tolua_tonumber(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KeyRepeatDelay of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_KeyRepeatDelay
static int tolua_get_ImGuiIO_KeyRepeatDelay(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'KeyRepeatDelay'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->KeyRepeatDelay);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: KeyRepeatDelay of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_KeyRepeatDelay
static int tolua_set_ImGuiIO_KeyRepeatDelay(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'KeyRepeatDelay'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->KeyRepeatDelay = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KeyRepeatRate of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_KeyRepeatRate
static int tolua_get_ImGuiIO_KeyRepeatRate(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'KeyRepeatRate'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->KeyRepeatRate);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: KeyRepeatRate of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_KeyRepeatRate
static int tolua_set_ImGuiIO_KeyRepeatRate(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'KeyRepeatRate'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->KeyRepeatRate = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: UserData of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_UserData
static int tolua_get_ImGuiIO_UserData(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'UserData'",NULL);
#endif
  tolua_pushuserdata(tolua_S,(void*)self->UserData);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: UserData of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_UserData
static int tolua_set_ImGuiIO_UserData(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'UserData'",NULL);
  if (!tolua_isuserdata(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->UserData = ((void*)  tolua_touserdata(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: FontGlobalScale of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_FontGlobalScale
static int tolua_get_ImGuiIO_FontGlobalScale(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FontGlobalScale'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->FontGlobalScale);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: FontGlobalScale of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_FontGlobalScale
static int tolua_set_ImGuiIO_FontGlobalScale(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FontGlobalScale'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->FontGlobalScale = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: FontAllowUserScaling of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_FontAllowUserScaling
static int tolua_get_ImGuiIO_FontAllowUserScaling(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FontAllowUserScaling'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->FontAllowUserScaling);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: FontAllowUserScaling of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_FontAllowUserScaling
static int tolua_set_ImGuiIO_FontAllowUserScaling(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FontAllowUserScaling'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->FontAllowUserScaling = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: FontDefault of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_FontDefault_ptr
static int tolua_get_ImGuiIO_FontDefault_ptr(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FontDefault'",NULL);
#endif
   tolua_ext_object_to_luaval<ImFont>(tolua_S,(void*)self->FontDefault,"ImFont");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: FontDefault of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_FontDefault_ptr
static int tolua_set_ImGuiIO_FontDefault_ptr(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FontDefault'",NULL);
  if (!tolua_isusertype(tolua_S,2,"ImFont",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->FontDefault = ((ImFont*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DisplayFramebufferScale of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_DisplayFramebufferScale
static int tolua_get_ImGuiIO_DisplayFramebufferScale(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'DisplayFramebufferScale'",NULL);
#endif
   tolua_ext_imvec2_value_to_luaval(tolua_S,self->DisplayFramebufferScale,"ImVec2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: DisplayFramebufferScale of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_DisplayFramebufferScale
static int tolua_set_ImGuiIO_DisplayFramebufferScale(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'DisplayFramebufferScale'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->DisplayFramebufferScale = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MouseDrawCursor of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_MouseDrawCursor
static int tolua_get_ImGuiIO_MouseDrawCursor(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MouseDrawCursor'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->MouseDrawCursor);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MouseDrawCursor of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_MouseDrawCursor
static int tolua_set_ImGuiIO_MouseDrawCursor(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MouseDrawCursor'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MouseDrawCursor = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ConfigMacOSXBehaviors of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_ConfigMacOSXBehaviors
static int tolua_get_ImGuiIO_ConfigMacOSXBehaviors(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ConfigMacOSXBehaviors'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->ConfigMacOSXBehaviors);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ConfigMacOSXBehaviors of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_ConfigMacOSXBehaviors
static int tolua_set_ImGuiIO_ConfigMacOSXBehaviors(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ConfigMacOSXBehaviors'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ConfigMacOSXBehaviors = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ConfigInputTextCursorBlink of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_ConfigInputTextCursorBlink
static int tolua_get_ImGuiIO_ConfigInputTextCursorBlink(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ConfigInputTextCursorBlink'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->ConfigInputTextCursorBlink);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ConfigInputTextCursorBlink of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_ConfigInputTextCursorBlink
static int tolua_set_ImGuiIO_ConfigInputTextCursorBlink(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ConfigInputTextCursorBlink'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ConfigInputTextCursorBlink = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ConfigWindowsResizeFromEdges of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_ConfigWindowsResizeFromEdges
static int tolua_get_ImGuiIO_ConfigWindowsResizeFromEdges(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ConfigWindowsResizeFromEdges'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->ConfigWindowsResizeFromEdges);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ConfigWindowsResizeFromEdges of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_ConfigWindowsResizeFromEdges
static int tolua_set_ImGuiIO_ConfigWindowsResizeFromEdges(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ConfigWindowsResizeFromEdges'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ConfigWindowsResizeFromEdges = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ConfigWindowsMoveFromTitleBarOnly of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_ConfigWindowsMoveFromTitleBarOnly
static int tolua_get_ImGuiIO_ConfigWindowsMoveFromTitleBarOnly(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ConfigWindowsMoveFromTitleBarOnly'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->ConfigWindowsMoveFromTitleBarOnly);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ConfigWindowsMoveFromTitleBarOnly of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_ConfigWindowsMoveFromTitleBarOnly
static int tolua_set_ImGuiIO_ConfigWindowsMoveFromTitleBarOnly(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ConfigWindowsMoveFromTitleBarOnly'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ConfigWindowsMoveFromTitleBarOnly = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MousePos of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_MousePos
static int tolua_get_ImGuiIO_MousePos(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MousePos'",NULL);
#endif
   tolua_ext_imvec2_value_to_luaval(tolua_S,self->MousePos,"ImVec2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MousePos of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_MousePos
static int tolua_set_ImGuiIO_MousePos(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MousePos'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MousePos = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MouseDown of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_main_ImGuiIO_MouseDown
static int tolua_get_main_ImGuiIO_MouseDown(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->MouseDown[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MouseDown of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_main_ImGuiIO_MouseDown
static int tolua_set_main_ImGuiIO_MouseDown(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->MouseDown[tolua_index] = ((bool)  tolua_toboolean(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MouseWheel of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_MouseWheel
static int tolua_get_ImGuiIO_MouseWheel(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MouseWheel'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->MouseWheel);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MouseWheel of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_MouseWheel
static int tolua_set_ImGuiIO_MouseWheel(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MouseWheel'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MouseWheel = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MouseWheelH of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_MouseWheelH
static int tolua_get_ImGuiIO_MouseWheelH(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MouseWheelH'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->MouseWheelH);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MouseWheelH of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_MouseWheelH
static int tolua_set_ImGuiIO_MouseWheelH(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MouseWheelH'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MouseWheelH = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KeyCtrl of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_KeyCtrl
static int tolua_get_ImGuiIO_KeyCtrl(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'KeyCtrl'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->KeyCtrl);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: KeyCtrl of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_KeyCtrl
static int tolua_set_ImGuiIO_KeyCtrl(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'KeyCtrl'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->KeyCtrl = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KeyShift of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_KeyShift
static int tolua_get_ImGuiIO_KeyShift(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'KeyShift'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->KeyShift);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: KeyShift of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_KeyShift
static int tolua_set_ImGuiIO_KeyShift(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'KeyShift'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->KeyShift = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KeyAlt of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_KeyAlt
static int tolua_get_ImGuiIO_KeyAlt(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'KeyAlt'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->KeyAlt);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: KeyAlt of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_KeyAlt
static int tolua_set_ImGuiIO_KeyAlt(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'KeyAlt'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->KeyAlt = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KeySuper of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_KeySuper
static int tolua_get_ImGuiIO_KeySuper(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'KeySuper'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->KeySuper);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: KeySuper of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_KeySuper
static int tolua_set_ImGuiIO_KeySuper(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'KeySuper'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->KeySuper = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KeysDown of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_main_ImGuiIO_KeysDown
static int tolua_get_main_ImGuiIO_KeysDown(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=512)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->KeysDown[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: KeysDown of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_main_ImGuiIO_KeysDown
static int tolua_set_main_ImGuiIO_KeysDown(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=512)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->KeysDown[tolua_index] = ((bool)  tolua_toboolean(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddInputCharacter of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_main_ImGuiIO_AddInputCharacter00
static int tolua_main_ImGuiIO_AddInputCharacter00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImGuiIO",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
  unsigned int c = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddInputCharacter'", NULL);
#endif
  {
   self->AddInputCharacter(c);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddInputCharacter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddInputCharactersUTF8 of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_main_ImGuiIO_AddInputCharactersUTF800
static int tolua_main_ImGuiIO_AddInputCharactersUTF800(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImGuiIO",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddInputCharactersUTF8'", NULL);
#endif
  {
   self->AddInputCharactersUTF8(str);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddInputCharactersUTF8'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearInputCharacters of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_main_ImGuiIO_ClearInputCharacters00
static int tolua_main_ImGuiIO_ClearInputCharacters00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImGuiIO",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearInputCharacters'", NULL);
#endif
  {
   self->ClearInputCharacters();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearInputCharacters'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WantCaptureMouse of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_WantCaptureMouse
static int tolua_get_ImGuiIO_WantCaptureMouse(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WantCaptureMouse'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->WantCaptureMouse);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: WantCaptureMouse of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_WantCaptureMouse
static int tolua_set_ImGuiIO_WantCaptureMouse(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WantCaptureMouse'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->WantCaptureMouse = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WantCaptureKeyboard of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_WantCaptureKeyboard
static int tolua_get_ImGuiIO_WantCaptureKeyboard(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WantCaptureKeyboard'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->WantCaptureKeyboard);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: WantCaptureKeyboard of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_WantCaptureKeyboard
static int tolua_set_ImGuiIO_WantCaptureKeyboard(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WantCaptureKeyboard'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->WantCaptureKeyboard = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WantTextInput of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_WantTextInput
static int tolua_get_ImGuiIO_WantTextInput(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WantTextInput'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->WantTextInput);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: WantTextInput of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_WantTextInput
static int tolua_set_ImGuiIO_WantTextInput(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WantTextInput'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->WantTextInput = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WantSetMousePos of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_WantSetMousePos
static int tolua_get_ImGuiIO_WantSetMousePos(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WantSetMousePos'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->WantSetMousePos);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: WantSetMousePos of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_WantSetMousePos
static int tolua_set_ImGuiIO_WantSetMousePos(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WantSetMousePos'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->WantSetMousePos = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WantSaveIniSettings of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_WantSaveIniSettings
static int tolua_get_ImGuiIO_WantSaveIniSettings(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WantSaveIniSettings'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->WantSaveIniSettings);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: WantSaveIniSettings of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_WantSaveIniSettings
static int tolua_set_ImGuiIO_WantSaveIniSettings(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WantSaveIniSettings'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->WantSaveIniSettings = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: NavActive of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_NavActive
static int tolua_get_ImGuiIO_NavActive(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'NavActive'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->NavActive);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: NavActive of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_NavActive
static int tolua_set_ImGuiIO_NavActive(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'NavActive'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->NavActive = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: NavVisible of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_NavVisible
static int tolua_get_ImGuiIO_NavVisible(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'NavVisible'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->NavVisible);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: NavVisible of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_NavVisible
static int tolua_set_ImGuiIO_NavVisible(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'NavVisible'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->NavVisible = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Framerate of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_Framerate
static int tolua_get_ImGuiIO_Framerate(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Framerate'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Framerate);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Framerate of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_Framerate
static int tolua_set_ImGuiIO_Framerate(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Framerate'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Framerate = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MetricsRenderVertices of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_MetricsRenderVertices
static int tolua_get_ImGuiIO_MetricsRenderVertices(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MetricsRenderVertices'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->MetricsRenderVertices);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MetricsRenderVertices of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_MetricsRenderVertices
static int tolua_set_ImGuiIO_MetricsRenderVertices(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MetricsRenderVertices'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MetricsRenderVertices = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MetricsRenderIndices of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_MetricsRenderIndices
static int tolua_get_ImGuiIO_MetricsRenderIndices(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MetricsRenderIndices'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->MetricsRenderIndices);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MetricsRenderIndices of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_MetricsRenderIndices
static int tolua_set_ImGuiIO_MetricsRenderIndices(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MetricsRenderIndices'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MetricsRenderIndices = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MetricsRenderWindows of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_MetricsRenderWindows
static int tolua_get_ImGuiIO_MetricsRenderWindows(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MetricsRenderWindows'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->MetricsRenderWindows);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MetricsRenderWindows of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_MetricsRenderWindows
static int tolua_set_ImGuiIO_MetricsRenderWindows(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MetricsRenderWindows'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MetricsRenderWindows = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MetricsActiveWindows of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_MetricsActiveWindows
static int tolua_get_ImGuiIO_MetricsActiveWindows(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MetricsActiveWindows'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->MetricsActiveWindows);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MetricsActiveWindows of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_MetricsActiveWindows
static int tolua_set_ImGuiIO_MetricsActiveWindows(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MetricsActiveWindows'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MetricsActiveWindows = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MetricsActiveAllocations of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_MetricsActiveAllocations
static int tolua_get_ImGuiIO_MetricsActiveAllocations(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MetricsActiveAllocations'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->MetricsActiveAllocations);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MetricsActiveAllocations of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_MetricsActiveAllocations
static int tolua_set_ImGuiIO_MetricsActiveAllocations(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MetricsActiveAllocations'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MetricsActiveAllocations = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MouseDelta of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_MouseDelta
static int tolua_get_ImGuiIO_MouseDelta(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MouseDelta'",NULL);
#endif
   tolua_ext_imvec2_value_to_luaval(tolua_S,self->MouseDelta,"ImVec2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MouseDelta of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_MouseDelta
static int tolua_set_ImGuiIO_MouseDelta(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MouseDelta'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MouseDelta = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MousePosPrev of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiIO_MousePosPrev
static int tolua_get_ImGuiIO_MousePosPrev(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MousePosPrev'",NULL);
#endif
   tolua_ext_imvec2_value_to_luaval(tolua_S,self->MousePosPrev,"ImVec2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MousePosPrev of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiIO_MousePosPrev
static int tolua_set_ImGuiIO_MousePosPrev(lua_State* tolua_S)
{
  ImGuiIO* self = (ImGuiIO*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MousePosPrev'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MousePosPrev = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MouseClickedTime of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_main_ImGuiIO_MouseClickedTime
static int tolua_get_main_ImGuiIO_MouseClickedTime(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->MouseClickedTime[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MouseClickedTime of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_main_ImGuiIO_MouseClickedTime
static int tolua_set_main_ImGuiIO_MouseClickedTime(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->MouseClickedTime[tolua_index] = ((double)  tolua_tonumber(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MouseClicked of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_main_ImGuiIO_MouseClicked
static int tolua_get_main_ImGuiIO_MouseClicked(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->MouseClicked[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MouseClicked of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_main_ImGuiIO_MouseClicked
static int tolua_set_main_ImGuiIO_MouseClicked(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->MouseClicked[tolua_index] = ((bool)  tolua_toboolean(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MouseDoubleClicked of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_main_ImGuiIO_MouseDoubleClicked
static int tolua_get_main_ImGuiIO_MouseDoubleClicked(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->MouseDoubleClicked[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MouseDoubleClicked of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_main_ImGuiIO_MouseDoubleClicked
static int tolua_set_main_ImGuiIO_MouseDoubleClicked(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->MouseDoubleClicked[tolua_index] = ((bool)  tolua_toboolean(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MouseReleased of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_main_ImGuiIO_MouseReleased
static int tolua_get_main_ImGuiIO_MouseReleased(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->MouseReleased[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MouseReleased of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_main_ImGuiIO_MouseReleased
static int tolua_set_main_ImGuiIO_MouseReleased(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->MouseReleased[tolua_index] = ((bool)  tolua_toboolean(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MouseDownOwned of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_main_ImGuiIO_MouseDownOwned
static int tolua_get_main_ImGuiIO_MouseDownOwned(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->MouseDownOwned[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MouseDownOwned of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_main_ImGuiIO_MouseDownOwned
static int tolua_set_main_ImGuiIO_MouseDownOwned(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->MouseDownOwned[tolua_index] = ((bool)  tolua_toboolean(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MouseDownWasDoubleClick of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_main_ImGuiIO_MouseDownWasDoubleClick
static int tolua_get_main_ImGuiIO_MouseDownWasDoubleClick(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->MouseDownWasDoubleClick[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MouseDownWasDoubleClick of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_main_ImGuiIO_MouseDownWasDoubleClick
static int tolua_set_main_ImGuiIO_MouseDownWasDoubleClick(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->MouseDownWasDoubleClick[tolua_index] = ((bool)  tolua_toboolean(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MouseDownDuration of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_main_ImGuiIO_MouseDownDuration
static int tolua_get_main_ImGuiIO_MouseDownDuration(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->MouseDownDuration[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MouseDownDuration of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_main_ImGuiIO_MouseDownDuration
static int tolua_set_main_ImGuiIO_MouseDownDuration(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->MouseDownDuration[tolua_index] = ((float)  tolua_tonumber(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MouseDownDurationPrev of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_main_ImGuiIO_MouseDownDurationPrev
static int tolua_get_main_ImGuiIO_MouseDownDurationPrev(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->MouseDownDurationPrev[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MouseDownDurationPrev of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_main_ImGuiIO_MouseDownDurationPrev
static int tolua_set_main_ImGuiIO_MouseDownDurationPrev(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->MouseDownDurationPrev[tolua_index] = ((float)  tolua_tonumber(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MouseDragMaxDistanceSqr of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_main_ImGuiIO_MouseDragMaxDistanceSqr
static int tolua_get_main_ImGuiIO_MouseDragMaxDistanceSqr(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->MouseDragMaxDistanceSqr[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MouseDragMaxDistanceSqr of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_main_ImGuiIO_MouseDragMaxDistanceSqr
static int tolua_set_main_ImGuiIO_MouseDragMaxDistanceSqr(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=5)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->MouseDragMaxDistanceSqr[tolua_index] = ((float)  tolua_tonumber(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KeysDownDuration of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_main_ImGuiIO_KeysDownDuration
static int tolua_get_main_ImGuiIO_KeysDownDuration(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=512)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->KeysDownDuration[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: KeysDownDuration of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_main_ImGuiIO_KeysDownDuration
static int tolua_set_main_ImGuiIO_KeysDownDuration(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=512)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->KeysDownDuration[tolua_index] = ((float)  tolua_tonumber(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KeysDownDurationPrev of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_get_main_ImGuiIO_KeysDownDurationPrev
static int tolua_get_main_ImGuiIO_KeysDownDurationPrev(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=512)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->KeysDownDurationPrev[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: KeysDownDurationPrev of class  ImGuiIO */
#ifndef TOLUA_DISABLE_tolua_set_main_ImGuiIO_KeysDownDurationPrev
static int tolua_set_main_ImGuiIO_KeysDownDurationPrev(lua_State* tolua_S)
{
 int tolua_index;
  ImGuiIO* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (ImGuiIO*)  lua_touserdata(tolua_S,-1);
#if COCOS2D_DEBUG >= 1
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#if COCOS2D_DEBUG >= 1
 if (tolua_index<0 || tolua_index>=512)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->KeysDownDurationPrev[tolua_index] = ((float)  tolua_tonumber(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Alpha of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_Alpha
static int tolua_get_ImGuiStyle_Alpha(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Alpha'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Alpha);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Alpha of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_Alpha
static int tolua_set_ImGuiStyle_Alpha(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Alpha'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Alpha = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WindowPadding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_WindowPadding
static int tolua_get_ImGuiStyle_WindowPadding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WindowPadding'",NULL);
#endif
   tolua_ext_imvec2_value_to_luaval(tolua_S,self->WindowPadding,"ImVec2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: WindowPadding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_WindowPadding
static int tolua_set_ImGuiStyle_WindowPadding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WindowPadding'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->WindowPadding = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WindowRounding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_WindowRounding
static int tolua_get_ImGuiStyle_WindowRounding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WindowRounding'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->WindowRounding);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: WindowRounding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_WindowRounding
static int tolua_set_ImGuiStyle_WindowRounding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WindowRounding'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->WindowRounding = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WindowBorderSize of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_WindowBorderSize
static int tolua_get_ImGuiStyle_WindowBorderSize(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WindowBorderSize'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->WindowBorderSize);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: WindowBorderSize of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_WindowBorderSize
static int tolua_set_ImGuiStyle_WindowBorderSize(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WindowBorderSize'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->WindowBorderSize = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WindowMinSize of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_WindowMinSize
static int tolua_get_ImGuiStyle_WindowMinSize(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WindowMinSize'",NULL);
#endif
   tolua_ext_imvec2_value_to_luaval(tolua_S,self->WindowMinSize,"ImVec2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: WindowMinSize of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_WindowMinSize
static int tolua_set_ImGuiStyle_WindowMinSize(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WindowMinSize'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->WindowMinSize = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WindowTitleAlign of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_WindowTitleAlign
static int tolua_get_ImGuiStyle_WindowTitleAlign(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WindowTitleAlign'",NULL);
#endif
   tolua_ext_imvec2_value_to_luaval(tolua_S,self->WindowTitleAlign,"ImVec2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: WindowTitleAlign of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_WindowTitleAlign
static int tolua_set_ImGuiStyle_WindowTitleAlign(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WindowTitleAlign'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->WindowTitleAlign = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WindowMenuButtonPosition of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_WindowMenuButtonPosition
static int tolua_get_ImGuiStyle_WindowMenuButtonPosition(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WindowMenuButtonPosition'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->WindowMenuButtonPosition);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: WindowMenuButtonPosition of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_WindowMenuButtonPosition
static int tolua_set_ImGuiStyle_WindowMenuButtonPosition(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WindowMenuButtonPosition'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->WindowMenuButtonPosition = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ChildRounding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_ChildRounding
static int tolua_get_ImGuiStyle_ChildRounding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ChildRounding'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ChildRounding);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ChildRounding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_ChildRounding
static int tolua_set_ImGuiStyle_ChildRounding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ChildRounding'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ChildRounding = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ChildBorderSize of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_ChildBorderSize
static int tolua_get_ImGuiStyle_ChildBorderSize(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ChildBorderSize'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ChildBorderSize);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ChildBorderSize of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_ChildBorderSize
static int tolua_set_ImGuiStyle_ChildBorderSize(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ChildBorderSize'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ChildBorderSize = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: PopupRounding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_PopupRounding
static int tolua_get_ImGuiStyle_PopupRounding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PopupRounding'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->PopupRounding);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: PopupRounding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_PopupRounding
static int tolua_set_ImGuiStyle_PopupRounding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PopupRounding'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->PopupRounding = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: PopupBorderSize of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_PopupBorderSize
static int tolua_get_ImGuiStyle_PopupBorderSize(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PopupBorderSize'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->PopupBorderSize);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: PopupBorderSize of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_PopupBorderSize
static int tolua_set_ImGuiStyle_PopupBorderSize(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PopupBorderSize'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->PopupBorderSize = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: FramePadding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_FramePadding
static int tolua_get_ImGuiStyle_FramePadding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FramePadding'",NULL);
#endif
   tolua_ext_imvec2_value_to_luaval(tolua_S,self->FramePadding,"ImVec2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: FramePadding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_FramePadding
static int tolua_set_ImGuiStyle_FramePadding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FramePadding'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->FramePadding = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: FrameRounding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_FrameRounding
static int tolua_get_ImGuiStyle_FrameRounding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FrameRounding'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->FrameRounding);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: FrameRounding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_FrameRounding
static int tolua_set_ImGuiStyle_FrameRounding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FrameRounding'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->FrameRounding = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: FrameBorderSize of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_FrameBorderSize
static int tolua_get_ImGuiStyle_FrameBorderSize(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FrameBorderSize'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->FrameBorderSize);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: FrameBorderSize of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_FrameBorderSize
static int tolua_set_ImGuiStyle_FrameBorderSize(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FrameBorderSize'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->FrameBorderSize = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ItemSpacing of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_ItemSpacing
static int tolua_get_ImGuiStyle_ItemSpacing(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ItemSpacing'",NULL);
#endif
   tolua_ext_imvec2_value_to_luaval(tolua_S,self->ItemSpacing,"ImVec2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ItemSpacing of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_ItemSpacing
static int tolua_set_ImGuiStyle_ItemSpacing(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ItemSpacing'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ItemSpacing = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ItemInnerSpacing of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_ItemInnerSpacing
static int tolua_get_ImGuiStyle_ItemInnerSpacing(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ItemInnerSpacing'",NULL);
#endif
   tolua_ext_imvec2_value_to_luaval(tolua_S,self->ItemInnerSpacing,"ImVec2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ItemInnerSpacing of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_ItemInnerSpacing
static int tolua_set_ImGuiStyle_ItemInnerSpacing(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ItemInnerSpacing'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ItemInnerSpacing = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: TouchExtraPadding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_TouchExtraPadding
static int tolua_get_ImGuiStyle_TouchExtraPadding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TouchExtraPadding'",NULL);
#endif
   tolua_ext_imvec2_value_to_luaval(tolua_S,self->TouchExtraPadding,"ImVec2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: TouchExtraPadding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_TouchExtraPadding
static int tolua_set_ImGuiStyle_TouchExtraPadding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TouchExtraPadding'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->TouchExtraPadding = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: IndentSpacing of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_IndentSpacing
static int tolua_get_ImGuiStyle_IndentSpacing(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'IndentSpacing'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->IndentSpacing);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: IndentSpacing of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_IndentSpacing
static int tolua_set_ImGuiStyle_IndentSpacing(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'IndentSpacing'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->IndentSpacing = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ColumnsMinSpacing of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_ColumnsMinSpacing
static int tolua_get_ImGuiStyle_ColumnsMinSpacing(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ColumnsMinSpacing'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ColumnsMinSpacing);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ColumnsMinSpacing of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_ColumnsMinSpacing
static int tolua_set_ImGuiStyle_ColumnsMinSpacing(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ColumnsMinSpacing'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ColumnsMinSpacing = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ScrollbarSize of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_ScrollbarSize
static int tolua_get_ImGuiStyle_ScrollbarSize(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ScrollbarSize'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ScrollbarSize);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ScrollbarSize of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_ScrollbarSize
static int tolua_set_ImGuiStyle_ScrollbarSize(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ScrollbarSize'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ScrollbarSize = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ScrollbarRounding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_ScrollbarRounding
static int tolua_get_ImGuiStyle_ScrollbarRounding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ScrollbarRounding'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ScrollbarRounding);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ScrollbarRounding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_ScrollbarRounding
static int tolua_set_ImGuiStyle_ScrollbarRounding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ScrollbarRounding'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ScrollbarRounding = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: GrabMinSize of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_GrabMinSize
static int tolua_get_ImGuiStyle_GrabMinSize(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'GrabMinSize'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->GrabMinSize);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: GrabMinSize of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_GrabMinSize
static int tolua_set_ImGuiStyle_GrabMinSize(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'GrabMinSize'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->GrabMinSize = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: GrabRounding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_GrabRounding
static int tolua_get_ImGuiStyle_GrabRounding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'GrabRounding'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->GrabRounding);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: GrabRounding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_GrabRounding
static int tolua_set_ImGuiStyle_GrabRounding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'GrabRounding'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->GrabRounding = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: LayoutAlign of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_LayoutAlign
static int tolua_get_ImGuiStyle_LayoutAlign(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LayoutAlign'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->LayoutAlign);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: LayoutAlign of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_LayoutAlign
static int tolua_set_ImGuiStyle_LayoutAlign(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LayoutAlign'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->LayoutAlign = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: TabRounding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_TabRounding
static int tolua_get_ImGuiStyle_TabRounding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TabRounding'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->TabRounding);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: TabRounding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_TabRounding
static int tolua_set_ImGuiStyle_TabRounding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TabRounding'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->TabRounding = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: TabBorderSize of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_TabBorderSize
static int tolua_get_ImGuiStyle_TabBorderSize(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TabBorderSize'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->TabBorderSize);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: TabBorderSize of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_TabBorderSize
static int tolua_set_ImGuiStyle_TabBorderSize(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TabBorderSize'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->TabBorderSize = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ButtonTextAlign of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_ButtonTextAlign
static int tolua_get_ImGuiStyle_ButtonTextAlign(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ButtonTextAlign'",NULL);
#endif
   tolua_ext_imvec2_value_to_luaval(tolua_S,self->ButtonTextAlign,"ImVec2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ButtonTextAlign of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_ButtonTextAlign
static int tolua_set_ImGuiStyle_ButtonTextAlign(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ButtonTextAlign'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ButtonTextAlign = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SelectableTextAlign of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_SelectableTextAlign
static int tolua_get_ImGuiStyle_SelectableTextAlign(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'SelectableTextAlign'",NULL);
#endif
   tolua_ext_imvec2_value_to_luaval(tolua_S,self->SelectableTextAlign,"ImVec2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: SelectableTextAlign of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_SelectableTextAlign
static int tolua_set_ImGuiStyle_SelectableTextAlign(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'SelectableTextAlign'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SelectableTextAlign = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DisplayWindowPadding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_DisplayWindowPadding
static int tolua_get_ImGuiStyle_DisplayWindowPadding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'DisplayWindowPadding'",NULL);
#endif
   tolua_ext_imvec2_value_to_luaval(tolua_S,self->DisplayWindowPadding,"ImVec2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: DisplayWindowPadding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_DisplayWindowPadding
static int tolua_set_ImGuiStyle_DisplayWindowPadding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'DisplayWindowPadding'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->DisplayWindowPadding = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DisplaySafeAreaPadding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_DisplaySafeAreaPadding
static int tolua_get_ImGuiStyle_DisplaySafeAreaPadding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'DisplaySafeAreaPadding'",NULL);
#endif
   tolua_ext_imvec2_value_to_luaval(tolua_S,self->DisplaySafeAreaPadding,"ImVec2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: DisplaySafeAreaPadding of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_DisplaySafeAreaPadding
static int tolua_set_ImGuiStyle_DisplaySafeAreaPadding(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'DisplaySafeAreaPadding'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->DisplaySafeAreaPadding = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MouseCursorScale of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_MouseCursorScale
static int tolua_get_ImGuiStyle_MouseCursorScale(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MouseCursorScale'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->MouseCursorScale);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MouseCursorScale of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_MouseCursorScale
static int tolua_set_ImGuiStyle_MouseCursorScale(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MouseCursorScale'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MouseCursorScale = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: AntiAliasedLines of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_AntiAliasedLines
static int tolua_get_ImGuiStyle_AntiAliasedLines(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AntiAliasedLines'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->AntiAliasedLines);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: AntiAliasedLines of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_AntiAliasedLines
static int tolua_set_ImGuiStyle_AntiAliasedLines(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AntiAliasedLines'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->AntiAliasedLines = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: AntiAliasedFill of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_AntiAliasedFill
static int tolua_get_ImGuiStyle_AntiAliasedFill(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AntiAliasedFill'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->AntiAliasedFill);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: AntiAliasedFill of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_AntiAliasedFill
static int tolua_set_ImGuiStyle_AntiAliasedFill(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AntiAliasedFill'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->AntiAliasedFill = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CurveTessellationTol of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_get_ImGuiStyle_CurveTessellationTol
static int tolua_get_ImGuiStyle_CurveTessellationTol(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CurveTessellationTol'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->CurveTessellationTol);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: CurveTessellationTol of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_set_ImGuiStyle_CurveTessellationTol
static int tolua_set_ImGuiStyle_CurveTessellationTol(lua_State* tolua_S)
{
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CurveTessellationTol'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->CurveTessellationTol = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: ScaleAllSizes of class  ImGuiStyle */
#ifndef TOLUA_DISABLE_tolua_main_ImGuiStyle_ScaleAllSizes00
static int tolua_main_ImGuiStyle_ScaleAllSizes00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImGuiStyle",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImGuiStyle* self = (ImGuiStyle*)  tolua_tousertype(tolua_S,1,0);
  float scale_factor = ((float)  tolua_tonumber(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ScaleAllSizes'", NULL);
#endif
  {
   self->ScaleAllSizes(scale_factor);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ScaleAllSizes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: FallbackAdvanceX of class  ImFont */
#ifndef TOLUA_DISABLE_tolua_get_ImFont_FallbackAdvanceX
static int tolua_get_ImFont_FallbackAdvanceX(lua_State* tolua_S)
{
  ImFont* self = (ImFont*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FallbackAdvanceX'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->FallbackAdvanceX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: FallbackAdvanceX of class  ImFont */
#ifndef TOLUA_DISABLE_tolua_set_ImFont_FallbackAdvanceX
static int tolua_set_ImFont_FallbackAdvanceX(lua_State* tolua_S)
{
  ImFont* self = (ImFont*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FallbackAdvanceX'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->FallbackAdvanceX = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: FontSize of class  ImFont */
#ifndef TOLUA_DISABLE_tolua_get_ImFont_FontSize
static int tolua_get_ImFont_FontSize(lua_State* tolua_S)
{
  ImFont* self = (ImFont*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FontSize'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->FontSize);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: FontSize of class  ImFont */
#ifndef TOLUA_DISABLE_tolua_set_ImFont_FontSize
static int tolua_set_ImFont_FontSize(lua_State* tolua_S)
{
  ImFont* self = (ImFont*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FontSize'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->FontSize = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ConfigDataCount of class  ImFont */
#ifndef TOLUA_DISABLE_tolua_get_ImFont_ConfigDataCount
static int tolua_get_ImFont_ConfigDataCount(lua_State* tolua_S)
{
  ImFont* self = (ImFont*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ConfigDataCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ConfigDataCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ConfigDataCount of class  ImFont */
#ifndef TOLUA_DISABLE_tolua_set_ImFont_ConfigDataCount
static int tolua_set_ImFont_ConfigDataCount(lua_State* tolua_S)
{
  ImFont* self = (ImFont*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ConfigDataCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ConfigDataCount = ((short)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Scale of class  ImFont */
#ifndef TOLUA_DISABLE_tolua_get_ImFont_Scale
static int tolua_get_ImFont_Scale(lua_State* tolua_S)
{
  ImFont* self = (ImFont*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Scale'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Scale);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Scale of class  ImFont */
#ifndef TOLUA_DISABLE_tolua_set_ImFont_Scale
static int tolua_set_ImFont_Scale(lua_State* tolua_S)
{
  ImFont* self = (ImFont*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Scale'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Scale = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Ascent of class  ImFont */
#ifndef TOLUA_DISABLE_tolua_get_ImFont_Ascent
static int tolua_get_ImFont_Ascent(lua_State* tolua_S)
{
  ImFont* self = (ImFont*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Ascent'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Ascent);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Ascent of class  ImFont */
#ifndef TOLUA_DISABLE_tolua_set_ImFont_Ascent
static int tolua_set_ImFont_Ascent(lua_State* tolua_S)
{
  ImFont* self = (ImFont*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Ascent'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Ascent = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Descent of class  ImFont */
#ifndef TOLUA_DISABLE_tolua_get_ImFont_Descent
static int tolua_get_ImFont_Descent(lua_State* tolua_S)
{
  ImFont* self = (ImFont*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Descent'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Descent);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Descent of class  ImFont */
#ifndef TOLUA_DISABLE_tolua_set_ImFont_Descent
static int tolua_set_ImFont_Descent(lua_State* tolua_S)
{
  ImFont* self = (ImFont*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Descent'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Descent = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MetricsTotalSurface of class  ImFont */
#ifndef TOLUA_DISABLE_tolua_get_ImFont_MetricsTotalSurface
static int tolua_get_ImFont_MetricsTotalSurface(lua_State* tolua_S)
{
  ImFont* self = (ImFont*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MetricsTotalSurface'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->MetricsTotalSurface);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MetricsTotalSurface of class  ImFont */
#ifndef TOLUA_DISABLE_tolua_set_ImFont_MetricsTotalSurface
static int tolua_set_ImFont_MetricsTotalSurface(lua_State* tolua_S)
{
  ImFont* self = (ImFont*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MetricsTotalSurface'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MetricsTotalSurface = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DirtyLookupTables of class  ImFont */
#ifndef TOLUA_DISABLE_tolua_get_ImFont_DirtyLookupTables
static int tolua_get_ImFont_DirtyLookupTables(lua_State* tolua_S)
{
  ImFont* self = (ImFont*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'DirtyLookupTables'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->DirtyLookupTables);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: DirtyLookupTables of class  ImFont */
#ifndef TOLUA_DISABLE_tolua_set_ImFont_DirtyLookupTables
static int tolua_set_ImFont_DirtyLookupTables(lua_State* tolua_S)
{
  ImFont* self = (ImFont*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'DirtyLookupTables'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->DirtyLookupTables = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _VtxCurrentOffset of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_get_ImDrawList_unsigned__VtxCurrentOffset
static int tolua_get_ImDrawList_unsigned__VtxCurrentOffset(lua_State* tolua_S)
{
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_VtxCurrentOffset'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->_VtxCurrentOffset);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _VtxCurrentOffset of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_set_ImDrawList_unsigned__VtxCurrentOffset
static int tolua_set_ImDrawList_unsigned__VtxCurrentOffset(lua_State* tolua_S)
{
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_VtxCurrentOffset'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->_VtxCurrentOffset = ((unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _VtxCurrentIdx of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_get_ImDrawList_unsigned__VtxCurrentIdx
static int tolua_get_ImDrawList_unsigned__VtxCurrentIdx(lua_State* tolua_S)
{
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_VtxCurrentIdx'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->_VtxCurrentIdx);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _VtxCurrentIdx of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_set_ImDrawList_unsigned__VtxCurrentIdx
static int tolua_set_ImDrawList_unsigned__VtxCurrentIdx(lua_State* tolua_S)
{
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_VtxCurrentIdx'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->_VtxCurrentIdx = ((unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: _FringeScale of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_get_ImDrawList__FringeScale
static int tolua_get_ImDrawList__FringeScale(lua_State* tolua_S)
{
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_FringeScale'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->_FringeScale);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: _FringeScale of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_set_ImDrawList__FringeScale
static int tolua_set_ImDrawList__FringeScale(lua_State* tolua_S)
{
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '_FringeScale'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->_FringeScale = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: PushClipRect of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_PushClipRect00
static int tolua_main_ImDrawList_PushClipRect00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 clip_rect_min = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  ImVec2 clip_rect_max = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  bool intersect_with_current_clip_rect = ((bool)  tolua_toboolean(tolua_S,4,false));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PushClipRect'", NULL);
#endif
  {
   self->PushClipRect(clip_rect_min,clip_rect_max,intersect_with_current_clip_rect);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PushClipRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PushClipRectFullScreen of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_PushClipRectFullScreen00
static int tolua_main_ImDrawList_PushClipRectFullScreen00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PushClipRectFullScreen'", NULL);
#endif
  {
   self->PushClipRectFullScreen();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PushClipRectFullScreen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PopClipRect of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_PopClipRect00
static int tolua_main_ImDrawList_PopClipRect00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PopClipRect'", NULL);
#endif
  {
   self->PopClipRect();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PopClipRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PopTextureID of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_PopTextureID00
static int tolua_main_ImDrawList_PopTextureID00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PopTextureID'", NULL);
#endif
  {
   self->PopTextureID();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PopTextureID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetClipRectMin of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_GetClipRectMin00
static int tolua_main_ImDrawList_GetClipRectMin00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ImDrawList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ImDrawList* self = (const ImDrawList*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetClipRectMin'", NULL);
#endif
  {
   ImVec2 tolua_ret = (ImVec2)  self->GetClipRectMin();
   {
   tolua_ext_imvec2_value_to_luaval(tolua_S, tolua_ret, "ImVec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetClipRectMin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetClipRectMax of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_GetClipRectMax00
static int tolua_main_ImDrawList_GetClipRectMax00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ImDrawList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ImDrawList* self = (const ImDrawList*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetClipRectMax'", NULL);
#endif
  {
   ImVec2 tolua_ret = (ImVec2)  self->GetClipRectMax();
   {
   tolua_ext_imvec2_value_to_luaval(tolua_S, tolua_ret, "ImVec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetClipRectMax'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddLine of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_AddLine00
static int tolua_main_ImDrawList_AddLine00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  ImVec2 b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
  float thickness = ((float)  tolua_tonumber(tolua_S,5,1.0f));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddLine'", NULL);
#endif
  {
   self->AddLine(a,b,col,thickness);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddRect of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_AddRect00
static int tolua_main_ImDrawList_AddRect00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  ImVec2 b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
  float rounding = ((float)  tolua_tonumber(tolua_S,5,0.0f));
  int rounding_corners_flags = ((int)  tolua_tonumber(tolua_S,6,ImDrawCornerFlags_All));
  float thickness = ((float)  tolua_tonumber(tolua_S,7,1.0f));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddRect'", NULL);
#endif
  {
   self->AddRect(a,b,col,rounding,rounding_corners_flags,thickness);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddRectFilled of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_AddRectFilled00
static int tolua_main_ImDrawList_AddRectFilled00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  ImVec2 b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
  float rounding = ((float)  tolua_tonumber(tolua_S,5,0.0f));
  int rounding_corners_flags = ((int)  tolua_tonumber(tolua_S,6,ImDrawCornerFlags_All));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddRectFilled'", NULL);
#endif
  {
   self->AddRectFilled(a,b,col,rounding,rounding_corners_flags);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddRectFilled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddRectFilledMultiColor of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_AddRectFilledMultiColor00
static int tolua_main_ImDrawList_AddRectFilledMultiColor00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  ImVec2 b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  unsigned int col_upr_left = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
  unsigned int col_upr_right = ((unsigned int)  tolua_tonumber(tolua_S,5,0));
  unsigned int col_bot_right = ((unsigned int)  tolua_tonumber(tolua_S,6,0));
  unsigned int col_bot_left = ((unsigned int)  tolua_tonumber(tolua_S,7,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddRectFilledMultiColor'", NULL);
#endif
  {
   self->AddRectFilledMultiColor(a,b,col_upr_left,col_upr_right,col_bot_right,col_bot_left);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddRectFilledMultiColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddQuad of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_AddQuad00
static int tolua_main_ImDrawList_AddQuad00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_ext_check_is_table(tolua_S,5,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  ImVec2 b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  ImVec2 c = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
  ImVec2 d = (  tolua_ext_luaval_to_imvec2_value(tolua_S,5,0));
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,6,0));
  float thickness = ((float)  tolua_tonumber(tolua_S,7,1.0f));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddQuad'", NULL);
#endif
  {
   self->AddQuad(a,b,c,d,col,thickness);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddQuad'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddQuadFilled of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_AddQuadFilled00
static int tolua_main_ImDrawList_AddQuadFilled00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_ext_check_is_table(tolua_S,5,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  ImVec2 b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  ImVec2 c = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
  ImVec2 d = (  tolua_ext_luaval_to_imvec2_value(tolua_S,5,0));
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,6,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddQuadFilled'", NULL);
#endif
  {
   self->AddQuadFilled(a,b,c,d,col);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddQuadFilled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddTriangle of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_AddTriangle00
static int tolua_main_ImDrawList_AddTriangle00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  ImVec2 b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  ImVec2 c = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,5,0));
  float thickness = ((float)  tolua_tonumber(tolua_S,6,1.0f));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddTriangle'", NULL);
#endif
  {
   self->AddTriangle(a,b,c,col,thickness);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddTriangle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddTriangleFilled of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_AddTriangleFilled00
static int tolua_main_ImDrawList_AddTriangleFilled00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  ImVec2 b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  ImVec2 c = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,5,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddTriangleFilled'", NULL);
#endif
  {
   self->AddTriangleFilled(a,b,c,col);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddTriangleFilled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddCircle of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_AddCircle00
static int tolua_main_ImDrawList_AddCircle00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 centre = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  float radius = ((float)  tolua_tonumber(tolua_S,3,0));
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
  int num_segments = ((int)  tolua_tonumber(tolua_S,5,12));
  float thickness = ((float)  tolua_tonumber(tolua_S,6,1.0f));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddCircle'", NULL);
#endif
  {
   self->AddCircle(centre,radius,col,num_segments,thickness);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddCircle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddCircleFilled of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_AddCircleFilled00
static int tolua_main_ImDrawList_AddCircleFilled00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 centre = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  float radius = ((float)  tolua_tonumber(tolua_S,3,0));
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
  int num_segments = ((int)  tolua_tonumber(tolua_S,5,12));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddCircleFilled'", NULL);
#endif
  {
   self->AddCircleFilled(centre,radius,col,num_segments);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddCircleFilled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddText of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_AddText00
static int tolua_main_ImDrawList_AddText00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 pos = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  const char* text_begin = ((const char*)  tolua_tostring(tolua_S,4,0));
  const char* text_end = ((const char*)  tolua_tostring(tolua_S,5,NULL));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddText'", NULL);
#endif
  {
   self->AddText(pos,col,text_begin,text_end);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddImage of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_AddImage00
static int tolua_main_ImDrawList_AddImage00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  void* user_texture_id = ((void*)  tolua_touserdata(tolua_S,2,0));
  ImVec2 a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  ImVec2 b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddImage'", NULL);
#endif
  {
   self->AddImage(user_texture_id,a,b);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddImage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddImage of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_AddImage01
static int tolua_main_ImDrawList_AddImage01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_ext_check_is_table(tolua_S,5,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  void* user_texture_id = ((void*)  tolua_touserdata(tolua_S,2,0));
  ImVec2 a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  ImVec2 b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
  ImVec2 uv_a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,5,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddImage'", NULL);
#endif
  {
   self->AddImage(user_texture_id,a,b,uv_a);
  }
 }
 return 0;
tolua_lerror:
 return tolua_main_ImDrawList_AddImage00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddImage of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_AddImage02
static int tolua_main_ImDrawList_AddImage02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_ext_check_is_table(tolua_S,5,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_ext_check_is_table(tolua_S,6,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  void* user_texture_id = ((void*)  tolua_touserdata(tolua_S,2,0));
  ImVec2 a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  ImVec2 b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
  ImVec2 uv_a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,5,0));
  ImVec2 uv_b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,6,0));
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,7,IM_COL32_WHITE));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddImage'", NULL);
#endif
  {
   self->AddImage(user_texture_id,a,b,uv_a,uv_b,col);
  }
 }
 return 0;
tolua_lerror:
 return tolua_main_ImDrawList_AddImage01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddImageQuad of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_AddImageQuad00
static int tolua_main_ImDrawList_AddImageQuad00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_ext_check_is_table(tolua_S,5,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_ext_check_is_table(tolua_S,6,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  void* user_texture_id = ((void*)  tolua_touserdata(tolua_S,2,0));
  ImVec2 a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  ImVec2 b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
  ImVec2 c = (  tolua_ext_luaval_to_imvec2_value(tolua_S,5,0));
  ImVec2 d = (  tolua_ext_luaval_to_imvec2_value(tolua_S,6,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddImageQuad'", NULL);
#endif
  {
   self->AddImageQuad(user_texture_id,a,b,c,d);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddImageQuad'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddImageQuad of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_AddImageQuad01
static int tolua_main_ImDrawList_AddImageQuad01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_ext_check_is_table(tolua_S,5,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_ext_check_is_table(tolua_S,6,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_ext_check_is_table(tolua_S,7,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  void* user_texture_id = ((void*)  tolua_touserdata(tolua_S,2,0));
  ImVec2 a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  ImVec2 b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
  ImVec2 c = (  tolua_ext_luaval_to_imvec2_value(tolua_S,5,0));
  ImVec2 d = (  tolua_ext_luaval_to_imvec2_value(tolua_S,6,0));
  ImVec2 uv_a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,7,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddImageQuad'", NULL);
#endif
  {
   self->AddImageQuad(user_texture_id,a,b,c,d,uv_a);
  }
 }
 return 0;
tolua_lerror:
 return tolua_main_ImDrawList_AddImageQuad00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddImageQuad of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_AddImageQuad02
static int tolua_main_ImDrawList_AddImageQuad02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_ext_check_is_table(tolua_S,5,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_ext_check_is_table(tolua_S,6,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_ext_check_is_table(tolua_S,7,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,8,&tolua_err) || !tolua_ext_check_is_table(tolua_S,8,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  void* user_texture_id = ((void*)  tolua_touserdata(tolua_S,2,0));
  ImVec2 a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  ImVec2 b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
  ImVec2 c = (  tolua_ext_luaval_to_imvec2_value(tolua_S,5,0));
  ImVec2 d = (  tolua_ext_luaval_to_imvec2_value(tolua_S,6,0));
  ImVec2 uv_a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,7,0));
  ImVec2 uv_b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,8,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddImageQuad'", NULL);
#endif
  {
   self->AddImageQuad(user_texture_id,a,b,c,d,uv_a,uv_b);
  }
 }
 return 0;
tolua_lerror:
 return tolua_main_ImDrawList_AddImageQuad01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddImageQuad of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_AddImageQuad03
static int tolua_main_ImDrawList_AddImageQuad03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_ext_check_is_table(tolua_S,5,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_ext_check_is_table(tolua_S,6,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_ext_check_is_table(tolua_S,7,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,8,&tolua_err) || !tolua_ext_check_is_table(tolua_S,8,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,9,&tolua_err) || !tolua_ext_check_is_table(tolua_S,9,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  void* user_texture_id = ((void*)  tolua_touserdata(tolua_S,2,0));
  ImVec2 a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  ImVec2 b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
  ImVec2 c = (  tolua_ext_luaval_to_imvec2_value(tolua_S,5,0));
  ImVec2 d = (  tolua_ext_luaval_to_imvec2_value(tolua_S,6,0));
  ImVec2 uv_a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,7,0));
  ImVec2 uv_b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,8,0));
  ImVec2 uv_c = (  tolua_ext_luaval_to_imvec2_value(tolua_S,9,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddImageQuad'", NULL);
#endif
  {
   self->AddImageQuad(user_texture_id,a,b,c,d,uv_a,uv_b,uv_c);
  }
 }
 return 0;
tolua_lerror:
 return tolua_main_ImDrawList_AddImageQuad02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddImageQuad of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_AddImageQuad04
static int tolua_main_ImDrawList_AddImageQuad04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_ext_check_is_table(tolua_S,5,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_ext_check_is_table(tolua_S,6,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_ext_check_is_table(tolua_S,7,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,8,&tolua_err) || !tolua_ext_check_is_table(tolua_S,8,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,9,&tolua_err) || !tolua_ext_check_is_table(tolua_S,9,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,10,&tolua_err) || !tolua_ext_check_is_table(tolua_S,10,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,11,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,12,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  void* user_texture_id = ((void*)  tolua_touserdata(tolua_S,2,0));
  ImVec2 a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  ImVec2 b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
  ImVec2 c = (  tolua_ext_luaval_to_imvec2_value(tolua_S,5,0));
  ImVec2 d = (  tolua_ext_luaval_to_imvec2_value(tolua_S,6,0));
  ImVec2 uv_a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,7,0));
  ImVec2 uv_b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,8,0));
  ImVec2 uv_c = (  tolua_ext_luaval_to_imvec2_value(tolua_S,9,0));
  ImVec2 uv_d = (  tolua_ext_luaval_to_imvec2_value(tolua_S,10,0));
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,11,IM_COL32_WHITE));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddImageQuad'", NULL);
#endif
  {
   self->AddImageQuad(user_texture_id,a,b,c,d,uv_a,uv_b,uv_c,uv_d,col);
  }
 }
 return 0;
tolua_lerror:
 return tolua_main_ImDrawList_AddImageQuad03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddImageRounded of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_AddImageRounded00
static int tolua_main_ImDrawList_AddImageRounded00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_ext_check_is_table(tolua_S,5,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_ext_check_is_table(tolua_S,6,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  void* user_texture_id = ((void*)  tolua_touserdata(tolua_S,2,0));
  ImVec2 a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  ImVec2 b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
  ImVec2 uv_a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,5,0));
  ImVec2 uv_b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,6,0));
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,7,0));
  float rounding = ((float)  tolua_tonumber(tolua_S,8,0));
  int rounding_corners = ((int)  tolua_tonumber(tolua_S,9,ImDrawCornerFlags_All));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddImageRounded'", NULL);
#endif
  {
   self->AddImageRounded(user_texture_id,a,b,uv_a,uv_b,col,rounding,rounding_corners);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddImageRounded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddBezierCurve of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_AddBezierCurve00
static int tolua_main_ImDrawList_AddBezierCurve00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_ext_check_is_table(tolua_S,5,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 pos0 = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  ImVec2 cp0 = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  ImVec2 cp1 = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
  ImVec2 pos1 = (  tolua_ext_luaval_to_imvec2_value(tolua_S,5,0));
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,6,0));
  float thickness = ((float)  tolua_tonumber(tolua_S,7,0));
  int num_segments = ((int)  tolua_tonumber(tolua_S,8,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddBezierCurve'", NULL);
#endif
  {
   self->AddBezierCurve(pos0,cp0,cp1,pos1,col,thickness,num_segments);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddBezierCurve'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PathClear of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_PathClear00
static int tolua_main_ImDrawList_PathClear00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PathClear'", NULL);
#endif
  {
   self->PathClear();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PathClear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PathLineTo of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_PathLineTo00
static int tolua_main_ImDrawList_PathLineTo00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 pos = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PathLineTo'", NULL);
#endif
  {
   self->PathLineTo(pos);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PathLineTo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PathLineToMergeDuplicate of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_PathLineToMergeDuplicate00
static int tolua_main_ImDrawList_PathLineToMergeDuplicate00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 pos = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PathLineToMergeDuplicate'", NULL);
#endif
  {
   self->PathLineToMergeDuplicate(pos);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PathLineToMergeDuplicate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PathFillConvex of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_PathFillConvex00
static int tolua_main_ImDrawList_PathFillConvex00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PathFillConvex'", NULL);
#endif
  {
   self->PathFillConvex(col);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PathFillConvex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PathStroke of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_PathStroke00
static int tolua_main_ImDrawList_PathStroke00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  bool closed = ((bool)  tolua_toboolean(tolua_S,3,0));
  float thickness = ((float)  tolua_tonumber(tolua_S,4,1.0f));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PathStroke'", NULL);
#endif
  {
   self->PathStroke(col,closed,thickness);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PathStroke'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PathArcTo of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_PathArcTo00
static int tolua_main_ImDrawList_PathArcTo00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 centre = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  float radius = ((float)  tolua_tonumber(tolua_S,3,0));
  float a_min = ((float)  tolua_tonumber(tolua_S,4,0));
  float a_max = ((float)  tolua_tonumber(tolua_S,5,0));
  int num_segments = ((int)  tolua_tonumber(tolua_S,6,10));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PathArcTo'", NULL);
#endif
  {
   self->PathArcTo(centre,radius,a_min,a_max,num_segments);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PathArcTo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PathArcToFast of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_PathArcToFast00
static int tolua_main_ImDrawList_PathArcToFast00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 centre = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  float radius = ((float)  tolua_tonumber(tolua_S,3,0));
  int a_min_of_12 = ((int)  tolua_tonumber(tolua_S,4,0));
  int a_max_of_12 = ((int)  tolua_tonumber(tolua_S,5,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PathArcToFast'", NULL);
#endif
  {
   self->PathArcToFast(centre,radius,a_min_of_12,a_max_of_12);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PathArcToFast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PathBezierCurveTo of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_PathBezierCurveTo00
static int tolua_main_ImDrawList_PathBezierCurveTo00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 p1 = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  ImVec2 p2 = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  ImVec2 p3 = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
  int num_segments = ((int)  tolua_tonumber(tolua_S,5,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PathBezierCurveTo'", NULL);
#endif
  {
   self->PathBezierCurveTo(p1,p2,p3,num_segments);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PathBezierCurveTo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PathRect of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_PathRect00
static int tolua_main_ImDrawList_PathRect00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 rect_min = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  ImVec2 rect_max = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  float rounding = ((float)  tolua_tonumber(tolua_S,4,0.0f));
  int rounding_corners_flags = ((int)  tolua_tonumber(tolua_S,5,ImDrawCornerFlags_All));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PathRect'", NULL);
#endif
  {
   self->PathRect(rect_min,rect_max,rounding,rounding_corners_flags);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PathRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ChannelsSplit of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_ChannelsSplit00
static int tolua_main_ImDrawList_ChannelsSplit00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  int count = ((int)  tolua_tonumber(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ChannelsSplit'", NULL);
#endif
  {
   self->ChannelsSplit(count);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChannelsSplit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ChannelsMerge of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_ChannelsMerge00
static int tolua_main_ImDrawList_ChannelsMerge00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ChannelsMerge'", NULL);
#endif
  {
   self->ChannelsMerge();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChannelsMerge'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ChannelsSetCurrent of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_ChannelsSetCurrent00
static int tolua_main_ImDrawList_ChannelsSetCurrent00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  int n = ((int)  tolua_tonumber(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ChannelsSetCurrent'", NULL);
#endif
  {
   self->ChannelsSetCurrent(n);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChannelsSetCurrent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_Clear00
static int tolua_main_ImDrawList_Clear00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearFreeMemory of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_ClearFreeMemory00
static int tolua_main_ImDrawList_ClearFreeMemory00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearFreeMemory'", NULL);
#endif
  {
   self->ClearFreeMemory();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearFreeMemory'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PrimReserve of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_PrimReserve00
static int tolua_main_ImDrawList_PrimReserve00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  int idx_count = ((int)  tolua_tonumber(tolua_S,2,0));
  int vtx_count = ((int)  tolua_tonumber(tolua_S,3,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PrimReserve'", NULL);
#endif
  {
   self->PrimReserve(idx_count,vtx_count);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PrimReserve'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PrimRect of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_PrimRect00
static int tolua_main_ImDrawList_PrimRect00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  ImVec2 b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PrimRect'", NULL);
#endif
  {
   self->PrimRect(a,b,col);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PrimRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PrimRectUV of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_PrimRectUV00
static int tolua_main_ImDrawList_PrimRectUV00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_ext_check_is_table(tolua_S,5,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  ImVec2 b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  ImVec2 uv_a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
  ImVec2 uv_b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,5,0));
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,6,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PrimRectUV'", NULL);
#endif
  {
   self->PrimRectUV(a,b,uv_a,uv_b,col);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PrimRectUV'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PrimQuadUV of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_PrimQuadUV00
static int tolua_main_ImDrawList_PrimQuadUV00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_ext_check_is_table(tolua_S,5,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_ext_check_is_table(tolua_S,6,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_ext_check_is_table(tolua_S,7,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,8,&tolua_err) || !tolua_ext_check_is_table(tolua_S,8,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,9,&tolua_err) || !tolua_ext_check_is_table(tolua_S,9,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,11,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  ImVec2 b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  ImVec2 c = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
  ImVec2 d = (  tolua_ext_luaval_to_imvec2_value(tolua_S,5,0));
  ImVec2 uv_a = (  tolua_ext_luaval_to_imvec2_value(tolua_S,6,0));
  ImVec2 uv_b = (  tolua_ext_luaval_to_imvec2_value(tolua_S,7,0));
  ImVec2 uv_c = (  tolua_ext_luaval_to_imvec2_value(tolua_S,8,0));
  ImVec2 uv_d = (  tolua_ext_luaval_to_imvec2_value(tolua_S,9,0));
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,10,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PrimQuadUV'", NULL);
#endif
  {
   self->PrimQuadUV(a,b,c,d,uv_a,uv_b,uv_c,uv_d,col);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PrimQuadUV'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PrimWriteVtx of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_PrimWriteVtx00
static int tolua_main_ImDrawList_PrimWriteVtx00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 pos = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  ImVec2 uv = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PrimWriteVtx'", NULL);
#endif
  {
   self->PrimWriteVtx(pos,uv,col);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PrimWriteVtx'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PrimVtx of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_PrimVtx00
static int tolua_main_ImDrawList_PrimVtx00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
  ImVec2 pos = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  ImVec2 uv = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PrimVtx'", NULL);
#endif
  {
   self->PrimVtx(pos,uv,col);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PrimVtx'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UpdateClipRect of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_UpdateClipRect00
static int tolua_main_ImDrawList_UpdateClipRect00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UpdateClipRect'", NULL);
#endif
  {
   self->UpdateClipRect();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UpdateClipRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UpdateTextureID of class  ImDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImDrawList_UpdateTextureID00
static int tolua_main_ImDrawList_UpdateTextureID00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImDrawList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImDrawList* self = (ImDrawList*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UpdateTextureID'", NULL);
#endif
  {
   self->UpdateTextureID();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UpdateTextureID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::ShowDemoWindow */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_ShowDemoWindow00
static int tolua_main_ImGui_ShowDemoWindow00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isboolean(tolua_S,1,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  bool p_open = ((bool)  tolua_toboolean(tolua_S,1,NULL));
  {
   ImGui::ShowDemoWindow(&p_open);
   tolua_pushboolean(tolua_S,(bool)p_open);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ShowDemoWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::ShowAboutWindow */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_ShowAboutWindow00
static int tolua_main_ImGui_ShowAboutWindow00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isboolean(tolua_S,1,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  bool p_open = ((bool)  tolua_toboolean(tolua_S,1,NULL));
  {
   ImGui::ShowAboutWindow(&p_open);
   tolua_pushboolean(tolua_S,(bool)p_open);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ShowAboutWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::ShowMetricsWindow */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_ShowMetricsWindow00
static int tolua_main_ImGui_ShowMetricsWindow00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isboolean(tolua_S,1,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  bool p_open = ((bool)  tolua_toboolean(tolua_S,1,NULL));
  {
   ImGui::ShowMetricsWindow(&p_open);
   tolua_pushboolean(tolua_S,(bool)p_open);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ShowMetricsWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::ShowStyleSelector */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_ShowStyleSelector00
static int tolua_main_ImGui_ShowStyleSelector00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  ImGui::ShowStyleSelector(label);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ShowStyleSelector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::ShowFontSelector */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_ShowFontSelector00
static int tolua_main_ImGui_ShowFontSelector00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   ImGui::ShowFontSelector(label);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ShowFontSelector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::ShowUserGuide */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_ShowUserGuide00
static int tolua_main_ImGui_ShowUserGuide00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::ShowUserGuide();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ShowUserGuide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetVersion */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetVersion00
static int tolua_main_ImGui_GetVersion00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  ImGui::GetVersion();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BeginMainMenuBar */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BeginMainMenuBar00
static int tolua_main_ImGui_BeginMainMenuBar00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  ImGui::BeginMainMenuBar();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginMainMenuBar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::EndMainMenuBar */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_EndMainMenuBar00
static int tolua_main_ImGui_EndMainMenuBar00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::EndMainMenuBar();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EndMainMenuBar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BeginMenuBar */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BeginMenuBar00
static int tolua_main_ImGui_BeginMenuBar00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  ImGui::BeginMenuBar();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginMenuBar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::EndMenuBar */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_EndMenuBar00
static int tolua_main_ImGui_EndMenuBar00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::EndMenuBar();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EndMenuBar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BeginMenu */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BeginMenu00
static int tolua_main_ImGui_BeginMenu00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  bool enabled = ((bool)  tolua_toboolean(tolua_S,2,true));
  {
   bool tolua_ret = (bool)  ImGui::BeginMenu(label,enabled);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginMenu'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::EndMenu */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_EndMenu00
static int tolua_main_ImGui_EndMenu00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::EndMenu();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EndMenu'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::MenuItem */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_MenuItem00
static int tolua_main_ImGui_MenuItem00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* shortcut = ((const char*)  tolua_tostring(tolua_S,2,NULL));
  bool selected = ((bool)  tolua_toboolean(tolua_S,3,false));
  bool enabled = ((bool)  tolua_toboolean(tolua_S,4,true));
  {
   bool tolua_ret = (bool)  ImGui::MenuItem(label,shortcut,selected,enabled);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MenuItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::MenuItem */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_MenuItem01
static int tolua_main_ImGui_MenuItem01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* shortcut = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool p_selected = ((bool)  tolua_toboolean(tolua_S,3,0));
  bool enabled = ((bool)  tolua_toboolean(tolua_S,4,true));
  {
   bool tolua_ret = (bool)  ImGui::MenuItem(label,shortcut,&p_selected,enabled);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushboolean(tolua_S,(bool)p_selected);
  }
 }
 return 2;
tolua_lerror:
 return tolua_main_ImGui_MenuItem00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BeginTooltip */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BeginTooltip00
static int tolua_main_ImGui_BeginTooltip00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::BeginTooltip();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginTooltip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::EndTooltip */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_EndTooltip00
static int tolua_main_ImGui_EndTooltip00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::EndTooltip();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EndTooltip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetTooltip */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetTooltip00
static int tolua_main_ImGui_SetTooltip00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* fmt = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   ImGui::SetTooltip(fmt);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTooltip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::OpenPopup */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_OpenPopup00
static int tolua_main_ImGui_OpenPopup00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* str_id = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   ImGui::OpenPopup(str_id);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OpenPopup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BeginPopup */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BeginPopup00
static int tolua_main_ImGui_BeginPopup00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* str_id = ((const char*)  tolua_tostring(tolua_S,1,0));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  ImGui::BeginPopup(str_id,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginPopup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BeginPopupContextItem */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BeginPopupContextItem00
static int tolua_main_ImGui_BeginPopupContextItem00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* str_id = ((const char*)  tolua_tostring(tolua_S,1,NULL));
  int mouse_button = ((int)  tolua_tonumber(tolua_S,2,1));
  {
   bool tolua_ret = (bool)  ImGui::BeginPopupContextItem(str_id,mouse_button);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginPopupContextItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BeginPopupContextWindow */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BeginPopupContextWindow00
static int tolua_main_ImGui_BeginPopupContextWindow00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* str_id = ((const char*)  tolua_tostring(tolua_S,1,NULL));
  int mouse_button = ((int)  tolua_tonumber(tolua_S,2,1));
  bool also_over_items = ((bool)  tolua_toboolean(tolua_S,3,true));
  {
   bool tolua_ret = (bool)  ImGui::BeginPopupContextWindow(str_id,mouse_button,also_over_items);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginPopupContextWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BeginPopupContextVoid */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BeginPopupContextVoid00
static int tolua_main_ImGui_BeginPopupContextVoid00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* str_id = ((const char*)  tolua_tostring(tolua_S,1,NULL));
  int mouse_button = ((int)  tolua_tonumber(tolua_S,2,1));
  {
   bool tolua_ret = (bool)  ImGui::BeginPopupContextVoid(str_id,mouse_button);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginPopupContextVoid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BeginPopupModal */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BeginPopupModal00
static int tolua_main_ImGui_BeginPopupModal00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,1,0));
  bool p_open = ((bool)  tolua_toboolean(tolua_S,2,NULL));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  ImGui::BeginPopupModal(name,&p_open,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushboolean(tolua_S,(bool)p_open);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginPopupModal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::EndPopup */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_EndPopup00
static int tolua_main_ImGui_EndPopup00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::EndPopup();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EndPopup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::OpenPopupOnItemClick */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_OpenPopupOnItemClick00
static int tolua_main_ImGui_OpenPopupOnItemClick00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* str_id = ((const char*)  tolua_tostring(tolua_S,1,NULL));
  int mouse_button = ((int)  tolua_tonumber(tolua_S,2,1));
  {
   bool tolua_ret = (bool)  ImGui::OpenPopupOnItemClick(str_id,mouse_button);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OpenPopupOnItemClick'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsPopupOpen */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsPopupOpen00
static int tolua_main_ImGui_IsPopupOpen00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* str_id = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  ImGui::IsPopupOpen(str_id);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsPopupOpen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::CloseCurrentPopup */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_CloseCurrentPopup00
static int tolua_main_ImGui_CloseCurrentPopup00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::CloseCurrentPopup();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CloseCurrentPopup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::Separator */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_Separator00
static int tolua_main_ImGui_Separator00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::Separator();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Separator'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SameLine */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SameLine00
static int tolua_main_ImGui_SameLine00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float offset_from_start_x = ((float)  tolua_tonumber(tolua_S,1,0.0f));
  float spacing = ((float)  tolua_tonumber(tolua_S,2,-1.0f));
  {
   ImGui::SameLine(offset_from_start_x,spacing);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SameLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::NewLine */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_NewLine00
static int tolua_main_ImGui_NewLine00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::NewLine();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'NewLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::Spacing */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_Spacing00
static int tolua_main_ImGui_Spacing00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::Spacing();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Spacing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::Dummy */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_Dummy00
static int tolua_main_ImGui_Dummy00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_ext_check_is_table(tolua_S,1,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,1,0));
  {
   ImGui::Dummy(size);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Dummy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::Indent */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_Indent00
static int tolua_main_ImGui_Indent00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float indent_w = ((float)  tolua_tonumber(tolua_S,1,0.0f));
  {
   ImGui::Indent(indent_w);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Indent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::Unindent */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_Unindent00
static int tolua_main_ImGui_Unindent00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float indent_w = ((float)  tolua_tonumber(tolua_S,1,0.0f));
  {
   ImGui::Unindent(indent_w);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Unindent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BeginGroup */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BeginGroup00
static int tolua_main_ImGui_BeginGroup00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::BeginGroup();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginGroup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::EndGroup */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_EndGroup00
static int tolua_main_ImGui_EndGroup00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::EndGroup();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EndGroup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetCursorPos */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetCursorPos00
static int tolua_main_ImGui_GetCursorPos00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImVec2 tolua_ret = (ImVec2)  ImGui::GetCursorPos();
   {
   tolua_ext_imvec2_value_to_luaval(tolua_S, tolua_ret, "ImVec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCursorPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetCursorPosX */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetCursorPosX00
static int tolua_main_ImGui_GetCursorPosX00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  ImGui::GetCursorPosX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCursorPosX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetCursorPosY */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetCursorPosY00
static int tolua_main_ImGui_GetCursorPosY00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  ImGui::GetCursorPosY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCursorPosY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetCursorPos */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetCursorPos00
static int tolua_main_ImGui_SetCursorPos00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_ext_check_is_table(tolua_S,1,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImVec2 local_pos = (  tolua_ext_luaval_to_imvec2_value(tolua_S,1,0));
  {
   ImGui::SetCursorPos(local_pos);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCursorPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetCursorPosX */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetCursorPosX00
static int tolua_main_ImGui_SetCursorPosX00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float local_x = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   ImGui::SetCursorPosX(local_x);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCursorPosX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetCursorPosY */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetCursorPosY00
static int tolua_main_ImGui_SetCursorPosY00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float local_y = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   ImGui::SetCursorPosY(local_y);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCursorPosY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetCursorStartPos */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetCursorStartPos00
static int tolua_main_ImGui_GetCursorStartPos00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImVec2 tolua_ret = (ImVec2)  ImGui::GetCursorStartPos();
   {
   tolua_ext_imvec2_value_to_luaval(tolua_S, tolua_ret, "ImVec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCursorStartPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetCursorScreenPos */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetCursorScreenPos00
static int tolua_main_ImGui_GetCursorScreenPos00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImVec2 tolua_ret = (ImVec2)  ImGui::GetCursorScreenPos();
   {
   tolua_ext_imvec2_value_to_luaval(tolua_S, tolua_ret, "ImVec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCursorScreenPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetCursorScreenPos */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetCursorScreenPos00
static int tolua_main_ImGui_SetCursorScreenPos00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_ext_check_is_table(tolua_S,1,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImVec2 pos = (  tolua_ext_luaval_to_imvec2_value(tolua_S,1,0));
  {
   ImGui::SetCursorScreenPos(pos);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCursorScreenPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::AlignTextToFramePadding */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_AlignTextToFramePadding00
static int tolua_main_ImGui_AlignTextToFramePadding00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::AlignTextToFramePadding();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AlignTextToFramePadding'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetTextLineHeight */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetTextLineHeight00
static int tolua_main_ImGui_GetTextLineHeight00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  ImGui::GetTextLineHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextLineHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetTextLineHeightWithSpacing */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetTextLineHeightWithSpacing00
static int tolua_main_ImGui_GetTextLineHeightWithSpacing00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  ImGui::GetTextLineHeightWithSpacing();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextLineHeightWithSpacing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetFrameHeight */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetFrameHeight00
static int tolua_main_ImGui_GetFrameHeight00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  ImGui::GetFrameHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFrameHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetFrameHeightWithSpacing */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetFrameHeightWithSpacing00
static int tolua_main_ImGui_GetFrameHeightWithSpacing00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  ImGui::GetFrameHeightWithSpacing();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFrameHeightWithSpacing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BeginHorizontal */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BeginHorizontal00
static int tolua_main_ImGui_BeginHorizontal00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* str_id = ((const char*)  tolua_tostring(tolua_S,1,0));
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  float align = ((float)  tolua_tonumber(tolua_S,3,-1.0f));
  {
   ImGui::BeginHorizontal(str_id,size,align);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginHorizontal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BeginHorizontal */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BeginHorizontal01
static int tolua_main_ImGui_BeginHorizontal01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int id = ((int)  tolua_tonumber(tolua_S,1,0));
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  float align = ((float)  tolua_tonumber(tolua_S,3,-1));
  {
   ImGui::BeginHorizontal(id,size,align);
  }
 }
 return 0;
tolua_lerror:
 return tolua_main_ImGui_BeginHorizontal00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::EndHorizontal */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_EndHorizontal00
static int tolua_main_ImGui_EndHorizontal00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::EndHorizontal();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EndHorizontal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BeginVertical */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BeginVertical00
static int tolua_main_ImGui_BeginVertical00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* str_id = ((const char*)  tolua_tostring(tolua_S,1,0));
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  float align = ((float)  tolua_tonumber(tolua_S,3,-1.0f));
  {
   ImGui::BeginVertical(str_id,size,align);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginVertical'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BeginVertical */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BeginVertical01
static int tolua_main_ImGui_BeginVertical01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isuserdata(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const void* ptr_id = ((const void*)  tolua_touserdata(tolua_S,1,0));
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  float align = ((float)  tolua_tonumber(tolua_S,3,-1.0f));
  {
   ImGui::BeginVertical(ptr_id,size,align);
  }
 }
 return 0;
tolua_lerror:
 return tolua_main_ImGui_BeginVertical00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BeginVertical */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BeginVertical02
static int tolua_main_ImGui_BeginVertical02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int id = ((int)  tolua_tonumber(tolua_S,1,0));
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  float align = ((float)  tolua_tonumber(tolua_S,3,-1));
  {
   ImGui::BeginVertical(id,size,align);
  }
 }
 return 0;
tolua_lerror:
 return tolua_main_ImGui_BeginVertical01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::EndVertical */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_EndVertical00
static int tolua_main_ImGui_EndVertical00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::EndVertical();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EndVertical'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::Spring */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_Spring00
static int tolua_main_ImGui_Spring00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float weight = ((float)  tolua_tonumber(tolua_S,1,1.0f));
  float spacing = ((float)  tolua_tonumber(tolua_S,2,-1.0f));
  {
   ImGui::Spring(weight,spacing);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Spring'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SuspendLayout */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SuspendLayout00
static int tolua_main_ImGui_SuspendLayout00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::SuspendLayout();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SuspendLayout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::ResumeLayout */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_ResumeLayout00
static int tolua_main_ImGui_ResumeLayout00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::ResumeLayout();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResumeLayout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BeginTabBar */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BeginTabBar00
static int tolua_main_ImGui_BeginTabBar00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* str_id = ((const char*)  tolua_tostring(tolua_S,1,0));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  ImGui::BeginTabBar(str_id,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginTabBar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::EndTabBar */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_EndTabBar00
static int tolua_main_ImGui_EndTabBar00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::EndTabBar();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EndTabBar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BeginTabItem */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BeginTabItem00
static int tolua_main_ImGui_BeginTabItem00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  bool p_open = ((bool)  tolua_toboolean(tolua_S,2,NULL));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  ImGui::BeginTabItem(label,&p_open,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushboolean(tolua_S,(bool)p_open);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginTabItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::EndTabItem */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_EndTabItem00
static int tolua_main_ImGui_EndTabItem00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::EndTabItem();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EndTabItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetTabItemClosed */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetTabItemClosed00
static int tolua_main_ImGui_SetTabItemClosed00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* tab_or_docked_window_label = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   ImGui::SetTabItemClosed(tab_or_docked_window_label);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTabItemClosed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::TextUnformatted */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_TextUnformatted00
static int tolua_main_ImGui_TextUnformatted00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* text = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* text_end = ((const char*)  tolua_tostring(tolua_S,2,NULL));
  {
   ImGui::TextUnformatted(text,text_end);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TextUnformatted'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::Text */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_Text00
static int tolua_main_ImGui_Text00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* fmt = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   ImGui::Text(fmt);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Text'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::TextColored */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_TextColored00
static int tolua_main_ImGui_TextColored00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_ext_check_is_table(tolua_S,1,"ImVec4",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImVec4 col = (  tolua_ext_luaval_to_imvec4_value(tolua_S,1,0));
  const char* fmt = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   ImGui::TextColored(col,fmt);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TextColored'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::TextDisabled */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_TextDisabled00
static int tolua_main_ImGui_TextDisabled00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* fmt = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   ImGui::TextDisabled(fmt);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TextDisabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::TextWrapped */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_TextWrapped00
static int tolua_main_ImGui_TextWrapped00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* fmt = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   ImGui::TextWrapped(fmt);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TextWrapped'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::LabelText */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_LabelText00
static int tolua_main_ImGui_LabelText00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* fmt = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   ImGui::LabelText(label,fmt);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LabelText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BulletText */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BulletText00
static int tolua_main_ImGui_BulletText00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* fmt = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   ImGui::BulletText(fmt);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BulletText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::InputText */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_InputText00
static int tolua_main_ImGui_InputText00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  char* buf = ((char*)  tolua_tostring(tolua_S,2,0));
  unsigned int buf_size = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  ImGui::InputText(label,buf,buf_size,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InputText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::InputTextMultiline */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_InputTextMultiline00
static int tolua_main_ImGui_InputTextMultiline00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  char* buf = ((char*)  tolua_tostring(tolua_S,2,0));
  unsigned int buf_size = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,5,0));
  {
   bool tolua_ret = (bool)  ImGui::InputTextMultiline(label,buf,buf_size,size,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InputTextMultiline'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::InputFloat */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_InputFloat00
static int tolua_main_ImGui_InputFloat00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isstring(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  float v = ((float)  tolua_tonumber(tolua_S,2,0));
  float step = ((float)  tolua_tonumber(tolua_S,3,0.0f));
  float step_fast = ((float)  tolua_tonumber(tolua_S,4,0.0f));
  const char* format = ((const char*)  tolua_tostring(tolua_S,5,"%.3f"));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,6,0));
  {
   bool tolua_ret = (bool)  ImGui::InputFloat(label,&v,step,step_fast,format,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)v);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InputFloat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::InputFloat2 */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_InputFloat200
static int tolua_main_ImGui_InputFloat200(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  float v[2];
  const char* format = ((const char*)  tolua_tostring(tolua_S,3,"%.3f"));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
  {
#if COCOS2D_DEBUG >= 1
   if (!tolua_isnumberarray(tolua_S,2,2,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<2;i++)
    v[i] = ((float)  tolua_tofieldnumber(tolua_S,2,i+1,0));
   }
  }
  {
   bool tolua_ret = (bool)  ImGui::InputFloat2(label,v,format,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
  {
   int i;
   for(i=0; i<2;i++)
    tolua_pushfieldnumber(tolua_S,2,i+1,(lua_Number) v[i]);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InputFloat2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::InputFloat3 */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_InputFloat300
static int tolua_main_ImGui_InputFloat300(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  float v[3];
  const char* format = ((const char*)  tolua_tostring(tolua_S,3,"%.3f"));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
  {
#if COCOS2D_DEBUG >= 1
   if (!tolua_isnumberarray(tolua_S,2,3,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<3;i++)
    v[i] = ((float)  tolua_tofieldnumber(tolua_S,2,i+1,0));
   }
  }
  {
   bool tolua_ret = (bool)  ImGui::InputFloat3(label,v,format,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
  {
   int i;
   for(i=0; i<3;i++)
    tolua_pushfieldnumber(tolua_S,2,i+1,(lua_Number) v[i]);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InputFloat3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::InputFloat4 */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_InputFloat400
static int tolua_main_ImGui_InputFloat400(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  float v[4];
  const char* format = ((const char*)  tolua_tostring(tolua_S,3,"%.3f"));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
  {
#if COCOS2D_DEBUG >= 1
   if (!tolua_isnumberarray(tolua_S,2,4,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<4;i++)
    v[i] = ((float)  tolua_tofieldnumber(tolua_S,2,i+1,0));
   }
  }
  {
   bool tolua_ret = (bool)  ImGui::InputFloat4(label,v,format,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
  {
   int i;
   for(i=0; i<4;i++)
    tolua_pushfieldnumber(tolua_S,2,i+1,(lua_Number) v[i]);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InputFloat4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::InputInt */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_InputInt00
static int tolua_main_ImGui_InputInt00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  int v = ((int)  tolua_tonumber(tolua_S,2,0));
  int step = ((int)  tolua_tonumber(tolua_S,3,1));
  int step_fast = ((int)  tolua_tonumber(tolua_S,4,100));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,5,0));
  {
   bool tolua_ret = (bool)  ImGui::InputInt(label,&v,step,step_fast,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)v);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InputInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::InputInt2 */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_InputInt200
static int tolua_main_ImGui_InputInt200(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  int v[2];
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  {
#if COCOS2D_DEBUG >= 1
   if (!tolua_isnumberarray(tolua_S,2,2,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<2;i++)
    v[i] = ((int)  tolua_tofieldnumber(tolua_S,2,i+1,0));
   }
  }
  {
   bool tolua_ret = (bool)  ImGui::InputInt2(label,v,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
  {
   int i;
   for(i=0; i<2;i++)
    tolua_pushfieldnumber(tolua_S,2,i+1,(lua_Number) v[i]);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InputInt2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::InputInt3 */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_InputInt300
static int tolua_main_ImGui_InputInt300(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  int v[3];
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  {
#if COCOS2D_DEBUG >= 1
   if (!tolua_isnumberarray(tolua_S,2,3,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<3;i++)
    v[i] = ((int)  tolua_tofieldnumber(tolua_S,2,i+1,0));
   }
  }
  {
   bool tolua_ret = (bool)  ImGui::InputInt3(label,v,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
  {
   int i;
   for(i=0; i<3;i++)
    tolua_pushfieldnumber(tolua_S,2,i+1,(lua_Number) v[i]);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InputInt3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::InputInt4 */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_InputInt400
static int tolua_main_ImGui_InputInt400(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  int v[4];
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  {
#if COCOS2D_DEBUG >= 1
   if (!tolua_isnumberarray(tolua_S,2,4,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<4;i++)
    v[i] = ((int)  tolua_tofieldnumber(tolua_S,2,i+1,0));
   }
  }
  {
   bool tolua_ret = (bool)  ImGui::InputInt4(label,v,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
  {
   int i;
   for(i=0; i<4;i++)
    tolua_pushfieldnumber(tolua_S,2,i+1,(lua_Number) v[i]);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InputInt4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::InputDouble */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_InputDouble00
static int tolua_main_ImGui_InputDouble00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isstring(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  double v = ((double)  tolua_tonumber(tolua_S,2,0));
  double step = ((double)  tolua_tonumber(tolua_S,3,0.0));
  double step_fast = ((double)  tolua_tonumber(tolua_S,4,0.0));
  const char* format = ((const char*)  tolua_tostring(tolua_S,5,"%.6f"));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,6,0));
  {
   bool tolua_ret = (bool)  ImGui::InputDouble(label,&v,step,step_fast,format,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)v);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InputDouble'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::InputScalar */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_InputScalar00
static int tolua_main_ImGui_InputScalar00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,3,0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,4,1,&tolua_err) ||
     !tolua_isuserdata(tolua_S,5,1,&tolua_err) ||
     !tolua_isstring(tolua_S,6,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  int data_type = ((int)  tolua_tonumber(tolua_S,2,0));
  void* v = ((void*)  tolua_touserdata(tolua_S,3,0));
  const void* step = ((const void*)  tolua_touserdata(tolua_S,4,NULL));
  const void* step_fast = ((const void*)  tolua_touserdata(tolua_S,5,NULL));
  const char* format = ((const char*)  tolua_tostring(tolua_S,6,NULL));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,7,0));
  {
   bool tolua_ret = (bool)  ImGui::InputScalar(label,data_type,v,step,step_fast,format,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InputScalar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::InputScalarN */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_InputScalarN00
static int tolua_main_ImGui_InputScalarN00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,5,1,&tolua_err) ||
     !tolua_isuserdata(tolua_S,6,1,&tolua_err) ||
     !tolua_isstring(tolua_S,7,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  int data_type = ((int)  tolua_tonumber(tolua_S,2,0));
  void* v = ((void*)  tolua_touserdata(tolua_S,3,0));
  int components = ((int)  tolua_tonumber(tolua_S,4,0));
  const void* step = ((const void*)  tolua_touserdata(tolua_S,5,NULL));
  const void* step_fast = ((const void*)  tolua_touserdata(tolua_S,6,NULL));
  const char* format = ((const char*)  tolua_tostring(tolua_S,7,NULL));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,8,0));
  {
   bool tolua_ret = (bool)  ImGui::InputScalarN(label,data_type,v,components,step,step_fast,format,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InputScalarN'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::PopFont */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_PopFont00
static int tolua_main_ImGui_PopFont00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::PopFont();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PopFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::PushStyleColor */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_PushStyleColor00
static int tolua_main_ImGui_PushStyleColor00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int idx = ((int)  tolua_tonumber(tolua_S,1,0));
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  {
   ImGui::PushStyleColor(idx,col);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PushStyleColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::PushStyleColor */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_PushStyleColor01
static int tolua_main_ImGui_PushStyleColor01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int idx = ((int)  tolua_tonumber(tolua_S,1,0));
  ImVec4 col = (  tolua_ext_luaval_to_imvec4_value(tolua_S,2,0));
  {
   ImGui::PushStyleColor(idx,col);
  }
 }
 return 0;
tolua_lerror:
 return tolua_main_ImGui_PushStyleColor00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::PopStyleColor */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_PopStyleColor00
static int tolua_main_ImGui_PopStyleColor00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int count = ((int)  tolua_tonumber(tolua_S,1,1));
  {
   ImGui::PopStyleColor(count);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PopStyleColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::PushStyleVar */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_PushStyleVar00
static int tolua_main_ImGui_PushStyleVar00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int idx = ((int)  tolua_tonumber(tolua_S,1,0));
  float val = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   ImGui::PushStyleVar(idx,val);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PushStyleVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::PushStyleVar */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_PushStyleVar01
static int tolua_main_ImGui_PushStyleVar01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int idx = ((int)  tolua_tonumber(tolua_S,1,0));
  ImVec2 val = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  {
   ImGui::PushStyleVar(idx,val);
  }
 }
 return 0;
tolua_lerror:
 return tolua_main_ImGui_PushStyleVar00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::PopStyleVar */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_PopStyleVar00
static int tolua_main_ImGui_PopStyleVar00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int count = ((int)  tolua_tonumber(tolua_S,1,1));
  {
   ImGui::PopStyleVar(count);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PopStyleVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetStyleColorVec4 */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetStyleColorVec400
static int tolua_main_ImGui_GetStyleColorVec400(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int idx = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   ImVec4 tolua_ret = (ImVec4)  ImGui::GetStyleColorVec4(idx);
   {
   tolua_ext_imvec4_value_to_luaval(tolua_S, tolua_ret, "ImVec4");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetStyleColorVec4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetFontSize */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetFontSize00
static int tolua_main_ImGui_GetFontSize00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  ImGui::GetFontSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFontSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetFontTexUvWhitePixel */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetFontTexUvWhitePixel00
static int tolua_main_ImGui_GetFontTexUvWhitePixel00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImVec2 tolua_ret = (ImVec2)  ImGui::GetFontTexUvWhitePixel();
   {
   tolua_ext_imvec2_value_to_luaval(tolua_S, tolua_ret, "ImVec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFontTexUvWhitePixel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetColorU32 */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetColorU3200
static int tolua_main_ImGui_GetColorU3200(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int idx = ((int)  tolua_tonumber(tolua_S,1,0));
  float alpha_mul = ((float)  tolua_tonumber(tolua_S,2,1.0f));
  {
   unsigned int tolua_ret = (unsigned int)  ImGui::GetColorU32(idx,alpha_mul);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetColorU32'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetColorU32 */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetColorU3201
static int tolua_main_ImGui_GetColorU3201(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_ext_check_is_table(tolua_S,1,"ImVec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  ImVec4 col = (  tolua_ext_luaval_to_imvec4_value(tolua_S,1,0));
  {
   unsigned int tolua_ret = (unsigned int)  ImGui::GetColorU32(col);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_main_ImGui_GetColorU3200(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetColorU32 */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetColorU3202
static int tolua_main_ImGui_GetColorU3202(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  unsigned int col = ((unsigned int)  tolua_tonumber(tolua_S,1,0));
  {
   unsigned int tolua_ret = (unsigned int)  ImGui::GetColorU32(col);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_main_ImGui_GetColorU3201(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::Button */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_Button00
static int tolua_main_ImGui_Button00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  ImGui::Button(label);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Button'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::Button */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_Button01
static int tolua_main_ImGui_Button01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  ImGui::Button(label,size);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_main_ImGui_Button00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SmallButton */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SmallButton00
static int tolua_main_ImGui_SmallButton00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  ImGui::SmallButton(label);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SmallButton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::InvisibleButton */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_InvisibleButton00
static int tolua_main_ImGui_InvisibleButton00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* str_id = ((const char*)  tolua_tostring(tolua_S,1,0));
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  ImGui::InvisibleButton(str_id,size);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InvisibleButton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::ArrowButton */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_ArrowButton00
static int tolua_main_ImGui_ArrowButton00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* str_id = ((const char*)  tolua_tostring(tolua_S,1,0));
  int dir = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  ImGui::ArrowButton(str_id,dir);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ArrowButton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::Image */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_Image00
static int tolua_main_ImGui_Image00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isuserdata(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  void* user_texture_id = ((void*)  tolua_touserdata(tolua_S,1,0));
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  {
   ImGui::Image(user_texture_id,size);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Image'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::Image */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_Image01
static int tolua_main_ImGui_Image01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isuserdata(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  void* user_texture_id = ((void*)  tolua_touserdata(tolua_S,1,0));
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  ImVec2 uv0 = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  {
   ImGui::Image(user_texture_id,size,uv0);
  }
 }
 return 0;
tolua_lerror:
 return tolua_main_ImGui_Image00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::Image */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_Image02
static int tolua_main_ImGui_Image02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isuserdata(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  void* user_texture_id = ((void*)  tolua_touserdata(tolua_S,1,0));
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  ImVec2 uv0 = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  ImVec2 uv1 = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
  {
   ImGui::Image(user_texture_id,size,uv0,uv1);
  }
 }
 return 0;
tolua_lerror:
 return tolua_main_ImGui_Image01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::Checkbox */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_Checkbox00
static int tolua_main_ImGui_Checkbox00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  bool v = ((bool)  tolua_toboolean(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  ImGui::Checkbox(label,&v);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushboolean(tolua_S,(bool)v);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Checkbox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::CheckboxFlags */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_CheckboxFlags00
static int tolua_main_ImGui_CheckboxFlags00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int flags_value = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  ImGui::CheckboxFlags(label,&flags,flags_value);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)flags);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CheckboxFlags'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::RadioButton */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_RadioButton00
static int tolua_main_ImGui_RadioButton00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  bool active = ((bool)  tolua_toboolean(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  ImGui::RadioButton(label,active);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RadioButton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::RadioButton */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_RadioButton01
static int tolua_main_ImGui_RadioButton01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  int v = ((int)  tolua_tonumber(tolua_S,2,0));
  int v_button = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  ImGui::RadioButton(label,&v,v_button);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)v);
  }
 }
 return 2;
tolua_lerror:
 return tolua_main_ImGui_RadioButton00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::ProgressBar */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_ProgressBar00
static int tolua_main_ImGui_ProgressBar00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float fraction = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   ImGui::ProgressBar(fraction);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ProgressBar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::ProgressBar */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_ProgressBar01
static int tolua_main_ImGui_ProgressBar01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float fraction = ((float)  tolua_tonumber(tolua_S,1,0));
  ImVec2 size_arg = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  const char* overlay = ((const char*)  tolua_tostring(tolua_S,3,NULL));
  {
   ImGui::ProgressBar(fraction,size_arg,overlay);
  }
 }
 return 0;
tolua_lerror:
 return tolua_main_ImGui_ProgressBar00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::Bullet */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_Bullet00
static int tolua_main_ImGui_Bullet00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::Bullet();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Bullet'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::PushItemWidth */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_PushItemWidth00
static int tolua_main_ImGui_PushItemWidth00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float item_width = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   ImGui::PushItemWidth(item_width);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PushItemWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::PopItemWidth */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_PopItemWidth00
static int tolua_main_ImGui_PopItemWidth00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::PopItemWidth();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PopItemWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetNextItemWidth */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetNextItemWidth00
static int tolua_main_ImGui_SetNextItemWidth00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float item_width = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   ImGui::SetNextItemWidth(item_width);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNextItemWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::CalcItemWidth */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_CalcItemWidth00
static int tolua_main_ImGui_CalcItemWidth00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  ImGui::CalcItemWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CalcItemWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::PushTextWrapPos */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_PushTextWrapPos00
static int tolua_main_ImGui_PushTextWrapPos00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float wrap_local_pos_x = ((float)  tolua_tonumber(tolua_S,1,0.0f));
  {
   ImGui::PushTextWrapPos(wrap_local_pos_x);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PushTextWrapPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::PopTextWrapPos */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_PopTextWrapPos00
static int tolua_main_ImGui_PopTextWrapPos00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::PopTextWrapPos();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PopTextWrapPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::PushAllowKeyboardFocus */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_PushAllowKeyboardFocus00
static int tolua_main_ImGui_PushAllowKeyboardFocus00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isboolean(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  bool allow_keyboard_focus = ((bool)  tolua_toboolean(tolua_S,1,0));
  {
   ImGui::PushAllowKeyboardFocus(allow_keyboard_focus);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PushAllowKeyboardFocus'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::PopAllowKeyboardFocus */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_PopAllowKeyboardFocus00
static int tolua_main_ImGui_PopAllowKeyboardFocus00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::PopAllowKeyboardFocus();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PopAllowKeyboardFocus'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::PushButtonRepeat */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_PushButtonRepeat00
static int tolua_main_ImGui_PushButtonRepeat00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isboolean(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  bool repeat = ((bool)  tolua_toboolean(tolua_S,1,0));
  {
   ImGui::PushButtonRepeat(repeat);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PushButtonRepeat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::PopButtonRepeat */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_PopButtonRepeat00
static int tolua_main_ImGui_PopButtonRepeat00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::PopButtonRepeat();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PopButtonRepeat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BeginChild */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BeginChild00
static int tolua_main_ImGui_BeginChild00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* str_id = ((const char*)  tolua_tostring(tolua_S,1,0));
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  bool border = ((bool)  tolua_toboolean(tolua_S,3,false));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  ImGui::BeginChild(str_id,size,border,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BeginChild */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BeginChild01
static int tolua_main_ImGui_BeginChild01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  unsigned int id = ((unsigned int)  tolua_tonumber(tolua_S,1,0));
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  bool border = ((bool)  tolua_toboolean(tolua_S,3,false));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  ImGui::BeginChild(id,size,border,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_main_ImGui_BeginChild00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::EndChild */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_EndChild00
static int tolua_main_ImGui_EndChild00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::EndChild();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EndChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::Selectable */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_Selectable00
static int tolua_main_ImGui_Selectable00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  bool selected = ((bool)  tolua_toboolean(tolua_S,2,false));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  ImGui::Selectable(label,selected,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Selectable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::Selectable */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_Selectable01
static int tolua_main_ImGui_Selectable01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  bool selected = ((bool)  tolua_toboolean(tolua_S,2,0));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  ImGui::Selectable(label,selected,flags,size);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_main_ImGui_Selectable00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::Selectable */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_Selectable02
static int tolua_main_ImGui_Selectable02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  bool p_selected = ((bool)  tolua_toboolean(tolua_S,2,0));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  ImGui::Selectable(label,&p_selected,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushboolean(tolua_S,(bool)p_selected);
  }
 }
 return 2;
tolua_lerror:
 return tolua_main_ImGui_Selectable01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::Selectable */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_Selectable03
static int tolua_main_ImGui_Selectable03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  bool p_selected = ((bool)  tolua_toboolean(tolua_S,2,0));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  ImGui::Selectable(label,&p_selected,flags,size);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushboolean(tolua_S,(bool)p_selected);
  }
 }
 return 2;
tolua_lerror:
 return tolua_main_ImGui_Selectable02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetKeyIndex */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetKeyIndex00
static int tolua_main_ImGui_GetKeyIndex00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int imgui_key = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   int tolua_ret = (int)  ImGui::GetKeyIndex(imgui_key);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetKeyIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsKeyDown */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsKeyDown00
static int tolua_main_ImGui_IsKeyDown00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int user_key_index = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  ImGui::IsKeyDown(user_key_index);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsKeyDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsKeyPressed */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsKeyPressed00
static int tolua_main_ImGui_IsKeyPressed00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int user_key_index = ((int)  tolua_tonumber(tolua_S,1,0));
  bool repeat = ((bool)  tolua_toboolean(tolua_S,2,true));
  {
   bool tolua_ret = (bool)  ImGui::IsKeyPressed(user_key_index,repeat);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsKeyPressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsKeyReleased */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsKeyReleased00
static int tolua_main_ImGui_IsKeyReleased00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int user_key_index = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  ImGui::IsKeyReleased(user_key_index);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsKeyReleased'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetKeyPressedAmount */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetKeyPressedAmount00
static int tolua_main_ImGui_GetKeyPressedAmount00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int key_index = ((int)  tolua_tonumber(tolua_S,1,0));
  float repeat_delay = ((float)  tolua_tonumber(tolua_S,2,0));
  float rate = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   int tolua_ret = (int)  ImGui::GetKeyPressedAmount(key_index,repeat_delay,rate);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetKeyPressedAmount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsMouseDown */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsMouseDown00
static int tolua_main_ImGui_IsMouseDown00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int button = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  ImGui::IsMouseDown(button);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsMouseDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsAnyMouseDown */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsAnyMouseDown00
static int tolua_main_ImGui_IsAnyMouseDown00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  ImGui::IsAnyMouseDown();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsAnyMouseDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsMouseClicked */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsMouseClicked00
static int tolua_main_ImGui_IsMouseClicked00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int button = ((int)  tolua_tonumber(tolua_S,1,0));
  bool repeat = ((bool)  tolua_toboolean(tolua_S,2,false));
  {
   bool tolua_ret = (bool)  ImGui::IsMouseClicked(button,repeat);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsMouseClicked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsMouseDoubleClicked */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsMouseDoubleClicked00
static int tolua_main_ImGui_IsMouseDoubleClicked00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int button = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  ImGui::IsMouseDoubleClicked(button);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsMouseDoubleClicked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsMouseReleased */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsMouseReleased00
static int tolua_main_ImGui_IsMouseReleased00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int button = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  ImGui::IsMouseReleased(button);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsMouseReleased'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsMouseDragging */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsMouseDragging00
static int tolua_main_ImGui_IsMouseDragging00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int button = ((int)  tolua_tonumber(tolua_S,1,0));
  float lock_threshold = ((float)  tolua_tonumber(tolua_S,2,-1.0f));
  {
   bool tolua_ret = (bool)  ImGui::IsMouseDragging(button,lock_threshold);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsMouseDragging'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsMouseHoveringRect */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsMouseHoveringRect00
static int tolua_main_ImGui_IsMouseHoveringRect00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_ext_check_is_table(tolua_S,1,"ImVec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImVec2 r_min = (  tolua_ext_luaval_to_imvec2_value(tolua_S,1,0));
  ImVec2 r_max = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  bool clip = ((bool)  tolua_toboolean(tolua_S,3,true));
  {
   bool tolua_ret = (bool)  ImGui::IsMouseHoveringRect(r_min,r_max,clip);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsMouseHoveringRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsMousePosValid */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsMousePosValid00
static int tolua_main_ImGui_IsMousePosValid00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  ImGui::IsMousePosValid();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsMousePosValid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetMousePos */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetMousePos00
static int tolua_main_ImGui_GetMousePos00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImVec2 tolua_ret = (ImVec2)  ImGui::GetMousePos();
   {
   tolua_ext_imvec2_value_to_luaval(tolua_S, tolua_ret, "ImVec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMousePos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetMousePosOnOpeningCurrentPopup */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetMousePosOnOpeningCurrentPopup00
static int tolua_main_ImGui_GetMousePosOnOpeningCurrentPopup00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImVec2 tolua_ret = (ImVec2)  ImGui::GetMousePosOnOpeningCurrentPopup();
   {
   tolua_ext_imvec2_value_to_luaval(tolua_S, tolua_ret, "ImVec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMousePosOnOpeningCurrentPopup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetMouseDragDelta */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetMouseDragDelta00
static int tolua_main_ImGui_GetMouseDragDelta00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int button = ((int)  tolua_tonumber(tolua_S,1,0));
  float lock_threshold = ((float)  tolua_tonumber(tolua_S,2,-1.0f));
  {
   ImVec2 tolua_ret = (ImVec2)  ImGui::GetMouseDragDelta(button,lock_threshold);
   {
   tolua_ext_imvec2_value_to_luaval(tolua_S, tolua_ret, "ImVec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMouseDragDelta'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::ResetMouseDragDelta */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_ResetMouseDragDelta00
static int tolua_main_ImGui_ResetMouseDragDelta00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int button = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   ImGui::ResetMouseDragDelta(button);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResetMouseDragDelta'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetMouseCursor */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetMouseCursor00
static int tolua_main_ImGui_GetMouseCursor00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   int tolua_ret = (int)  ImGui::GetMouseCursor();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMouseCursor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetMouseCursor */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetMouseCursor00
static int tolua_main_ImGui_SetMouseCursor00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int type = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   ImGui::SetMouseCursor(type);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMouseCursor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::CaptureKeyboardFromApp */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_CaptureKeyboardFromApp00
static int tolua_main_ImGui_CaptureKeyboardFromApp00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isboolean(tolua_S,1,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  bool want_capture_keyboard_value = ((bool)  tolua_toboolean(tolua_S,1,true));
  {
   ImGui::CaptureKeyboardFromApp(want_capture_keyboard_value);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CaptureKeyboardFromApp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::CaptureMouseFromApp */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_CaptureMouseFromApp00
static int tolua_main_ImGui_CaptureMouseFromApp00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isboolean(tolua_S,1,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  bool want_capture_mouse_value = ((bool)  tolua_toboolean(tolua_S,1,true));
  {
   ImGui::CaptureMouseFromApp(want_capture_mouse_value);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CaptureMouseFromApp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetContentRegionAvailWidth */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetContentRegionAvailWidth00
static int tolua_main_ImGui_GetContentRegionAvailWidth00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  ImGui::GetContentRegionAvailWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetContentRegionAvailWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetNextWindowPos */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetNextWindowPos00
static int tolua_main_ImGui_SetNextWindowPos00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_ext_check_is_table(tolua_S,1,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImVec2 pos = (  tolua_ext_luaval_to_imvec2_value(tolua_S,1,0));
  int cond = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   ImGui::SetNextWindowPos(pos,cond);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNextWindowPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetNextWindowPos */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetNextWindowPos01
static int tolua_main_ImGui_SetNextWindowPos01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_ext_check_is_table(tolua_S,1,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_ext_check_is_table(tolua_S,3,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  ImVec2 pos = (  tolua_ext_luaval_to_imvec2_value(tolua_S,1,0));
  int cond = ((int)  tolua_tonumber(tolua_S,2,0));
  ImVec2 pivot = (  tolua_ext_luaval_to_imvec2_value(tolua_S,3,0));
  {
   ImGui::SetNextWindowPos(pos,cond,pivot);
  }
 }
 return 0;
tolua_lerror:
 return tolua_main_ImGui_SetNextWindowPos00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetNextWindowSize */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetNextWindowSize00
static int tolua_main_ImGui_SetNextWindowSize00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_ext_check_is_table(tolua_S,1,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,1,0));
  int cond = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   ImGui::SetNextWindowSize(size,cond);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNextWindowSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetNextWindowContentSize */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetNextWindowContentSize00
static int tolua_main_ImGui_SetNextWindowContentSize00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_ext_check_is_table(tolua_S,1,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,1,0));
  {
   ImGui::SetNextWindowContentSize(size);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNextWindowContentSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetNextWindowCollapsed */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetNextWindowCollapsed00
static int tolua_main_ImGui_SetNextWindowCollapsed00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isboolean(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  bool collapsed = ((bool)  tolua_toboolean(tolua_S,1,0));
  int cond = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   ImGui::SetNextWindowCollapsed(collapsed,cond);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNextWindowCollapsed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetNextWindowFocus */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetNextWindowFocus00
static int tolua_main_ImGui_SetNextWindowFocus00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::SetNextWindowFocus();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNextWindowFocus'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetNextWindowBgAlpha */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetNextWindowBgAlpha00
static int tolua_main_ImGui_SetNextWindowBgAlpha00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float alpha = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   ImGui::SetNextWindowBgAlpha(alpha);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNextWindowBgAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetWindowPos */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetWindowPos00
static int tolua_main_ImGui_SetWindowPos00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_ext_check_is_table(tolua_S,1,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImVec2 pos = (  tolua_ext_luaval_to_imvec2_value(tolua_S,1,0));
  int cond = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   ImGui::SetWindowPos(pos,cond);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWindowPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetWindowSize */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetWindowSize00
static int tolua_main_ImGui_SetWindowSize00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_ext_check_is_table(tolua_S,1,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,1,0));
  int cond = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   ImGui::SetWindowSize(size,cond);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWindowSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetWindowCollapsed */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetWindowCollapsed00
static int tolua_main_ImGui_SetWindowCollapsed00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isboolean(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  bool collapsed = ((bool)  tolua_toboolean(tolua_S,1,0));
  int cond = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   ImGui::SetWindowCollapsed(collapsed,cond);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWindowCollapsed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetWindowFocus */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetWindowFocus00
static int tolua_main_ImGui_SetWindowFocus00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::SetWindowFocus();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWindowFocus'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetWindowFontScale */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetWindowFontScale00
static int tolua_main_ImGui_SetWindowFontScale00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float scale = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   ImGui::SetWindowFontScale(scale);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWindowFontScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetWindowPos */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetWindowPos01
static int tolua_main_ImGui_SetWindowPos01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,1,0));
  ImVec2 pos = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  int cond = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   ImGui::SetWindowPos(name,pos,cond);
  }
 }
 return 0;
tolua_lerror:
 return tolua_main_ImGui_SetWindowPos00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetWindowSize */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetWindowSize01
static int tolua_main_ImGui_SetWindowSize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,1,0));
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  int cond = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   ImGui::SetWindowSize(name,size,cond);
  }
 }
 return 0;
tolua_lerror:
 return tolua_main_ImGui_SetWindowSize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetWindowCollapsed */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetWindowCollapsed01
static int tolua_main_ImGui_SetWindowCollapsed01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,1,0));
  bool collapsed = ((bool)  tolua_toboolean(tolua_S,2,0));
  int cond = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   ImGui::SetWindowCollapsed(name,collapsed,cond);
  }
 }
 return 0;
tolua_lerror:
 return tolua_main_ImGui_SetWindowCollapsed00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetWindowFocus */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetWindowFocus01
static int tolua_main_ImGui_SetWindowFocus01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   ImGui::SetWindowFocus(name);
  }
 }
 return 0;
tolua_lerror:
 return tolua_main_ImGui_SetWindowFocus00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::Begin */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_Begin00
static int tolua_main_ImGui_Begin00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,1,0));
  bool p_open = ((bool)  tolua_toboolean(tolua_S,2,NULL));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  ImGui::Begin(name,&p_open,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushboolean(tolua_S,(bool)p_open);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Begin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::End */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_End00
static int tolua_main_ImGui_End00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::End();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'End'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::TreeNode */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_TreeNode00
static int tolua_main_ImGui_TreeNode00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  ImGui::TreeNode(label);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TreeNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::TreeNode */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_TreeNode01
static int tolua_main_ImGui_TreeNode01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* str_id = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* fmt = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  ImGui::TreeNode(str_id,fmt);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_main_ImGui_TreeNode00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::TreeNodeEx */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_TreeNodeEx00
static int tolua_main_ImGui_TreeNodeEx00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  ImGui::TreeNodeEx(label,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TreeNodeEx'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::TreeNodeEx */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_TreeNodeEx01
static int tolua_main_ImGui_TreeNodeEx01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* str_id = ((const char*)  tolua_tostring(tolua_S,1,0));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  const char* fmt = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  ImGui::TreeNodeEx(str_id,flags,fmt);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_main_ImGui_TreeNodeEx00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::TreePush */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_TreePush00
static int tolua_main_ImGui_TreePush00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* str_id = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   ImGui::TreePush(str_id);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TreePush'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::TreePush */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_TreePush01
static int tolua_main_ImGui_TreePush01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isuserdata(tolua_S,1,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const void* ptr_id = ((const void*)  tolua_touserdata(tolua_S,1,NULL));
  {
   ImGui::TreePush(ptr_id);
  }
 }
 return 0;
tolua_lerror:
 return tolua_main_ImGui_TreePush00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::TreePop */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_TreePop00
static int tolua_main_ImGui_TreePop00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::TreePop();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TreePop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::TreeAdvanceToLabelPos */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_TreeAdvanceToLabelPos00
static int tolua_main_ImGui_TreeAdvanceToLabelPos00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::TreeAdvanceToLabelPos();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TreeAdvanceToLabelPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetTreeNodeToLabelSpacing */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetTreeNodeToLabelSpacing00
static int tolua_main_ImGui_GetTreeNodeToLabelSpacing00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  ImGui::GetTreeNodeToLabelSpacing();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTreeNodeToLabelSpacing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::CollapsingHeader */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_CollapsingHeader00
static int tolua_main_ImGui_CollapsingHeader00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  ImGui::CollapsingHeader(label,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CollapsingHeader'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::CollapsingHeader */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_CollapsingHeader01
static int tolua_main_ImGui_CollapsingHeader01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  bool p_open = ((bool)  tolua_toboolean(tolua_S,2,0));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  ImGui::CollapsingHeader(label,&p_open,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushboolean(tolua_S,(bool)p_open);
  }
 }
 return 2;
tolua_lerror:
 return tolua_main_ImGui_CollapsingHeader00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetNextItemOpen */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetNextItemOpen00
static int tolua_main_ImGui_SetNextItemOpen00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isboolean(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  bool is_open = ((bool)  tolua_toboolean(tolua_S,1,0));
  int cond = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   ImGui::SetNextItemOpen(is_open,cond);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNextItemOpen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsItemHovered */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsItemHovered00
static int tolua_main_ImGui_IsItemHovered00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int flags = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  ImGui::IsItemHovered(flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsItemHovered'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsItemActive */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsItemActive00
static int tolua_main_ImGui_IsItemActive00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  ImGui::IsItemActive();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsItemActive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsItemFocused */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsItemFocused00
static int tolua_main_ImGui_IsItemFocused00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  ImGui::IsItemFocused();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsItemFocused'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsItemClicked */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsItemClicked00
static int tolua_main_ImGui_IsItemClicked00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int mouse_button = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  ImGui::IsItemClicked(mouse_button);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsItemClicked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsItemVisible */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsItemVisible00
static int tolua_main_ImGui_IsItemVisible00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  ImGui::IsItemVisible();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsItemVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsItemEdited */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsItemEdited00
static int tolua_main_ImGui_IsItemEdited00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  ImGui::IsItemEdited();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsItemEdited'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsItemActivated */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsItemActivated00
static int tolua_main_ImGui_IsItemActivated00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  ImGui::IsItemActivated();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsItemActivated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsItemDeactivated */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsItemDeactivated00
static int tolua_main_ImGui_IsItemDeactivated00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  ImGui::IsItemDeactivated();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsItemDeactivated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsItemDeactivatedAfterEdit */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsItemDeactivatedAfterEdit00
static int tolua_main_ImGui_IsItemDeactivatedAfterEdit00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  ImGui::IsItemDeactivatedAfterEdit();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsItemDeactivatedAfterEdit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsAnyItemHovered */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsAnyItemHovered00
static int tolua_main_ImGui_IsAnyItemHovered00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  ImGui::IsAnyItemHovered();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsAnyItemHovered'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsAnyItemActive */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsAnyItemActive00
static int tolua_main_ImGui_IsAnyItemActive00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  ImGui::IsAnyItemActive();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsAnyItemActive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsAnyItemFocused */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsAnyItemFocused00
static int tolua_main_ImGui_IsAnyItemFocused00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  ImGui::IsAnyItemFocused();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsAnyItemFocused'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetItemRectMin */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetItemRectMin00
static int tolua_main_ImGui_GetItemRectMin00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImVec2 tolua_ret = (ImVec2)  ImGui::GetItemRectMin();
   {
   tolua_ext_imvec2_value_to_luaval(tolua_S, tolua_ret, "ImVec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemRectMin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetItemRectMax */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetItemRectMax00
static int tolua_main_ImGui_GetItemRectMax00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImVec2 tolua_ret = (ImVec2)  ImGui::GetItemRectMax();
   {
   tolua_ext_imvec2_value_to_luaval(tolua_S, tolua_ret, "ImVec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemRectMax'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetItemRectSize */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetItemRectSize00
static int tolua_main_ImGui_GetItemRectSize00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImVec2 tolua_ret = (ImVec2)  ImGui::GetItemRectSize();
   {
   tolua_ext_imvec2_value_to_luaval(tolua_S, tolua_ret, "ImVec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemRectSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetItemAllowOverlap */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetItemAllowOverlap00
static int tolua_main_ImGui_SetItemAllowOverlap00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::SetItemAllowOverlap();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetItemAllowOverlap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetIO */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetIO00
static int tolua_main_ImGui_GetIO00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGuiIO& tolua_ret = (ImGuiIO&)  ImGui::GetIO();
    tolua_ext_object_to_luaval<ImGuiIO>(tolua_S,&tolua_ret,"ImGuiIO");
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIO'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetStyle */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetStyle00
static int tolua_main_ImGui_GetStyle00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGuiStyle& tolua_ret = (ImGuiStyle&)  ImGui::GetStyle();
    tolua_ext_object_to_luaval<ImGuiStyle>(tolua_S,&tolua_ret,"ImGuiStyle");
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetStyle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::NewFrame */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_NewFrame00
static int tolua_main_ImGui_NewFrame00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::NewFrame();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'NewFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::EndFrame */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_EndFrame00
static int tolua_main_ImGui_EndFrame00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::EndFrame();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EndFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::Render */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_Render00
static int tolua_main_ImGui_Render00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::Render();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Render'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::DragFloat */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_DragFloat00
static int tolua_main_ImGui_DragFloat00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isstring(tolua_S,6,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  float v = ((float)  tolua_tonumber(tolua_S,2,0));
  float v_speed = ((float)  tolua_tonumber(tolua_S,3,1.0f));
  float v_min = ((float)  tolua_tonumber(tolua_S,4,0.0f));
  float v_max = ((float)  tolua_tonumber(tolua_S,5,0.0f));
  const char* format = ((const char*)  tolua_tostring(tolua_S,6,"%.3f"));
  float power = ((float)  tolua_tonumber(tolua_S,7,1.0f));
  {
   bool tolua_ret = (bool)  ImGui::DragFloat(label,&v,v_speed,v_min,v_max,format,power);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)v);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DragFloat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::DragFloat2 */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_DragFloat200
static int tolua_main_ImGui_DragFloat200(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isstring(tolua_S,6,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  float v[2];
  float v_speed = ((float)  tolua_tonumber(tolua_S,3,1.0f));
  float v_min = ((float)  tolua_tonumber(tolua_S,4,0.0f));
  float v_max = ((float)  tolua_tonumber(tolua_S,5,0.0f));
  const char* format = ((const char*)  tolua_tostring(tolua_S,6,"%.3f"));
  float power = ((float)  tolua_tonumber(tolua_S,7,1.0f));
  {
#if COCOS2D_DEBUG >= 1
   if (!tolua_isnumberarray(tolua_S,2,2,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<2;i++)
    v[i] = ((float)  tolua_tofieldnumber(tolua_S,2,i+1,0));
   }
  }
  {
   bool tolua_ret = (bool)  ImGui::DragFloat2(label,v,v_speed,v_min,v_max,format,power);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
  {
   int i;
   for(i=0; i<2;i++)
    tolua_pushfieldnumber(tolua_S,2,i+1,(lua_Number) v[i]);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DragFloat2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::DragInt */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_DragInt00
static int tolua_main_ImGui_DragInt00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isstring(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  int v = ((int)  tolua_tonumber(tolua_S,2,0));
  float v_speed = ((float)  tolua_tonumber(tolua_S,3,1.0f));
  int v_min = ((int)  tolua_tonumber(tolua_S,4,0));
  int v_max = ((int)  tolua_tonumber(tolua_S,5,0));
  const char* format = ((const char*)  tolua_tostring(tolua_S,6,"%d"));
  {
   bool tolua_ret = (bool)  ImGui::DragInt(label,&v,v_speed,v_min,v_max,format);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)v);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DragInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SliderFloat */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SliderFloat00
static int tolua_main_ImGui_SliderFloat00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  float v = ((float)  tolua_tonumber(tolua_S,2,0));
  float v_min = ((float)  tolua_tonumber(tolua_S,3,0));
  float v_max = ((float)  tolua_tonumber(tolua_S,4,0));
  const char* format = ((const char*)  tolua_tostring(tolua_S,5,"%.3f"));
  float power = ((float)  tolua_tonumber(tolua_S,6,1.0f));
  {
   bool tolua_ret = (bool)  ImGui::SliderFloat(label,&v,v_min,v_max,format,power);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)v);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SliderFloat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SliderFloat2 */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SliderFloat200
static int tolua_main_ImGui_SliderFloat200(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  float v[2];
  float v_min = ((float)  tolua_tonumber(tolua_S,3,0));
  float v_max = ((float)  tolua_tonumber(tolua_S,4,0));
  const char* format = ((const char*)  tolua_tostring(tolua_S,5,"%.3f"));
  float power = ((float)  tolua_tonumber(tolua_S,6,1.0f));
  {
#if COCOS2D_DEBUG >= 1
   if (!tolua_isnumberarray(tolua_S,2,2,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<2;i++)
    v[i] = ((float)  tolua_tofieldnumber(tolua_S,2,i+1,0));
   }
  }
  {
   bool tolua_ret = (bool)  ImGui::SliderFloat2(label,v,v_min,v_max,format,power);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
  {
   int i;
   for(i=0; i<2;i++)
    tolua_pushfieldnumber(tolua_S,2,i+1,(lua_Number) v[i]);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SliderFloat2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SliderFloat3 */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SliderFloat300
static int tolua_main_ImGui_SliderFloat300(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  float v[3];
  float v_min = ((float)  tolua_tonumber(tolua_S,3,0));
  float v_max = ((float)  tolua_tonumber(tolua_S,4,0));
  const char* format = ((const char*)  tolua_tostring(tolua_S,5,"%.3f"));
  float power = ((float)  tolua_tonumber(tolua_S,6,1.0f));
  {
#if COCOS2D_DEBUG >= 1
   if (!tolua_isnumberarray(tolua_S,2,3,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<3;i++)
    v[i] = ((float)  tolua_tofieldnumber(tolua_S,2,i+1,0));
   }
  }
  {
   bool tolua_ret = (bool)  ImGui::SliderFloat3(label,v,v_min,v_max,format,power);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
  {
   int i;
   for(i=0; i<3;i++)
    tolua_pushfieldnumber(tolua_S,2,i+1,(lua_Number) v[i]);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SliderFloat3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SliderFloat4 */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SliderFloat400
static int tolua_main_ImGui_SliderFloat400(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  float v[4];
  float v_min = ((float)  tolua_tonumber(tolua_S,3,0));
  float v_max = ((float)  tolua_tonumber(tolua_S,4,0));
  const char* format = ((const char*)  tolua_tostring(tolua_S,5,"%.3f"));
  float power = ((float)  tolua_tonumber(tolua_S,6,1.0f));
  {
#if COCOS2D_DEBUG >= 1
   if (!tolua_isnumberarray(tolua_S,2,4,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<4;i++)
    v[i] = ((float)  tolua_tofieldnumber(tolua_S,2,i+1,0));
   }
  }
  {
   bool tolua_ret = (bool)  ImGui::SliderFloat4(label,v,v_min,v_max,format,power);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
  {
   int i;
   for(i=0; i<4;i++)
    tolua_pushfieldnumber(tolua_S,2,i+1,(lua_Number) v[i]);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SliderFloat4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SliderAngle */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SliderAngle00
static int tolua_main_ImGui_SliderAngle00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isstring(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  float v_rad = ((float)  tolua_tonumber(tolua_S,2,0));
  float v_degrees_min = ((float)  tolua_tonumber(tolua_S,3,-360.0f));
  float v_degrees_max = ((float)  tolua_tonumber(tolua_S,4,360.0f));
  const char* format = ((const char*)  tolua_tostring(tolua_S,5,"%.0f deg"));
  {
   bool tolua_ret = (bool)  ImGui::SliderAngle(label,&v_rad,v_degrees_min,v_degrees_max,format);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)v_rad);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SliderAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SliderInt */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SliderInt00
static int tolua_main_ImGui_SliderInt00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  int v = ((int)  tolua_tonumber(tolua_S,2,0));
  int v_min = ((int)  tolua_tonumber(tolua_S,3,0));
  int v_max = ((int)  tolua_tonumber(tolua_S,4,0));
  const char* format = ((const char*)  tolua_tostring(tolua_S,5,"%d"));
  {
   bool tolua_ret = (bool)  ImGui::SliderInt(label,&v,v_min,v_max,format);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)v);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SliderInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SliderInt2 */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SliderInt200
static int tolua_main_ImGui_SliderInt200(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  int v[2];
  int v_min = ((int)  tolua_tonumber(tolua_S,3,0));
  int v_max = ((int)  tolua_tonumber(tolua_S,4,0));
  const char* format = ((const char*)  tolua_tostring(tolua_S,5,"%d"));
  {
#if COCOS2D_DEBUG >= 1
   if (!tolua_isnumberarray(tolua_S,2,2,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<2;i++)
    v[i] = ((int)  tolua_tofieldnumber(tolua_S,2,i+1,0));
   }
  }
  {
   bool tolua_ret = (bool)  ImGui::SliderInt2(label,v,v_min,v_max,format);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
  {
   int i;
   for(i=0; i<2;i++)
    tolua_pushfieldnumber(tolua_S,2,i+1,(lua_Number) v[i]);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SliderInt2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SliderInt3 */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SliderInt300
static int tolua_main_ImGui_SliderInt300(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  int v[3];
  int v_min = ((int)  tolua_tonumber(tolua_S,3,0));
  int v_max = ((int)  tolua_tonumber(tolua_S,4,0));
  const char* format = ((const char*)  tolua_tostring(tolua_S,5,"%d"));
  {
#if COCOS2D_DEBUG >= 1
   if (!tolua_isnumberarray(tolua_S,2,3,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<3;i++)
    v[i] = ((int)  tolua_tofieldnumber(tolua_S,2,i+1,0));
   }
  }
  {
   bool tolua_ret = (bool)  ImGui::SliderInt3(label,v,v_min,v_max,format);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
  {
   int i;
   for(i=0; i<3;i++)
    tolua_pushfieldnumber(tolua_S,2,i+1,(lua_Number) v[i]);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SliderInt3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SliderInt4 */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SliderInt400
static int tolua_main_ImGui_SliderInt400(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  int v[4];
  int v_min = ((int)  tolua_tonumber(tolua_S,3,0));
  int v_max = ((int)  tolua_tonumber(tolua_S,4,0));
  const char* format = ((const char*)  tolua_tostring(tolua_S,5,"%d"));
  {
#if COCOS2D_DEBUG >= 1
   if (!tolua_isnumberarray(tolua_S,2,4,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<4;i++)
    v[i] = ((int)  tolua_tofieldnumber(tolua_S,2,i+1,0));
   }
  }
  {
   bool tolua_ret = (bool)  ImGui::SliderInt4(label,v,v_min,v_max,format);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
  {
   int i;
   for(i=0; i<4;i++)
    tolua_pushfieldnumber(tolua_S,2,i+1,(lua_Number) v[i]);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SliderInt4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::VSliderFloat */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_VSliderFloat00
static int tolua_main_ImGui_VSliderFloat00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isstring(tolua_S,6,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  float v = ((float)  tolua_tonumber(tolua_S,3,0));
  float v_min = ((float)  tolua_tonumber(tolua_S,4,0));
  float v_max = ((float)  tolua_tonumber(tolua_S,5,0));
  const char* format = ((const char*)  tolua_tostring(tolua_S,6,"%.3f"));
  float power = ((float)  tolua_tonumber(tolua_S,7,1.0f));
  {
   bool tolua_ret = (bool)  ImGui::VSliderFloat(label,size,&v,v_min,v_max,format,power);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)v);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'VSliderFloat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::VSliderInt */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_VSliderInt00
static int tolua_main_ImGui_VSliderInt00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isstring(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,2,0));
  int v = ((int)  tolua_tonumber(tolua_S,3,0));
  int v_min = ((int)  tolua_tonumber(tolua_S,4,0));
  int v_max = ((int)  tolua_tonumber(tolua_S,5,0));
  const char* format = ((const char*)  tolua_tostring(tolua_S,6,"%d"));
  {
   bool tolua_ret = (bool)  ImGui::VSliderInt(label,size,&v,v_min,v_max,format);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)v);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'VSliderInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::ColorEdit3 */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_ColorEdit300
static int tolua_main_ImGui_ColorEdit300(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  float col[3];
  int flags = ((int)  tolua_tonumber(tolua_S,3,0));
  {
#if COCOS2D_DEBUG >= 1
   if (!tolua_isnumberarray(tolua_S,2,3,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<3;i++)
    col[i] = ((float)  tolua_tofieldnumber(tolua_S,2,i+1,0));
   }
  }
  {
   bool tolua_ret = (bool)  ImGui::ColorEdit3(label,col,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
  {
   int i;
   for(i=0; i<3;i++)
    tolua_pushfieldnumber(tolua_S,2,i+1,(lua_Number) col[i]);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ColorEdit3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::ColorEdit4 */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_ColorEdit400
static int tolua_main_ImGui_ColorEdit400(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  float col[4];
  int flags = ((int)  tolua_tonumber(tolua_S,3,0));
  {
#if COCOS2D_DEBUG >= 1
   if (!tolua_isnumberarray(tolua_S,2,4,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<4;i++)
    col[i] = ((float)  tolua_tofieldnumber(tolua_S,2,i+1,0));
   }
  }
  {
   bool tolua_ret = (bool)  ImGui::ColorEdit4(label,col,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
  {
   int i;
   for(i=0; i<4;i++)
    tolua_pushfieldnumber(tolua_S,2,i+1,(lua_Number) col[i]);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ColorEdit4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::ColorPicker3 */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_ColorPicker300
static int tolua_main_ImGui_ColorPicker300(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  float col[3];
  int flags = ((int)  tolua_tonumber(tolua_S,3,0));
  {
#if COCOS2D_DEBUG >= 1
   if (!tolua_isnumberarray(tolua_S,2,3,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<3;i++)
    col[i] = ((float)  tolua_tofieldnumber(tolua_S,2,i+1,0));
   }
  }
  {
   bool tolua_ret = (bool)  ImGui::ColorPicker3(label,col,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
  {
   int i;
   for(i=0; i<3;i++)
    tolua_pushfieldnumber(tolua_S,2,i+1,(lua_Number) col[i]);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ColorPicker3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::ColorPicker4 */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_ColorPicker400
static int tolua_main_ImGui_ColorPicker400(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,1,0));
  float col[4];
  int flags = ((int)  tolua_tonumber(tolua_S,3,0));
  const float ref_col = ((const float)  tolua_tonumber(tolua_S,4,NULL));
  {
#if COCOS2D_DEBUG >= 1
   if (!tolua_isnumberarray(tolua_S,2,4,0,&tolua_err))
    goto tolua_lerror;
   else
#endif
   {
    int i;
    for(i=0; i<4;i++)
    col[i] = ((float)  tolua_tofieldnumber(tolua_S,2,i+1,0));
   }
  }
  {
   bool tolua_ret = (bool)  ImGui::ColorPicker4(label,col,flags,&ref_col);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)ref_col);
  }
  {
   int i;
   for(i=0; i<4;i++)
    tolua_pushfieldnumber(tolua_S,2,i+1,(lua_Number) col[i]);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ColorPicker4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::ColorButton */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_ColorButton00
static int tolua_main_ImGui_ColorButton00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec4",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* desc_id = ((const char*)  tolua_tostring(tolua_S,1,0));
  ImVec4 col = (  tolua_ext_luaval_to_imvec4_value(tolua_S,2,0));
  int flags = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  ImGui::ColorButton(desc_id,col,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ColorButton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::ColorButton */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_ColorButton01
static int tolua_main_ImGui_ColorButton01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_ext_check_is_table(tolua_S,2,"ImVec4",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_is_table(tolua_S,4,"ImVec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* desc_id = ((const char*)  tolua_tostring(tolua_S,1,0));
  ImVec4 col = (  tolua_ext_luaval_to_imvec4_value(tolua_S,2,0));
  int flags = ((int)  tolua_tonumber(tolua_S,3,0));
  ImVec2 size = (  tolua_ext_luaval_to_imvec2_value(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  ImGui::ColorButton(desc_id,col,flags,size);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_main_ImGui_ColorButton00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetColorEditOptions */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetColorEditOptions00
static int tolua_main_ImGui_SetColorEditOptions00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int flags = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   ImGui::SetColorEditOptions(flags);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetColorEditOptions'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BeginDragDropSource */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BeginDragDropSource00
static int tolua_main_ImGui_BeginDragDropSource00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int flags = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  ImGui::BeginDragDropSource(flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginDragDropSource'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::SetDragDropPayload */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_SetDragDropPayload00
static int tolua_main_ImGui_SetDragDropPayload00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* type = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* data = ((const char*)  tolua_tostring(tolua_S,2,0));
  int sz = ((int)  tolua_tonumber(tolua_S,3,0));
  int cond = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  ImGui::SetDragDropPayload(type,data,sz,cond);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDragDropPayload'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::EndDragDropSource */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_EndDragDropSource00
static int tolua_main_ImGui_EndDragDropSource00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::EndDragDropSource();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EndDragDropSource'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::BeginDragDropTarget */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_BeginDragDropTarget00
static int tolua_main_ImGui_BeginDragDropTarget00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  ImGui::BeginDragDropTarget();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginDragDropTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::EndDragDropTarget */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_EndDragDropTarget00
static int tolua_main_ImGui_EndDragDropTarget00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::EndDragDropTarget();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EndDragDropTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::PushID */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_PushID00
static int tolua_main_ImGui_PushID00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* str_id = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   ImGui::PushID(str_id);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PushID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::PushID */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_PushID01
static int tolua_main_ImGui_PushID01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int int_id = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   ImGui::PushID(int_id);
  }
 }
 return 0;
tolua_lerror:
 return tolua_main_ImGui_PushID00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::PopID */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_PopID00
static int tolua_main_ImGui_PopID00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImGui::PopID();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PopID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsWindowAppearing */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsWindowAppearing00
static int tolua_main_ImGui_IsWindowAppearing00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  ImGui::IsWindowAppearing();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsWindowAppearing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsWindowCollapsed */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsWindowCollapsed00
static int tolua_main_ImGui_IsWindowCollapsed00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  ImGui::IsWindowCollapsed();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsWindowCollapsed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsWindowFocused */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsWindowFocused00
static int tolua_main_ImGui_IsWindowFocused00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int flags = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  ImGui::IsWindowFocused(flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsWindowFocused'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::IsWindowHovered */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_IsWindowHovered00
static int tolua_main_ImGui_IsWindowHovered00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int flags = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  ImGui::IsWindowHovered(flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsWindowHovered'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetWindowDrawList */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetWindowDrawList00
static int tolua_main_ImGui_GetWindowDrawList00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImDrawList* tolua_ret = (ImDrawList*)  ImGui::GetWindowDrawList();
    tolua_ext_object_to_luaval<ImDrawList>(tolua_S,(void*)tolua_ret,"ImDrawList");
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWindowDrawList'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetWindowPos */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetWindowPos00
static int tolua_main_ImGui_GetWindowPos00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImVec2 tolua_ret = (ImVec2)  ImGui::GetWindowPos();
   {
   tolua_ext_imvec2_value_to_luaval(tolua_S, tolua_ret, "ImVec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWindowPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetWindowSize */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetWindowSize00
static int tolua_main_ImGui_GetWindowSize00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImVec2 tolua_ret = (ImVec2)  ImGui::GetWindowSize();
   {
   tolua_ext_imvec2_value_to_luaval(tolua_S, tolua_ret, "ImVec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWindowSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetWindowWidth */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetWindowWidth00
static int tolua_main_ImGui_GetWindowWidth00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  ImGui::GetWindowWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWindowWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetWindowHeight */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetWindowHeight00
static int tolua_main_ImGui_GetWindowHeight00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  ImGui::GetWindowHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWindowHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetContentRegionMax */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetContentRegionMax00
static int tolua_main_ImGui_GetContentRegionMax00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImVec2 tolua_ret = (ImVec2)  ImGui::GetContentRegionMax();
   {
   tolua_ext_imvec2_value_to_luaval(tolua_S, tolua_ret, "ImVec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetContentRegionMax'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetContentRegionAvail */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetContentRegionAvail00
static int tolua_main_ImGui_GetContentRegionAvail00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImVec2 tolua_ret = (ImVec2)  ImGui::GetContentRegionAvail();
   {
   tolua_ext_imvec2_value_to_luaval(tolua_S, tolua_ret, "ImVec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetContentRegionAvail'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetWindowContentRegionMin */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetWindowContentRegionMin00
static int tolua_main_ImGui_GetWindowContentRegionMin00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImVec2 tolua_ret = (ImVec2)  ImGui::GetWindowContentRegionMin();
   {
   tolua_ext_imvec2_value_to_luaval(tolua_S, tolua_ret, "ImVec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWindowContentRegionMin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetWindowContentRegionMax */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetWindowContentRegionMax00
static int tolua_main_ImGui_GetWindowContentRegionMax00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ImVec2 tolua_ret = (ImVec2)  ImGui::GetWindowContentRegionMax();
   {
   tolua_ext_imvec2_value_to_luaval(tolua_S, tolua_ret, "ImVec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWindowContentRegionMax'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ImGui::GetWindowContentRegionWidth */
#ifndef TOLUA_DISABLE_tolua_main_ImGui_GetWindowContentRegionWidth00
static int tolua_main_ImGui_GetWindowContentRegionWidth00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  ImGui::GetWindowContentRegionWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWindowContentRegionWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: IM_COL32 */
#ifndef TOLUA_DISABLE_tolua_main_IM_COL3200
static int tolua_main_IM_COL3200(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned int r = ((unsigned int)  tolua_tonumber(tolua_S,1,0));
  unsigned int g = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int b = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int a = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
  {
   unsigned int tolua_ret = (unsigned int)  IM_COL32(r,g,b,a);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IM_COL32'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_main_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"ImGuiIO","ImGuiIO","",NULL);
  tolua_beginmodule(tolua_S,"ImGuiIO");
   tolua_variable(tolua_S,"ConfigFlags",tolua_get_ImGuiIO_ConfigFlags,tolua_set_ImGuiIO_ConfigFlags);
   tolua_variable(tolua_S,"BackendFlags",tolua_get_ImGuiIO_BackendFlags,tolua_set_ImGuiIO_BackendFlags);
   tolua_variable(tolua_S,"DisplaySize",tolua_get_ImGuiIO_DisplaySize,tolua_set_ImGuiIO_DisplaySize);
   tolua_variable(tolua_S,"DeltaTime",tolua_get_ImGuiIO_DeltaTime,tolua_set_ImGuiIO_DeltaTime);
   tolua_variable(tolua_S,"IniSavingRate",tolua_get_ImGuiIO_IniSavingRate,tolua_set_ImGuiIO_IniSavingRate);
   tolua_variable(tolua_S,"IniFilename",tolua_get_ImGuiIO_IniFilename,NULL);
   tolua_variable(tolua_S,"LogFilename",tolua_get_ImGuiIO_LogFilename,NULL);
   tolua_variable(tolua_S,"MouseDoubleClickTime",tolua_get_ImGuiIO_MouseDoubleClickTime,tolua_set_ImGuiIO_MouseDoubleClickTime);
   tolua_variable(tolua_S,"MouseDoubleClickMaxDist",tolua_get_ImGuiIO_MouseDoubleClickMaxDist,tolua_set_ImGuiIO_MouseDoubleClickMaxDist);
   tolua_variable(tolua_S,"MouseDragThreshold",tolua_get_ImGuiIO_MouseDragThreshold,tolua_set_ImGuiIO_MouseDragThreshold);
   tolua_array(tolua_S,"KeyMap",tolua_get_main_ImGuiIO_KeyMap,tolua_set_main_ImGuiIO_KeyMap);
   tolua_variable(tolua_S,"KeyRepeatDelay",tolua_get_ImGuiIO_KeyRepeatDelay,tolua_set_ImGuiIO_KeyRepeatDelay);
   tolua_variable(tolua_S,"KeyRepeatRate",tolua_get_ImGuiIO_KeyRepeatRate,tolua_set_ImGuiIO_KeyRepeatRate);
   tolua_variable(tolua_S,"UserData",tolua_get_ImGuiIO_UserData,tolua_set_ImGuiIO_UserData);
   tolua_variable(tolua_S,"FontGlobalScale",tolua_get_ImGuiIO_FontGlobalScale,tolua_set_ImGuiIO_FontGlobalScale);
   tolua_variable(tolua_S,"FontAllowUserScaling",tolua_get_ImGuiIO_FontAllowUserScaling,tolua_set_ImGuiIO_FontAllowUserScaling);
   tolua_variable(tolua_S,"FontDefault",tolua_get_ImGuiIO_FontDefault_ptr,tolua_set_ImGuiIO_FontDefault_ptr);
   tolua_variable(tolua_S,"DisplayFramebufferScale",tolua_get_ImGuiIO_DisplayFramebufferScale,tolua_set_ImGuiIO_DisplayFramebufferScale);
   tolua_variable(tolua_S,"MouseDrawCursor",tolua_get_ImGuiIO_MouseDrawCursor,tolua_set_ImGuiIO_MouseDrawCursor);
   tolua_variable(tolua_S,"ConfigMacOSXBehaviors",tolua_get_ImGuiIO_ConfigMacOSXBehaviors,tolua_set_ImGuiIO_ConfigMacOSXBehaviors);
   tolua_variable(tolua_S,"ConfigInputTextCursorBlink",tolua_get_ImGuiIO_ConfigInputTextCursorBlink,tolua_set_ImGuiIO_ConfigInputTextCursorBlink);
   tolua_variable(tolua_S,"ConfigWindowsResizeFromEdges",tolua_get_ImGuiIO_ConfigWindowsResizeFromEdges,tolua_set_ImGuiIO_ConfigWindowsResizeFromEdges);
   tolua_variable(tolua_S,"ConfigWindowsMoveFromTitleBarOnly",tolua_get_ImGuiIO_ConfigWindowsMoveFromTitleBarOnly,tolua_set_ImGuiIO_ConfigWindowsMoveFromTitleBarOnly);
   tolua_variable(tolua_S,"MousePos",tolua_get_ImGuiIO_MousePos,tolua_set_ImGuiIO_MousePos);
   tolua_array(tolua_S,"MouseDown",tolua_get_main_ImGuiIO_MouseDown,tolua_set_main_ImGuiIO_MouseDown);
   tolua_variable(tolua_S,"MouseWheel",tolua_get_ImGuiIO_MouseWheel,tolua_set_ImGuiIO_MouseWheel);
   tolua_variable(tolua_S,"MouseWheelH",tolua_get_ImGuiIO_MouseWheelH,tolua_set_ImGuiIO_MouseWheelH);
   tolua_variable(tolua_S,"KeyCtrl",tolua_get_ImGuiIO_KeyCtrl,tolua_set_ImGuiIO_KeyCtrl);
   tolua_variable(tolua_S,"KeyShift",tolua_get_ImGuiIO_KeyShift,tolua_set_ImGuiIO_KeyShift);
   tolua_variable(tolua_S,"KeyAlt",tolua_get_ImGuiIO_KeyAlt,tolua_set_ImGuiIO_KeyAlt);
   tolua_variable(tolua_S,"KeySuper",tolua_get_ImGuiIO_KeySuper,tolua_set_ImGuiIO_KeySuper);
   tolua_array(tolua_S,"KeysDown",tolua_get_main_ImGuiIO_KeysDown,tolua_set_main_ImGuiIO_KeysDown);
   tolua_function(tolua_S,"AddInputCharacter",tolua_main_ImGuiIO_AddInputCharacter00);
   tolua_function(tolua_S,"AddInputCharactersUTF8",tolua_main_ImGuiIO_AddInputCharactersUTF800);
   tolua_function(tolua_S,"ClearInputCharacters",tolua_main_ImGuiIO_ClearInputCharacters00);
   tolua_variable(tolua_S,"WantCaptureMouse",tolua_get_ImGuiIO_WantCaptureMouse,tolua_set_ImGuiIO_WantCaptureMouse);
   tolua_variable(tolua_S,"WantCaptureKeyboard",tolua_get_ImGuiIO_WantCaptureKeyboard,tolua_set_ImGuiIO_WantCaptureKeyboard);
   tolua_variable(tolua_S,"WantTextInput",tolua_get_ImGuiIO_WantTextInput,tolua_set_ImGuiIO_WantTextInput);
   tolua_variable(tolua_S,"WantSetMousePos",tolua_get_ImGuiIO_WantSetMousePos,tolua_set_ImGuiIO_WantSetMousePos);
   tolua_variable(tolua_S,"WantSaveIniSettings",tolua_get_ImGuiIO_WantSaveIniSettings,tolua_set_ImGuiIO_WantSaveIniSettings);
   tolua_variable(tolua_S,"NavActive",tolua_get_ImGuiIO_NavActive,tolua_set_ImGuiIO_NavActive);
   tolua_variable(tolua_S,"NavVisible",tolua_get_ImGuiIO_NavVisible,tolua_set_ImGuiIO_NavVisible);
   tolua_variable(tolua_S,"Framerate",tolua_get_ImGuiIO_Framerate,tolua_set_ImGuiIO_Framerate);
   tolua_variable(tolua_S,"MetricsRenderVertices",tolua_get_ImGuiIO_MetricsRenderVertices,tolua_set_ImGuiIO_MetricsRenderVertices);
   tolua_variable(tolua_S,"MetricsRenderIndices",tolua_get_ImGuiIO_MetricsRenderIndices,tolua_set_ImGuiIO_MetricsRenderIndices);
   tolua_variable(tolua_S,"MetricsRenderWindows",tolua_get_ImGuiIO_MetricsRenderWindows,tolua_set_ImGuiIO_MetricsRenderWindows);
   tolua_variable(tolua_S,"MetricsActiveWindows",tolua_get_ImGuiIO_MetricsActiveWindows,tolua_set_ImGuiIO_MetricsActiveWindows);
   tolua_variable(tolua_S,"MetricsActiveAllocations",tolua_get_ImGuiIO_MetricsActiveAllocations,tolua_set_ImGuiIO_MetricsActiveAllocations);
   tolua_variable(tolua_S,"MouseDelta",tolua_get_ImGuiIO_MouseDelta,tolua_set_ImGuiIO_MouseDelta);
   tolua_variable(tolua_S,"MousePosPrev",tolua_get_ImGuiIO_MousePosPrev,tolua_set_ImGuiIO_MousePosPrev);
   tolua_array(tolua_S,"MouseClickedTime",tolua_get_main_ImGuiIO_MouseClickedTime,tolua_set_main_ImGuiIO_MouseClickedTime);
   tolua_array(tolua_S,"MouseClicked",tolua_get_main_ImGuiIO_MouseClicked,tolua_set_main_ImGuiIO_MouseClicked);
   tolua_array(tolua_S,"MouseDoubleClicked",tolua_get_main_ImGuiIO_MouseDoubleClicked,tolua_set_main_ImGuiIO_MouseDoubleClicked);
   tolua_array(tolua_S,"MouseReleased",tolua_get_main_ImGuiIO_MouseReleased,tolua_set_main_ImGuiIO_MouseReleased);
   tolua_array(tolua_S,"MouseDownOwned",tolua_get_main_ImGuiIO_MouseDownOwned,tolua_set_main_ImGuiIO_MouseDownOwned);
   tolua_array(tolua_S,"MouseDownWasDoubleClick",tolua_get_main_ImGuiIO_MouseDownWasDoubleClick,tolua_set_main_ImGuiIO_MouseDownWasDoubleClick);
   tolua_array(tolua_S,"MouseDownDuration",tolua_get_main_ImGuiIO_MouseDownDuration,tolua_set_main_ImGuiIO_MouseDownDuration);
   tolua_array(tolua_S,"MouseDownDurationPrev",tolua_get_main_ImGuiIO_MouseDownDurationPrev,tolua_set_main_ImGuiIO_MouseDownDurationPrev);
   tolua_array(tolua_S,"MouseDragMaxDistanceSqr",tolua_get_main_ImGuiIO_MouseDragMaxDistanceSqr,tolua_set_main_ImGuiIO_MouseDragMaxDistanceSqr);
   tolua_array(tolua_S,"KeysDownDuration",tolua_get_main_ImGuiIO_KeysDownDuration,tolua_set_main_ImGuiIO_KeysDownDuration);
   tolua_array(tolua_S,"KeysDownDurationPrev",tolua_get_main_ImGuiIO_KeysDownDurationPrev,tolua_set_main_ImGuiIO_KeysDownDurationPrev);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ImGuiStyle","ImGuiStyle","",NULL);
  tolua_beginmodule(tolua_S,"ImGuiStyle");
   tolua_variable(tolua_S,"Alpha",tolua_get_ImGuiStyle_Alpha,tolua_set_ImGuiStyle_Alpha);
   tolua_variable(tolua_S,"WindowPadding",tolua_get_ImGuiStyle_WindowPadding,tolua_set_ImGuiStyle_WindowPadding);
   tolua_variable(tolua_S,"WindowRounding",tolua_get_ImGuiStyle_WindowRounding,tolua_set_ImGuiStyle_WindowRounding);
   tolua_variable(tolua_S,"WindowBorderSize",tolua_get_ImGuiStyle_WindowBorderSize,tolua_set_ImGuiStyle_WindowBorderSize);
   tolua_variable(tolua_S,"WindowMinSize",tolua_get_ImGuiStyle_WindowMinSize,tolua_set_ImGuiStyle_WindowMinSize);
   tolua_variable(tolua_S,"WindowTitleAlign",tolua_get_ImGuiStyle_WindowTitleAlign,tolua_set_ImGuiStyle_WindowTitleAlign);
   tolua_variable(tolua_S,"WindowMenuButtonPosition",tolua_get_ImGuiStyle_WindowMenuButtonPosition,tolua_set_ImGuiStyle_WindowMenuButtonPosition);
   tolua_variable(tolua_S,"ChildRounding",tolua_get_ImGuiStyle_ChildRounding,tolua_set_ImGuiStyle_ChildRounding);
   tolua_variable(tolua_S,"ChildBorderSize",tolua_get_ImGuiStyle_ChildBorderSize,tolua_set_ImGuiStyle_ChildBorderSize);
   tolua_variable(tolua_S,"PopupRounding",tolua_get_ImGuiStyle_PopupRounding,tolua_set_ImGuiStyle_PopupRounding);
   tolua_variable(tolua_S,"PopupBorderSize",tolua_get_ImGuiStyle_PopupBorderSize,tolua_set_ImGuiStyle_PopupBorderSize);
   tolua_variable(tolua_S,"FramePadding",tolua_get_ImGuiStyle_FramePadding,tolua_set_ImGuiStyle_FramePadding);
   tolua_variable(tolua_S,"FrameRounding",tolua_get_ImGuiStyle_FrameRounding,tolua_set_ImGuiStyle_FrameRounding);
   tolua_variable(tolua_S,"FrameBorderSize",tolua_get_ImGuiStyle_FrameBorderSize,tolua_set_ImGuiStyle_FrameBorderSize);
   tolua_variable(tolua_S,"ItemSpacing",tolua_get_ImGuiStyle_ItemSpacing,tolua_set_ImGuiStyle_ItemSpacing);
   tolua_variable(tolua_S,"ItemInnerSpacing",tolua_get_ImGuiStyle_ItemInnerSpacing,tolua_set_ImGuiStyle_ItemInnerSpacing);
   tolua_variable(tolua_S,"TouchExtraPadding",tolua_get_ImGuiStyle_TouchExtraPadding,tolua_set_ImGuiStyle_TouchExtraPadding);
   tolua_variable(tolua_S,"IndentSpacing",tolua_get_ImGuiStyle_IndentSpacing,tolua_set_ImGuiStyle_IndentSpacing);
   tolua_variable(tolua_S,"ColumnsMinSpacing",tolua_get_ImGuiStyle_ColumnsMinSpacing,tolua_set_ImGuiStyle_ColumnsMinSpacing);
   tolua_variable(tolua_S,"ScrollbarSize",tolua_get_ImGuiStyle_ScrollbarSize,tolua_set_ImGuiStyle_ScrollbarSize);
   tolua_variable(tolua_S,"ScrollbarRounding",tolua_get_ImGuiStyle_ScrollbarRounding,tolua_set_ImGuiStyle_ScrollbarRounding);
   tolua_variable(tolua_S,"GrabMinSize",tolua_get_ImGuiStyle_GrabMinSize,tolua_set_ImGuiStyle_GrabMinSize);
   tolua_variable(tolua_S,"GrabRounding",tolua_get_ImGuiStyle_GrabRounding,tolua_set_ImGuiStyle_GrabRounding);
   tolua_variable(tolua_S,"LayoutAlign",tolua_get_ImGuiStyle_LayoutAlign,tolua_set_ImGuiStyle_LayoutAlign);
   tolua_variable(tolua_S,"TabRounding",tolua_get_ImGuiStyle_TabRounding,tolua_set_ImGuiStyle_TabRounding);
   tolua_variable(tolua_S,"TabBorderSize",tolua_get_ImGuiStyle_TabBorderSize,tolua_set_ImGuiStyle_TabBorderSize);
   tolua_variable(tolua_S,"ButtonTextAlign",tolua_get_ImGuiStyle_ButtonTextAlign,tolua_set_ImGuiStyle_ButtonTextAlign);
   tolua_variable(tolua_S,"SelectableTextAlign",tolua_get_ImGuiStyle_SelectableTextAlign,tolua_set_ImGuiStyle_SelectableTextAlign);
   tolua_variable(tolua_S,"DisplayWindowPadding",tolua_get_ImGuiStyle_DisplayWindowPadding,tolua_set_ImGuiStyle_DisplayWindowPadding);
   tolua_variable(tolua_S,"DisplaySafeAreaPadding",tolua_get_ImGuiStyle_DisplaySafeAreaPadding,tolua_set_ImGuiStyle_DisplaySafeAreaPadding);
   tolua_variable(tolua_S,"MouseCursorScale",tolua_get_ImGuiStyle_MouseCursorScale,tolua_set_ImGuiStyle_MouseCursorScale);
   tolua_variable(tolua_S,"AntiAliasedLines",tolua_get_ImGuiStyle_AntiAliasedLines,tolua_set_ImGuiStyle_AntiAliasedLines);
   tolua_variable(tolua_S,"AntiAliasedFill",tolua_get_ImGuiStyle_AntiAliasedFill,tolua_set_ImGuiStyle_AntiAliasedFill);
   tolua_variable(tolua_S,"CurveTessellationTol",tolua_get_ImGuiStyle_CurveTessellationTol,tolua_set_ImGuiStyle_CurveTessellationTol);
   tolua_function(tolua_S,"ScaleAllSizes",tolua_main_ImGuiStyle_ScaleAllSizes00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ImFont","ImFont","",NULL);
  tolua_beginmodule(tolua_S,"ImFont");
   tolua_variable(tolua_S,"FallbackAdvanceX",tolua_get_ImFont_FallbackAdvanceX,tolua_set_ImFont_FallbackAdvanceX);
   tolua_variable(tolua_S,"FontSize",tolua_get_ImFont_FontSize,tolua_set_ImFont_FontSize);
   tolua_variable(tolua_S,"ConfigDataCount",tolua_get_ImFont_ConfigDataCount,tolua_set_ImFont_ConfigDataCount);
   tolua_variable(tolua_S,"Scale",tolua_get_ImFont_Scale,tolua_set_ImFont_Scale);
   tolua_variable(tolua_S,"Ascent",tolua_get_ImFont_Ascent,tolua_set_ImFont_Ascent);
   tolua_variable(tolua_S,"Descent",tolua_get_ImFont_Descent,tolua_set_ImFont_Descent);
   tolua_variable(tolua_S,"MetricsTotalSurface",tolua_get_ImFont_MetricsTotalSurface,tolua_set_ImFont_MetricsTotalSurface);
   tolua_variable(tolua_S,"DirtyLookupTables",tolua_get_ImFont_DirtyLookupTables,tolua_set_ImFont_DirtyLookupTables);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ImDrawList","ImDrawList","",NULL);
  tolua_beginmodule(tolua_S,"ImDrawList");
   tolua_variable(tolua_S,"_VtxCurrentOffset",tolua_get_ImDrawList_unsigned__VtxCurrentOffset,tolua_set_ImDrawList_unsigned__VtxCurrentOffset);
   tolua_variable(tolua_S,"_VtxCurrentIdx",tolua_get_ImDrawList_unsigned__VtxCurrentIdx,tolua_set_ImDrawList_unsigned__VtxCurrentIdx);
   tolua_variable(tolua_S,"_FringeScale",tolua_get_ImDrawList__FringeScale,tolua_set_ImDrawList__FringeScale);
   tolua_function(tolua_S,"PushClipRect",tolua_main_ImDrawList_PushClipRect00);
   tolua_function(tolua_S,"PushClipRectFullScreen",tolua_main_ImDrawList_PushClipRectFullScreen00);
   tolua_function(tolua_S,"PopClipRect",tolua_main_ImDrawList_PopClipRect00);
   tolua_function(tolua_S,"PopTextureID",tolua_main_ImDrawList_PopTextureID00);
   tolua_function(tolua_S,"GetClipRectMin",tolua_main_ImDrawList_GetClipRectMin00);
   tolua_function(tolua_S,"GetClipRectMax",tolua_main_ImDrawList_GetClipRectMax00);
   tolua_function(tolua_S,"AddLine",tolua_main_ImDrawList_AddLine00);
   tolua_function(tolua_S,"AddRect",tolua_main_ImDrawList_AddRect00);
   tolua_function(tolua_S,"AddRectFilled",tolua_main_ImDrawList_AddRectFilled00);
   tolua_function(tolua_S,"AddRectFilledMultiColor",tolua_main_ImDrawList_AddRectFilledMultiColor00);
   tolua_function(tolua_S,"AddQuad",tolua_main_ImDrawList_AddQuad00);
   tolua_function(tolua_S,"AddQuadFilled",tolua_main_ImDrawList_AddQuadFilled00);
   tolua_function(tolua_S,"AddTriangle",tolua_main_ImDrawList_AddTriangle00);
   tolua_function(tolua_S,"AddTriangleFilled",tolua_main_ImDrawList_AddTriangleFilled00);
   tolua_function(tolua_S,"AddCircle",tolua_main_ImDrawList_AddCircle00);
   tolua_function(tolua_S,"AddCircleFilled",tolua_main_ImDrawList_AddCircleFilled00);
   tolua_function(tolua_S,"AddText",tolua_main_ImDrawList_AddText00);
   tolua_function(tolua_S,"AddImage",tolua_main_ImDrawList_AddImage00);
   tolua_function(tolua_S,"AddImage",tolua_main_ImDrawList_AddImage01);
   tolua_function(tolua_S,"AddImage",tolua_main_ImDrawList_AddImage02);
   tolua_function(tolua_S,"AddImageQuad",tolua_main_ImDrawList_AddImageQuad00);
   tolua_function(tolua_S,"AddImageQuad",tolua_main_ImDrawList_AddImageQuad01);
   tolua_function(tolua_S,"AddImageQuad",tolua_main_ImDrawList_AddImageQuad02);
   tolua_function(tolua_S,"AddImageQuad",tolua_main_ImDrawList_AddImageQuad03);
   tolua_function(tolua_S,"AddImageQuad",tolua_main_ImDrawList_AddImageQuad04);
   tolua_function(tolua_S,"AddImageRounded",tolua_main_ImDrawList_AddImageRounded00);
   tolua_function(tolua_S,"AddBezierCurve",tolua_main_ImDrawList_AddBezierCurve00);
   tolua_function(tolua_S,"PathClear",tolua_main_ImDrawList_PathClear00);
   tolua_function(tolua_S,"PathLineTo",tolua_main_ImDrawList_PathLineTo00);
   tolua_function(tolua_S,"PathLineToMergeDuplicate",tolua_main_ImDrawList_PathLineToMergeDuplicate00);
   tolua_function(tolua_S,"PathFillConvex",tolua_main_ImDrawList_PathFillConvex00);
   tolua_function(tolua_S,"PathStroke",tolua_main_ImDrawList_PathStroke00);
   tolua_function(tolua_S,"PathArcTo",tolua_main_ImDrawList_PathArcTo00);
   tolua_function(tolua_S,"PathArcToFast",tolua_main_ImDrawList_PathArcToFast00);
   tolua_function(tolua_S,"PathBezierCurveTo",tolua_main_ImDrawList_PathBezierCurveTo00);
   tolua_function(tolua_S,"PathRect",tolua_main_ImDrawList_PathRect00);
   tolua_function(tolua_S,"ChannelsSplit",tolua_main_ImDrawList_ChannelsSplit00);
   tolua_function(tolua_S,"ChannelsMerge",tolua_main_ImDrawList_ChannelsMerge00);
   tolua_function(tolua_S,"ChannelsSetCurrent",tolua_main_ImDrawList_ChannelsSetCurrent00);
   tolua_function(tolua_S,"Clear",tolua_main_ImDrawList_Clear00);
   tolua_function(tolua_S,"ClearFreeMemory",tolua_main_ImDrawList_ClearFreeMemory00);
   tolua_function(tolua_S,"PrimReserve",tolua_main_ImDrawList_PrimReserve00);
   tolua_function(tolua_S,"PrimRect",tolua_main_ImDrawList_PrimRect00);
   tolua_function(tolua_S,"PrimRectUV",tolua_main_ImDrawList_PrimRectUV00);
   tolua_function(tolua_S,"PrimQuadUV",tolua_main_ImDrawList_PrimQuadUV00);
   tolua_function(tolua_S,"PrimWriteVtx",tolua_main_ImDrawList_PrimWriteVtx00);
   tolua_function(tolua_S,"PrimVtx",tolua_main_ImDrawList_PrimVtx00);
   tolua_function(tolua_S,"UpdateClipRect",tolua_main_ImDrawList_UpdateClipRect00);
   tolua_function(tolua_S,"UpdateTextureID",tolua_main_ImDrawList_UpdateTextureID00);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"ImGui",0);
  tolua_beginmodule(tolua_S,"ImGui");
   tolua_function(tolua_S,"ShowDemoWindow",tolua_main_ImGui_ShowDemoWindow00);
   tolua_function(tolua_S,"ShowAboutWindow",tolua_main_ImGui_ShowAboutWindow00);
   tolua_function(tolua_S,"ShowMetricsWindow",tolua_main_ImGui_ShowMetricsWindow00);
   tolua_function(tolua_S,"ShowStyleSelector",tolua_main_ImGui_ShowStyleSelector00);
   tolua_function(tolua_S,"ShowFontSelector",tolua_main_ImGui_ShowFontSelector00);
   tolua_function(tolua_S,"ShowUserGuide",tolua_main_ImGui_ShowUserGuide00);
   tolua_function(tolua_S,"GetVersion",tolua_main_ImGui_GetVersion00);
   tolua_function(tolua_S,"BeginMainMenuBar",tolua_main_ImGui_BeginMainMenuBar00);
   tolua_function(tolua_S,"EndMainMenuBar",tolua_main_ImGui_EndMainMenuBar00);
   tolua_function(tolua_S,"BeginMenuBar",tolua_main_ImGui_BeginMenuBar00);
   tolua_function(tolua_S,"EndMenuBar",tolua_main_ImGui_EndMenuBar00);
   tolua_function(tolua_S,"BeginMenu",tolua_main_ImGui_BeginMenu00);
   tolua_function(tolua_S,"EndMenu",tolua_main_ImGui_EndMenu00);
   tolua_function(tolua_S,"MenuItem",tolua_main_ImGui_MenuItem00);
   tolua_function(tolua_S,"MenuItem",tolua_main_ImGui_MenuItem01);
   tolua_function(tolua_S,"BeginTooltip",tolua_main_ImGui_BeginTooltip00);
   tolua_function(tolua_S,"EndTooltip",tolua_main_ImGui_EndTooltip00);
   tolua_function(tolua_S,"SetTooltip",tolua_main_ImGui_SetTooltip00);
   tolua_function(tolua_S,"OpenPopup",tolua_main_ImGui_OpenPopup00);
   tolua_function(tolua_S,"BeginPopup",tolua_main_ImGui_BeginPopup00);
   tolua_function(tolua_S,"BeginPopupContextItem",tolua_main_ImGui_BeginPopupContextItem00);
   tolua_function(tolua_S,"BeginPopupContextWindow",tolua_main_ImGui_BeginPopupContextWindow00);
   tolua_function(tolua_S,"BeginPopupContextVoid",tolua_main_ImGui_BeginPopupContextVoid00);
   tolua_function(tolua_S,"BeginPopupModal",tolua_main_ImGui_BeginPopupModal00);
   tolua_function(tolua_S,"EndPopup",tolua_main_ImGui_EndPopup00);
   tolua_function(tolua_S,"OpenPopupOnItemClick",tolua_main_ImGui_OpenPopupOnItemClick00);
   tolua_function(tolua_S,"IsPopupOpen",tolua_main_ImGui_IsPopupOpen00);
   tolua_function(tolua_S,"CloseCurrentPopup",tolua_main_ImGui_CloseCurrentPopup00);
   tolua_function(tolua_S,"Separator",tolua_main_ImGui_Separator00);
   tolua_function(tolua_S,"SameLine",tolua_main_ImGui_SameLine00);
   tolua_function(tolua_S,"NewLine",tolua_main_ImGui_NewLine00);
   tolua_function(tolua_S,"Spacing",tolua_main_ImGui_Spacing00);
   tolua_function(tolua_S,"Dummy",tolua_main_ImGui_Dummy00);
   tolua_function(tolua_S,"Indent",tolua_main_ImGui_Indent00);
   tolua_function(tolua_S,"Unindent",tolua_main_ImGui_Unindent00);
   tolua_function(tolua_S,"BeginGroup",tolua_main_ImGui_BeginGroup00);
   tolua_function(tolua_S,"EndGroup",tolua_main_ImGui_EndGroup00);
   tolua_function(tolua_S,"GetCursorPos",tolua_main_ImGui_GetCursorPos00);
   tolua_function(tolua_S,"GetCursorPosX",tolua_main_ImGui_GetCursorPosX00);
   tolua_function(tolua_S,"GetCursorPosY",tolua_main_ImGui_GetCursorPosY00);
   tolua_function(tolua_S,"SetCursorPos",tolua_main_ImGui_SetCursorPos00);
   tolua_function(tolua_S,"SetCursorPosX",tolua_main_ImGui_SetCursorPosX00);
   tolua_function(tolua_S,"SetCursorPosY",tolua_main_ImGui_SetCursorPosY00);
   tolua_function(tolua_S,"GetCursorStartPos",tolua_main_ImGui_GetCursorStartPos00);
   tolua_function(tolua_S,"GetCursorScreenPos",tolua_main_ImGui_GetCursorScreenPos00);
   tolua_function(tolua_S,"SetCursorScreenPos",tolua_main_ImGui_SetCursorScreenPos00);
   tolua_function(tolua_S,"AlignTextToFramePadding",tolua_main_ImGui_AlignTextToFramePadding00);
   tolua_function(tolua_S,"GetTextLineHeight",tolua_main_ImGui_GetTextLineHeight00);
   tolua_function(tolua_S,"GetTextLineHeightWithSpacing",tolua_main_ImGui_GetTextLineHeightWithSpacing00);
   tolua_function(tolua_S,"GetFrameHeight",tolua_main_ImGui_GetFrameHeight00);
   tolua_function(tolua_S,"GetFrameHeightWithSpacing",tolua_main_ImGui_GetFrameHeightWithSpacing00);
   tolua_function(tolua_S,"BeginHorizontal",tolua_main_ImGui_BeginHorizontal00);
   tolua_function(tolua_S,"BeginHorizontal",tolua_main_ImGui_BeginHorizontal01);
   tolua_function(tolua_S,"EndHorizontal",tolua_main_ImGui_EndHorizontal00);
   tolua_function(tolua_S,"BeginVertical",tolua_main_ImGui_BeginVertical00);
   tolua_function(tolua_S,"BeginVertical",tolua_main_ImGui_BeginVertical01);
   tolua_function(tolua_S,"BeginVertical",tolua_main_ImGui_BeginVertical02);
   tolua_function(tolua_S,"EndVertical",tolua_main_ImGui_EndVertical00);
   tolua_function(tolua_S,"Spring",tolua_main_ImGui_Spring00);
   tolua_function(tolua_S,"SuspendLayout",tolua_main_ImGui_SuspendLayout00);
   tolua_function(tolua_S,"ResumeLayout",tolua_main_ImGui_ResumeLayout00);
   tolua_function(tolua_S,"BeginTabBar",tolua_main_ImGui_BeginTabBar00);
   tolua_function(tolua_S,"EndTabBar",tolua_main_ImGui_EndTabBar00);
   tolua_function(tolua_S,"BeginTabItem",tolua_main_ImGui_BeginTabItem00);
   tolua_function(tolua_S,"EndTabItem",tolua_main_ImGui_EndTabItem00);
   tolua_function(tolua_S,"SetTabItemClosed",tolua_main_ImGui_SetTabItemClosed00);
   tolua_function(tolua_S,"TextUnformatted",tolua_main_ImGui_TextUnformatted00);
   tolua_function(tolua_S,"Text",tolua_main_ImGui_Text00);
   tolua_function(tolua_S,"TextColored",tolua_main_ImGui_TextColored00);
   tolua_function(tolua_S,"TextDisabled",tolua_main_ImGui_TextDisabled00);
   tolua_function(tolua_S,"TextWrapped",tolua_main_ImGui_TextWrapped00);
   tolua_function(tolua_S,"LabelText",tolua_main_ImGui_LabelText00);
   tolua_function(tolua_S,"BulletText",tolua_main_ImGui_BulletText00);
   tolua_function(tolua_S,"InputText",tolua_main_ImGui_InputText00);
   tolua_function(tolua_S,"InputTextMultiline",tolua_main_ImGui_InputTextMultiline00);
   tolua_function(tolua_S,"InputFloat",tolua_main_ImGui_InputFloat00);
   tolua_function(tolua_S,"InputFloat2",tolua_main_ImGui_InputFloat200);
   tolua_function(tolua_S,"InputFloat3",tolua_main_ImGui_InputFloat300);
   tolua_function(tolua_S,"InputFloat4",tolua_main_ImGui_InputFloat400);
   tolua_function(tolua_S,"InputInt",tolua_main_ImGui_InputInt00);
   tolua_function(tolua_S,"InputInt2",tolua_main_ImGui_InputInt200);
   tolua_function(tolua_S,"InputInt3",tolua_main_ImGui_InputInt300);
   tolua_function(tolua_S,"InputInt4",tolua_main_ImGui_InputInt400);
   tolua_function(tolua_S,"InputDouble",tolua_main_ImGui_InputDouble00);
   tolua_function(tolua_S,"InputScalar",tolua_main_ImGui_InputScalar00);
   tolua_function(tolua_S,"InputScalarN",tolua_main_ImGui_InputScalarN00);
   tolua_function(tolua_S,"PopFont",tolua_main_ImGui_PopFont00);
   tolua_function(tolua_S,"PushStyleColor",tolua_main_ImGui_PushStyleColor00);
   tolua_function(tolua_S,"PushStyleColor",tolua_main_ImGui_PushStyleColor01);
   tolua_function(tolua_S,"PopStyleColor",tolua_main_ImGui_PopStyleColor00);
   tolua_function(tolua_S,"PushStyleVar",tolua_main_ImGui_PushStyleVar00);
   tolua_function(tolua_S,"PushStyleVar",tolua_main_ImGui_PushStyleVar01);
   tolua_function(tolua_S,"PopStyleVar",tolua_main_ImGui_PopStyleVar00);
   tolua_function(tolua_S,"GetStyleColorVec4",tolua_main_ImGui_GetStyleColorVec400);
   tolua_function(tolua_S,"GetFontSize",tolua_main_ImGui_GetFontSize00);
   tolua_function(tolua_S,"GetFontTexUvWhitePixel",tolua_main_ImGui_GetFontTexUvWhitePixel00);
   tolua_function(tolua_S,"GetColorU32",tolua_main_ImGui_GetColorU3200);
   tolua_function(tolua_S,"GetColorU32",tolua_main_ImGui_GetColorU3201);
   tolua_function(tolua_S,"GetColorU32",tolua_main_ImGui_GetColorU3202);
   tolua_function(tolua_S,"Button",tolua_main_ImGui_Button00);
   tolua_function(tolua_S,"Button",tolua_main_ImGui_Button01);
   tolua_function(tolua_S,"SmallButton",tolua_main_ImGui_SmallButton00);
   tolua_function(tolua_S,"InvisibleButton",tolua_main_ImGui_InvisibleButton00);
   tolua_function(tolua_S,"ArrowButton",tolua_main_ImGui_ArrowButton00);
   tolua_function(tolua_S,"Image",tolua_main_ImGui_Image00);
   tolua_function(tolua_S,"Image",tolua_main_ImGui_Image01);
   tolua_function(tolua_S,"Image",tolua_main_ImGui_Image02);
   tolua_function(tolua_S,"Checkbox",tolua_main_ImGui_Checkbox00);
   tolua_function(tolua_S,"CheckboxFlags",tolua_main_ImGui_CheckboxFlags00);
   tolua_function(tolua_S,"RadioButton",tolua_main_ImGui_RadioButton00);
   tolua_function(tolua_S,"RadioButton",tolua_main_ImGui_RadioButton01);
   tolua_function(tolua_S,"ProgressBar",tolua_main_ImGui_ProgressBar00);
   tolua_function(tolua_S,"ProgressBar",tolua_main_ImGui_ProgressBar01);
   tolua_function(tolua_S,"Bullet",tolua_main_ImGui_Bullet00);
   tolua_function(tolua_S,"PushItemWidth",tolua_main_ImGui_PushItemWidth00);
   tolua_function(tolua_S,"PopItemWidth",tolua_main_ImGui_PopItemWidth00);
   tolua_function(tolua_S,"SetNextItemWidth",tolua_main_ImGui_SetNextItemWidth00);
   tolua_function(tolua_S,"CalcItemWidth",tolua_main_ImGui_CalcItemWidth00);
   tolua_function(tolua_S,"PushTextWrapPos",tolua_main_ImGui_PushTextWrapPos00);
   tolua_function(tolua_S,"PopTextWrapPos",tolua_main_ImGui_PopTextWrapPos00);
   tolua_function(tolua_S,"PushAllowKeyboardFocus",tolua_main_ImGui_PushAllowKeyboardFocus00);
   tolua_function(tolua_S,"PopAllowKeyboardFocus",tolua_main_ImGui_PopAllowKeyboardFocus00);
   tolua_function(tolua_S,"PushButtonRepeat",tolua_main_ImGui_PushButtonRepeat00);
   tolua_function(tolua_S,"PopButtonRepeat",tolua_main_ImGui_PopButtonRepeat00);
   tolua_function(tolua_S,"BeginChild",tolua_main_ImGui_BeginChild00);
   tolua_function(tolua_S,"BeginChild",tolua_main_ImGui_BeginChild01);
   tolua_function(tolua_S,"EndChild",tolua_main_ImGui_EndChild00);
   tolua_function(tolua_S,"Selectable",tolua_main_ImGui_Selectable00);
   tolua_function(tolua_S,"Selectable",tolua_main_ImGui_Selectable01);
   tolua_function(tolua_S,"Selectable",tolua_main_ImGui_Selectable02);
   tolua_function(tolua_S,"Selectable",tolua_main_ImGui_Selectable03);
   tolua_function(tolua_S,"GetKeyIndex",tolua_main_ImGui_GetKeyIndex00);
   tolua_function(tolua_S,"IsKeyDown",tolua_main_ImGui_IsKeyDown00);
   tolua_function(tolua_S,"IsKeyPressed",tolua_main_ImGui_IsKeyPressed00);
   tolua_function(tolua_S,"IsKeyReleased",tolua_main_ImGui_IsKeyReleased00);
   tolua_function(tolua_S,"GetKeyPressedAmount",tolua_main_ImGui_GetKeyPressedAmount00);
   tolua_function(tolua_S,"IsMouseDown",tolua_main_ImGui_IsMouseDown00);
   tolua_function(tolua_S,"IsAnyMouseDown",tolua_main_ImGui_IsAnyMouseDown00);
   tolua_function(tolua_S,"IsMouseClicked",tolua_main_ImGui_IsMouseClicked00);
   tolua_function(tolua_S,"IsMouseDoubleClicked",tolua_main_ImGui_IsMouseDoubleClicked00);
   tolua_function(tolua_S,"IsMouseReleased",tolua_main_ImGui_IsMouseReleased00);
   tolua_function(tolua_S,"IsMouseDragging",tolua_main_ImGui_IsMouseDragging00);
   tolua_function(tolua_S,"IsMouseHoveringRect",tolua_main_ImGui_IsMouseHoveringRect00);
   tolua_function(tolua_S,"IsMousePosValid",tolua_main_ImGui_IsMousePosValid00);
   tolua_function(tolua_S,"GetMousePos",tolua_main_ImGui_GetMousePos00);
   tolua_function(tolua_S,"GetMousePosOnOpeningCurrentPopup",tolua_main_ImGui_GetMousePosOnOpeningCurrentPopup00);
   tolua_function(tolua_S,"GetMouseDragDelta",tolua_main_ImGui_GetMouseDragDelta00);
   tolua_function(tolua_S,"ResetMouseDragDelta",tolua_main_ImGui_ResetMouseDragDelta00);
   tolua_function(tolua_S,"GetMouseCursor",tolua_main_ImGui_GetMouseCursor00);
   tolua_function(tolua_S,"SetMouseCursor",tolua_main_ImGui_SetMouseCursor00);
   tolua_function(tolua_S,"CaptureKeyboardFromApp",tolua_main_ImGui_CaptureKeyboardFromApp00);
   tolua_function(tolua_S,"CaptureMouseFromApp",tolua_main_ImGui_CaptureMouseFromApp00);
   tolua_function(tolua_S,"GetContentRegionAvailWidth",tolua_main_ImGui_GetContentRegionAvailWidth00);
   tolua_function(tolua_S,"SetNextWindowPos",tolua_main_ImGui_SetNextWindowPos00);
   tolua_function(tolua_S,"SetNextWindowPos",tolua_main_ImGui_SetNextWindowPos01);
   tolua_function(tolua_S,"SetNextWindowSize",tolua_main_ImGui_SetNextWindowSize00);
   tolua_function(tolua_S,"SetNextWindowContentSize",tolua_main_ImGui_SetNextWindowContentSize00);
   tolua_function(tolua_S,"SetNextWindowCollapsed",tolua_main_ImGui_SetNextWindowCollapsed00);
   tolua_function(tolua_S,"SetNextWindowFocus",tolua_main_ImGui_SetNextWindowFocus00);
   tolua_function(tolua_S,"SetNextWindowBgAlpha",tolua_main_ImGui_SetNextWindowBgAlpha00);
   tolua_function(tolua_S,"SetWindowPos",tolua_main_ImGui_SetWindowPos00);
   tolua_function(tolua_S,"SetWindowSize",tolua_main_ImGui_SetWindowSize00);
   tolua_function(tolua_S,"SetWindowCollapsed",tolua_main_ImGui_SetWindowCollapsed00);
   tolua_function(tolua_S,"SetWindowFocus",tolua_main_ImGui_SetWindowFocus00);
   tolua_function(tolua_S,"SetWindowFontScale",tolua_main_ImGui_SetWindowFontScale00);
   tolua_function(tolua_S,"SetWindowPos",tolua_main_ImGui_SetWindowPos01);
   tolua_function(tolua_S,"SetWindowSize",tolua_main_ImGui_SetWindowSize01);
   tolua_function(tolua_S,"SetWindowCollapsed",tolua_main_ImGui_SetWindowCollapsed01);
   tolua_function(tolua_S,"SetWindowFocus",tolua_main_ImGui_SetWindowFocus01);
   tolua_function(tolua_S,"Begin",tolua_main_ImGui_Begin00);
   tolua_function(tolua_S,"End",tolua_main_ImGui_End00);
   tolua_function(tolua_S,"TreeNode",tolua_main_ImGui_TreeNode00);
   tolua_function(tolua_S,"TreeNode",tolua_main_ImGui_TreeNode01);
   tolua_function(tolua_S,"TreeNodeEx",tolua_main_ImGui_TreeNodeEx00);
   tolua_function(tolua_S,"TreeNodeEx",tolua_main_ImGui_TreeNodeEx01);
   tolua_function(tolua_S,"TreePush",tolua_main_ImGui_TreePush00);
   tolua_function(tolua_S,"TreePush",tolua_main_ImGui_TreePush01);
   tolua_function(tolua_S,"TreePop",tolua_main_ImGui_TreePop00);
   tolua_function(tolua_S,"TreeAdvanceToLabelPos",tolua_main_ImGui_TreeAdvanceToLabelPos00);
   tolua_function(tolua_S,"GetTreeNodeToLabelSpacing",tolua_main_ImGui_GetTreeNodeToLabelSpacing00);
   tolua_function(tolua_S,"CollapsingHeader",tolua_main_ImGui_CollapsingHeader00);
   tolua_function(tolua_S,"CollapsingHeader",tolua_main_ImGui_CollapsingHeader01);
   tolua_function(tolua_S,"SetNextItemOpen",tolua_main_ImGui_SetNextItemOpen00);
   tolua_function(tolua_S,"IsItemHovered",tolua_main_ImGui_IsItemHovered00);
   tolua_function(tolua_S,"IsItemActive",tolua_main_ImGui_IsItemActive00);
   tolua_function(tolua_S,"IsItemFocused",tolua_main_ImGui_IsItemFocused00);
   tolua_function(tolua_S,"IsItemClicked",tolua_main_ImGui_IsItemClicked00);
   tolua_function(tolua_S,"IsItemVisible",tolua_main_ImGui_IsItemVisible00);
   tolua_function(tolua_S,"IsItemEdited",tolua_main_ImGui_IsItemEdited00);
   tolua_function(tolua_S,"IsItemActivated",tolua_main_ImGui_IsItemActivated00);
   tolua_function(tolua_S,"IsItemDeactivated",tolua_main_ImGui_IsItemDeactivated00);
   tolua_function(tolua_S,"IsItemDeactivatedAfterEdit",tolua_main_ImGui_IsItemDeactivatedAfterEdit00);
   tolua_function(tolua_S,"IsAnyItemHovered",tolua_main_ImGui_IsAnyItemHovered00);
   tolua_function(tolua_S,"IsAnyItemActive",tolua_main_ImGui_IsAnyItemActive00);
   tolua_function(tolua_S,"IsAnyItemFocused",tolua_main_ImGui_IsAnyItemFocused00);
   tolua_function(tolua_S,"GetItemRectMin",tolua_main_ImGui_GetItemRectMin00);
   tolua_function(tolua_S,"GetItemRectMax",tolua_main_ImGui_GetItemRectMax00);
   tolua_function(tolua_S,"GetItemRectSize",tolua_main_ImGui_GetItemRectSize00);
   tolua_function(tolua_S,"SetItemAllowOverlap",tolua_main_ImGui_SetItemAllowOverlap00);
   tolua_function(tolua_S,"GetIO",tolua_main_ImGui_GetIO00);
   tolua_function(tolua_S,"GetStyle",tolua_main_ImGui_GetStyle00);
   tolua_function(tolua_S,"NewFrame",tolua_main_ImGui_NewFrame00);
   tolua_function(tolua_S,"EndFrame",tolua_main_ImGui_EndFrame00);
   tolua_function(tolua_S,"Render",tolua_main_ImGui_Render00);
   tolua_function(tolua_S,"DragFloat",tolua_main_ImGui_DragFloat00);
   tolua_function(tolua_S,"DragFloat2",tolua_main_ImGui_DragFloat200);
   tolua_function(tolua_S,"DragInt",tolua_main_ImGui_DragInt00);
   tolua_function(tolua_S,"SliderFloat",tolua_main_ImGui_SliderFloat00);
   tolua_function(tolua_S,"SliderFloat2",tolua_main_ImGui_SliderFloat200);
   tolua_function(tolua_S,"SliderFloat3",tolua_main_ImGui_SliderFloat300);
   tolua_function(tolua_S,"SliderFloat4",tolua_main_ImGui_SliderFloat400);
   tolua_function(tolua_S,"SliderAngle",tolua_main_ImGui_SliderAngle00);
   tolua_function(tolua_S,"SliderInt",tolua_main_ImGui_SliderInt00);
   tolua_function(tolua_S,"SliderInt2",tolua_main_ImGui_SliderInt200);
   tolua_function(tolua_S,"SliderInt3",tolua_main_ImGui_SliderInt300);
   tolua_function(tolua_S,"SliderInt4",tolua_main_ImGui_SliderInt400);
   tolua_function(tolua_S,"VSliderFloat",tolua_main_ImGui_VSliderFloat00);
   tolua_function(tolua_S,"VSliderInt",tolua_main_ImGui_VSliderInt00);
   tolua_function(tolua_S,"ColorEdit3",tolua_main_ImGui_ColorEdit300);
   tolua_function(tolua_S,"ColorEdit4",tolua_main_ImGui_ColorEdit400);
   tolua_function(tolua_S,"ColorPicker3",tolua_main_ImGui_ColorPicker300);
   tolua_function(tolua_S,"ColorPicker4",tolua_main_ImGui_ColorPicker400);
   tolua_function(tolua_S,"ColorButton",tolua_main_ImGui_ColorButton00);
   tolua_function(tolua_S,"ColorButton",tolua_main_ImGui_ColorButton01);
   tolua_function(tolua_S,"SetColorEditOptions",tolua_main_ImGui_SetColorEditOptions00);
   tolua_function(tolua_S,"BeginDragDropSource",tolua_main_ImGui_BeginDragDropSource00);
   tolua_function(tolua_S,"SetDragDropPayload",tolua_main_ImGui_SetDragDropPayload00);
   tolua_function(tolua_S,"EndDragDropSource",tolua_main_ImGui_EndDragDropSource00);
   tolua_function(tolua_S,"BeginDragDropTarget",tolua_main_ImGui_BeginDragDropTarget00);
   tolua_function(tolua_S,"EndDragDropTarget",tolua_main_ImGui_EndDragDropTarget00);
   tolua_function(tolua_S,"PushID",tolua_main_ImGui_PushID00);
   tolua_function(tolua_S,"PushID",tolua_main_ImGui_PushID01);
   tolua_function(tolua_S,"PopID",tolua_main_ImGui_PopID00);
   tolua_function(tolua_S,"IsWindowAppearing",tolua_main_ImGui_IsWindowAppearing00);
   tolua_function(tolua_S,"IsWindowCollapsed",tolua_main_ImGui_IsWindowCollapsed00);
   tolua_function(tolua_S,"IsWindowFocused",tolua_main_ImGui_IsWindowFocused00);
   tolua_function(tolua_S,"IsWindowHovered",tolua_main_ImGui_IsWindowHovered00);
   tolua_function(tolua_S,"GetWindowDrawList",tolua_main_ImGui_GetWindowDrawList00);
   tolua_function(tolua_S,"GetWindowPos",tolua_main_ImGui_GetWindowPos00);
   tolua_function(tolua_S,"GetWindowSize",tolua_main_ImGui_GetWindowSize00);
   tolua_function(tolua_S,"GetWindowWidth",tolua_main_ImGui_GetWindowWidth00);
   tolua_function(tolua_S,"GetWindowHeight",tolua_main_ImGui_GetWindowHeight00);
   tolua_function(tolua_S,"GetContentRegionMax",tolua_main_ImGui_GetContentRegionMax00);
   tolua_function(tolua_S,"GetContentRegionAvail",tolua_main_ImGui_GetContentRegionAvail00);
   tolua_function(tolua_S,"GetWindowContentRegionMin",tolua_main_ImGui_GetWindowContentRegionMin00);
   tolua_function(tolua_S,"GetWindowContentRegionMax",tolua_main_ImGui_GetWindowContentRegionMax00);
   tolua_function(tolua_S,"GetWindowContentRegionWidth",tolua_main_ImGui_GetWindowContentRegionWidth00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"IM_COL32",tolua_main_IM_COL3200);
  tolua_constant(tolua_S,"ImGuiWindowFlags_None",ImGuiWindowFlags_None);
  tolua_constant(tolua_S,"ImGuiWindowFlags_NoTitleBar",ImGuiWindowFlags_NoTitleBar);
  tolua_constant(tolua_S,"ImGuiWindowFlags_NoResize",ImGuiWindowFlags_NoResize);
  tolua_constant(tolua_S,"ImGuiWindowFlags_NoMove",ImGuiWindowFlags_NoMove);
  tolua_constant(tolua_S,"ImGuiWindowFlags_NoScrollbar",ImGuiWindowFlags_NoScrollbar);
  tolua_constant(tolua_S,"ImGuiWindowFlags_NoScrollWithMouse",ImGuiWindowFlags_NoScrollWithMouse);
  tolua_constant(tolua_S,"ImGuiWindowFlags_NoCollapse",ImGuiWindowFlags_NoCollapse);
  tolua_constant(tolua_S,"ImGuiWindowFlags_AlwaysAutoResize",ImGuiWindowFlags_AlwaysAutoResize);
  tolua_constant(tolua_S,"ImGuiWindowFlags_NoBackground",ImGuiWindowFlags_NoBackground);
  tolua_constant(tolua_S,"ImGuiWindowFlags_NoSavedSettings",ImGuiWindowFlags_NoSavedSettings);
  tolua_constant(tolua_S,"ImGuiWindowFlags_NoMouseInputs",ImGuiWindowFlags_NoMouseInputs);
  tolua_constant(tolua_S,"ImGuiWindowFlags_MenuBar",ImGuiWindowFlags_MenuBar);
  tolua_constant(tolua_S,"ImGuiWindowFlags_HorizontalScrollbar",ImGuiWindowFlags_HorizontalScrollbar);
  tolua_constant(tolua_S,"ImGuiWindowFlags_NoFocusOnAppearing",ImGuiWindowFlags_NoFocusOnAppearing);
  tolua_constant(tolua_S,"ImGuiWindowFlags_NoBringToFrontOnFocus",ImGuiWindowFlags_NoBringToFrontOnFocus);
  tolua_constant(tolua_S,"ImGuiWindowFlags_AlwaysVerticalScrollbar",ImGuiWindowFlags_AlwaysVerticalScrollbar);
  tolua_constant(tolua_S,"ImGuiWindowFlags_AlwaysHorizontalScrollbar",ImGuiWindowFlags_AlwaysHorizontalScrollbar);
  tolua_constant(tolua_S,"ImGuiWindowFlags_AlwaysUseWindowPadding",ImGuiWindowFlags_AlwaysUseWindowPadding);
  tolua_constant(tolua_S,"ImGuiWindowFlags_NoNavInputs",ImGuiWindowFlags_NoNavInputs);
  tolua_constant(tolua_S,"ImGuiWindowFlags_NoNavFocus",ImGuiWindowFlags_NoNavFocus);
  tolua_constant(tolua_S,"ImGuiWindowFlags_UnsavedDocument",ImGuiWindowFlags_UnsavedDocument);
  tolua_constant(tolua_S,"ImGuiWindowFlags_NoNav",ImGuiWindowFlags_NoNav);
  tolua_constant(tolua_S,"ImGuiWindowFlags_NoDecoration",ImGuiWindowFlags_NoDecoration);
  tolua_constant(tolua_S,"ImGuiWindowFlags_NoInputs",ImGuiWindowFlags_NoInputs);
  tolua_constant(tolua_S,"ImGuiWindowFlags_NavFlattened",ImGuiWindowFlags_NavFlattened);
  tolua_constant(tolua_S,"ImGuiWindowFlags_ChildWindow",ImGuiWindowFlags_ChildWindow);
  tolua_constant(tolua_S,"ImGuiWindowFlags_Tooltip",ImGuiWindowFlags_Tooltip);
  tolua_constant(tolua_S,"ImGuiWindowFlags_Popup",ImGuiWindowFlags_Popup);
  tolua_constant(tolua_S,"ImGuiWindowFlags_Modal",ImGuiWindowFlags_Modal);
  tolua_constant(tolua_S,"ImGuiWindowFlags_ChildMenu",ImGuiWindowFlags_ChildMenu);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_None",ImGuiInputTextFlags_None);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_CharsDecimal",ImGuiInputTextFlags_CharsDecimal);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_CharsHexadecimal",ImGuiInputTextFlags_CharsHexadecimal);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_CharsUppercase",ImGuiInputTextFlags_CharsUppercase);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_CharsNoBlank",ImGuiInputTextFlags_CharsNoBlank);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_AutoSelectAll",ImGuiInputTextFlags_AutoSelectAll);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_EnterReturnsTrue",ImGuiInputTextFlags_EnterReturnsTrue);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_CallbackCompletion",ImGuiInputTextFlags_CallbackCompletion);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_CallbackHistory",ImGuiInputTextFlags_CallbackHistory);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_CallbackAlways",ImGuiInputTextFlags_CallbackAlways);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_CallbackCharFilter",ImGuiInputTextFlags_CallbackCharFilter);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_AllowTabInput",ImGuiInputTextFlags_AllowTabInput);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_CtrlEnterForNewLine",ImGuiInputTextFlags_CtrlEnterForNewLine);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_NoHorizontalScroll",ImGuiInputTextFlags_NoHorizontalScroll);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_AlwaysInsertMode",ImGuiInputTextFlags_AlwaysInsertMode);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_ReadOnly",ImGuiInputTextFlags_ReadOnly);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_Password",ImGuiInputTextFlags_Password);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_NoUndoRedo",ImGuiInputTextFlags_NoUndoRedo);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_CharsScientific",ImGuiInputTextFlags_CharsScientific);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_CallbackResize",ImGuiInputTextFlags_CallbackResize);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_Multiline",ImGuiInputTextFlags_Multiline);
  tolua_constant(tolua_S,"ImGuiInputTextFlags_NoMarkEdited",ImGuiInputTextFlags_NoMarkEdited);
  tolua_constant(tolua_S,"ImGuiTreeNodeFlags_None",ImGuiTreeNodeFlags_None);
  tolua_constant(tolua_S,"ImGuiTreeNodeFlags_Selected",ImGuiTreeNodeFlags_Selected);
  tolua_constant(tolua_S,"ImGuiTreeNodeFlags_Framed",ImGuiTreeNodeFlags_Framed);
  tolua_constant(tolua_S,"ImGuiTreeNodeFlags_AllowItemOverlap",ImGuiTreeNodeFlags_AllowItemOverlap);
  tolua_constant(tolua_S,"ImGuiTreeNodeFlags_NoTreePushOnOpen",ImGuiTreeNodeFlags_NoTreePushOnOpen);
  tolua_constant(tolua_S,"ImGuiTreeNodeFlags_NoAutoOpenOnLog",ImGuiTreeNodeFlags_NoAutoOpenOnLog);
  tolua_constant(tolua_S,"ImGuiTreeNodeFlags_DefaultOpen",ImGuiTreeNodeFlags_DefaultOpen);
  tolua_constant(tolua_S,"ImGuiTreeNodeFlags_OpenOnDoubleClick",ImGuiTreeNodeFlags_OpenOnDoubleClick);
  tolua_constant(tolua_S,"ImGuiTreeNodeFlags_OpenOnArrow",ImGuiTreeNodeFlags_OpenOnArrow);
  tolua_constant(tolua_S,"ImGuiTreeNodeFlags_Leaf",ImGuiTreeNodeFlags_Leaf);
  tolua_constant(tolua_S,"ImGuiTreeNodeFlags_Bullet",ImGuiTreeNodeFlags_Bullet);
  tolua_constant(tolua_S,"ImGuiTreeNodeFlags_FramePadding",ImGuiTreeNodeFlags_FramePadding);
  tolua_constant(tolua_S,"ImGuiTreeNodeFlags_NavLeftJumpsBackHere",ImGuiTreeNodeFlags_NavLeftJumpsBackHere);
  tolua_constant(tolua_S,"ImGuiTreeNodeFlags_CollapsingHeader",ImGuiTreeNodeFlags_CollapsingHeader);
  tolua_constant(tolua_S,"ImGuiSelectableFlags_None",ImGuiSelectableFlags_None);
  tolua_constant(tolua_S,"ImGuiSelectableFlags_DontClosePopups",ImGuiSelectableFlags_DontClosePopups);
  tolua_constant(tolua_S,"ImGuiSelectableFlags_SpanAllColumns",ImGuiSelectableFlags_SpanAllColumns);
  tolua_constant(tolua_S,"ImGuiSelectableFlags_AllowDoubleClick",ImGuiSelectableFlags_AllowDoubleClick);
  tolua_constant(tolua_S,"ImGuiSelectableFlags_Disabled",ImGuiSelectableFlags_Disabled);
  tolua_constant(tolua_S,"ImGuiComboFlags_None",ImGuiComboFlags_None);
  tolua_constant(tolua_S,"ImGuiComboFlags_PopupAlignLeft",ImGuiComboFlags_PopupAlignLeft);
  tolua_constant(tolua_S,"ImGuiComboFlags_HeightSmall",ImGuiComboFlags_HeightSmall);
  tolua_constant(tolua_S,"ImGuiComboFlags_HeightRegular",ImGuiComboFlags_HeightRegular);
  tolua_constant(tolua_S,"ImGuiComboFlags_HeightLarge",ImGuiComboFlags_HeightLarge);
  tolua_constant(tolua_S,"ImGuiComboFlags_HeightLargest",ImGuiComboFlags_HeightLargest);
  tolua_constant(tolua_S,"ImGuiComboFlags_NoArrowButton",ImGuiComboFlags_NoArrowButton);
  tolua_constant(tolua_S,"ImGuiComboFlags_NoPreview",ImGuiComboFlags_NoPreview);
  tolua_constant(tolua_S,"ImGuiComboFlags_HeightMask_",ImGuiComboFlags_HeightMask_);
  tolua_constant(tolua_S,"ImGuiTabBarFlags_None",ImGuiTabBarFlags_None);
  tolua_constant(tolua_S,"ImGuiTabBarFlags_Reorderable",ImGuiTabBarFlags_Reorderable);
  tolua_constant(tolua_S,"ImGuiTabBarFlags_AutoSelectNewTabs",ImGuiTabBarFlags_AutoSelectNewTabs);
  tolua_constant(tolua_S,"ImGuiTabBarFlags_TabListPopupButton",ImGuiTabBarFlags_TabListPopupButton);
  tolua_constant(tolua_S,"ImGuiTabBarFlags_NoCloseWithMiddleMouseButton",ImGuiTabBarFlags_NoCloseWithMiddleMouseButton);
  tolua_constant(tolua_S,"ImGuiTabBarFlags_NoTabListScrollingButtons",ImGuiTabBarFlags_NoTabListScrollingButtons);
  tolua_constant(tolua_S,"ImGuiTabBarFlags_NoTooltip",ImGuiTabBarFlags_NoTooltip);
  tolua_constant(tolua_S,"ImGuiTabBarFlags_FittingPolicyResizeDown",ImGuiTabBarFlags_FittingPolicyResizeDown);
  tolua_constant(tolua_S,"ImGuiTabBarFlags_FittingPolicyScroll",ImGuiTabBarFlags_FittingPolicyScroll);
  tolua_constant(tolua_S,"ImGuiTabBarFlags_FittingPolicyMask_",ImGuiTabBarFlags_FittingPolicyMask_);
  tolua_constant(tolua_S,"ImGuiTabBarFlags_FittingPolicyDefault_",ImGuiTabBarFlags_FittingPolicyDefault_);
  tolua_constant(tolua_S,"ImGuiTabItemFlags_None",ImGuiTabItemFlags_None);
  tolua_constant(tolua_S,"ImGuiTabItemFlags_UnsavedDocument",ImGuiTabItemFlags_UnsavedDocument);
  tolua_constant(tolua_S,"ImGuiTabItemFlags_SetSelected",ImGuiTabItemFlags_SetSelected);
  tolua_constant(tolua_S,"ImGuiTabItemFlags_NoCloseWithMiddleMouseButton",ImGuiTabItemFlags_NoCloseWithMiddleMouseButton);
  tolua_constant(tolua_S,"ImGuiTabItemFlags_NoPushId",ImGuiTabItemFlags_NoPushId);
  tolua_constant(tolua_S,"ImGuiFocusedFlags_None",ImGuiFocusedFlags_None);
  tolua_constant(tolua_S,"ImGuiFocusedFlags_ChildWindows",ImGuiFocusedFlags_ChildWindows);
  tolua_constant(tolua_S,"ImGuiFocusedFlags_RootWindow",ImGuiFocusedFlags_RootWindow);
  tolua_constant(tolua_S,"ImGuiFocusedFlags_AnyWindow",ImGuiFocusedFlags_AnyWindow);
  tolua_constant(tolua_S,"ImGuiFocusedFlags_RootAndChildWindows",ImGuiFocusedFlags_RootAndChildWindows);
  tolua_constant(tolua_S,"ImGuiHoveredFlags_None",ImGuiHoveredFlags_None);
  tolua_constant(tolua_S,"ImGuiHoveredFlags_ChildWindows",ImGuiHoveredFlags_ChildWindows);
  tolua_constant(tolua_S,"ImGuiHoveredFlags_RootWindow",ImGuiHoveredFlags_RootWindow);
  tolua_constant(tolua_S,"ImGuiHoveredFlags_AnyWindow",ImGuiHoveredFlags_AnyWindow);
  tolua_constant(tolua_S,"ImGuiHoveredFlags_AllowWhenBlockedByPopup",ImGuiHoveredFlags_AllowWhenBlockedByPopup);
  tolua_constant(tolua_S,"ImGuiHoveredFlags_AllowWhenBlockedByActiveItem",ImGuiHoveredFlags_AllowWhenBlockedByActiveItem);
  tolua_constant(tolua_S,"ImGuiHoveredFlags_AllowWhenOverlapped",ImGuiHoveredFlags_AllowWhenOverlapped);
  tolua_constant(tolua_S,"ImGuiHoveredFlags_AllowWhenDisabled",ImGuiHoveredFlags_AllowWhenDisabled);
  tolua_constant(tolua_S,"ImGuiHoveredFlags_RectOnly",ImGuiHoveredFlags_RectOnly);
  tolua_constant(tolua_S,"ImGuiHoveredFlags_RootAndChildWindows",ImGuiHoveredFlags_RootAndChildWindows);
  tolua_constant(tolua_S,"ImGuiDragDropFlags_None",ImGuiDragDropFlags_None);
  tolua_constant(tolua_S,"ImGuiDragDropFlags_SourceNoPreviewTooltip",ImGuiDragDropFlags_SourceNoPreviewTooltip);
  tolua_constant(tolua_S,"ImGuiDragDropFlags_SourceNoDisableHover",ImGuiDragDropFlags_SourceNoDisableHover);
  tolua_constant(tolua_S,"ImGuiDragDropFlags_SourceNoHoldToOpenOthers",ImGuiDragDropFlags_SourceNoHoldToOpenOthers);
  tolua_constant(tolua_S,"ImGuiDragDropFlags_SourceAllowNullID",ImGuiDragDropFlags_SourceAllowNullID);
  tolua_constant(tolua_S,"ImGuiDragDropFlags_SourceExtern",ImGuiDragDropFlags_SourceExtern);
  tolua_constant(tolua_S,"ImGuiDragDropFlags_SourceAutoExpirePayload",ImGuiDragDropFlags_SourceAutoExpirePayload);
  tolua_constant(tolua_S,"ImGuiDragDropFlags_AcceptBeforeDelivery",ImGuiDragDropFlags_AcceptBeforeDelivery);
  tolua_constant(tolua_S,"ImGuiDragDropFlags_AcceptNoDrawDefaultRect",ImGuiDragDropFlags_AcceptNoDrawDefaultRect);
  tolua_constant(tolua_S,"ImGuiDragDropFlags_AcceptNoPreviewTooltip",ImGuiDragDropFlags_AcceptNoPreviewTooltip);
  tolua_constant(tolua_S,"ImGuiDragDropFlags_AcceptPeekOnly",ImGuiDragDropFlags_AcceptPeekOnly);
  tolua_constant(tolua_S,"ImGuiDataType_S8",ImGuiDataType_S8);
  tolua_constant(tolua_S,"ImGuiDataType_U8",ImGuiDataType_U8);
  tolua_constant(tolua_S,"ImGuiDataType_S16",ImGuiDataType_S16);
  tolua_constant(tolua_S,"ImGuiDataType_U16",ImGuiDataType_U16);
  tolua_constant(tolua_S,"ImGuiDataType_S32",ImGuiDataType_S32);
  tolua_constant(tolua_S,"ImGuiDataType_U32",ImGuiDataType_U32);
  tolua_constant(tolua_S,"ImGuiDataType_S64",ImGuiDataType_S64);
  tolua_constant(tolua_S,"ImGuiDataType_U64",ImGuiDataType_U64);
  tolua_constant(tolua_S,"ImGuiDataType_Float",ImGuiDataType_Float);
  tolua_constant(tolua_S,"ImGuiDataType_Double",ImGuiDataType_Double);
  tolua_constant(tolua_S,"ImGuiDataType_COUNT",ImGuiDataType_COUNT);
  tolua_constant(tolua_S,"ImGuiDir_None",ImGuiDir_None);
  tolua_constant(tolua_S,"ImGuiDir_Left",ImGuiDir_Left);
  tolua_constant(tolua_S,"ImGuiDir_Right",ImGuiDir_Right);
  tolua_constant(tolua_S,"ImGuiDir_Up",ImGuiDir_Up);
  tolua_constant(tolua_S,"ImGuiDir_Down",ImGuiDir_Down);
  tolua_constant(tolua_S,"ImGuiDir_COUNT",ImGuiDir_COUNT);
  tolua_constant(tolua_S,"ImGuiKey_Tab",ImGuiKey_Tab);
  tolua_constant(tolua_S,"ImGuiKey_LeftArrow",ImGuiKey_LeftArrow);
  tolua_constant(tolua_S,"ImGuiKey_RightArrow",ImGuiKey_RightArrow);
  tolua_constant(tolua_S,"ImGuiKey_UpArrow",ImGuiKey_UpArrow);
  tolua_constant(tolua_S,"ImGuiKey_DownArrow",ImGuiKey_DownArrow);
  tolua_constant(tolua_S,"ImGuiKey_PageUp",ImGuiKey_PageUp);
  tolua_constant(tolua_S,"ImGuiKey_PageDown",ImGuiKey_PageDown);
  tolua_constant(tolua_S,"ImGuiKey_Home",ImGuiKey_Home);
  tolua_constant(tolua_S,"ImGuiKey_End",ImGuiKey_End);
  tolua_constant(tolua_S,"ImGuiKey_Insert",ImGuiKey_Insert);
  tolua_constant(tolua_S,"ImGuiKey_Delete",ImGuiKey_Delete);
  tolua_constant(tolua_S,"ImGuiKey_Backspace",ImGuiKey_Backspace);
  tolua_constant(tolua_S,"ImGuiKey_Space",ImGuiKey_Space);
  tolua_constant(tolua_S,"ImGuiKey_Enter",ImGuiKey_Enter);
  tolua_constant(tolua_S,"ImGuiKey_Escape",ImGuiKey_Escape);
  tolua_constant(tolua_S,"ImGuiKey_0",ImGuiKey_0);
  tolua_constant(tolua_S,"ImGuiKey_1",ImGuiKey_1);
  tolua_constant(tolua_S,"ImGuiKey_2",ImGuiKey_2);
  tolua_constant(tolua_S,"ImGuiKey_3",ImGuiKey_3);
  tolua_constant(tolua_S,"ImGuiKey_4",ImGuiKey_4);
  tolua_constant(tolua_S,"ImGuiKey_5",ImGuiKey_5);
  tolua_constant(tolua_S,"ImGuiKey_6",ImGuiKey_6);
  tolua_constant(tolua_S,"ImGuiKey_7",ImGuiKey_7);
  tolua_constant(tolua_S,"ImGuiKey_8",ImGuiKey_8);
  tolua_constant(tolua_S,"ImGuiKey_9",ImGuiKey_9);
  tolua_constant(tolua_S,"ImGuiKey_A",ImGuiKey_A);
  tolua_constant(tolua_S,"ImGuiKey_B",ImGuiKey_B);
  tolua_constant(tolua_S,"ImGuiKey_C",ImGuiKey_C);
  tolua_constant(tolua_S,"ImGuiKey_D",ImGuiKey_D);
  tolua_constant(tolua_S,"ImGuiKey_E",ImGuiKey_E);
  tolua_constant(tolua_S,"ImGuiKey_F",ImGuiKey_F);
  tolua_constant(tolua_S,"ImGuiKey_G",ImGuiKey_G);
  tolua_constant(tolua_S,"ImGuiKey_H",ImGuiKey_H);
  tolua_constant(tolua_S,"ImGuiKey_I",ImGuiKey_I);
  tolua_constant(tolua_S,"ImGuiKey_J",ImGuiKey_J);
  tolua_constant(tolua_S,"ImGuiKey_K",ImGuiKey_K);
  tolua_constant(tolua_S,"ImGuiKey_L",ImGuiKey_L);
  tolua_constant(tolua_S,"ImGuiKey_M",ImGuiKey_M);
  tolua_constant(tolua_S,"ImGuiKey_N",ImGuiKey_N);
  tolua_constant(tolua_S,"ImGuiKey_O",ImGuiKey_O);
  tolua_constant(tolua_S,"ImGuiKey_P",ImGuiKey_P);
  tolua_constant(tolua_S,"ImGuiKey_Q",ImGuiKey_Q);
  tolua_constant(tolua_S,"ImGuiKey_R",ImGuiKey_R);
  tolua_constant(tolua_S,"ImGuiKey_S",ImGuiKey_S);
  tolua_constant(tolua_S,"ImGuiKey_T",ImGuiKey_T);
  tolua_constant(tolua_S,"ImGuiKey_U",ImGuiKey_U);
  tolua_constant(tolua_S,"ImGuiKey_V",ImGuiKey_V);
  tolua_constant(tolua_S,"ImGuiKey_W",ImGuiKey_W);
  tolua_constant(tolua_S,"ImGuiKey_X",ImGuiKey_X);
  tolua_constant(tolua_S,"ImGuiKey_Y",ImGuiKey_Y);
  tolua_constant(tolua_S,"ImGuiKey_Z",ImGuiKey_Z);
  tolua_constant(tolua_S,"ImGuiKey_F1",ImGuiKey_F1);
  tolua_constant(tolua_S,"ImGuiKey_F2",ImGuiKey_F2);
  tolua_constant(tolua_S,"ImGuiKey_F3",ImGuiKey_F3);
  tolua_constant(tolua_S,"ImGuiKey_F4",ImGuiKey_F4);
  tolua_constant(tolua_S,"ImGuiKey_F5",ImGuiKey_F5);
  tolua_constant(tolua_S,"ImGuiKey_F6",ImGuiKey_F6);
  tolua_constant(tolua_S,"ImGuiKey_F7",ImGuiKey_F7);
  tolua_constant(tolua_S,"ImGuiKey_F8",ImGuiKey_F8);
  tolua_constant(tolua_S,"ImGuiKey_F9",ImGuiKey_F9);
  tolua_constant(tolua_S,"ImGuiKey_F10",ImGuiKey_F10);
  tolua_constant(tolua_S,"ImGuiKey_F11",ImGuiKey_F11);
  tolua_constant(tolua_S,"ImGuiKey_F12",ImGuiKey_F12);
  tolua_constant(tolua_S,"ImGuiKey_COUNT",ImGuiKey_COUNT);
  tolua_constant(tolua_S,"ImGuiNavInput_Activate",ImGuiNavInput_Activate);
  tolua_constant(tolua_S,"ImGuiNavInput_Cancel",ImGuiNavInput_Cancel);
  tolua_constant(tolua_S,"ImGuiNavInput_Input",ImGuiNavInput_Input);
  tolua_constant(tolua_S,"ImGuiNavInput_Menu",ImGuiNavInput_Menu);
  tolua_constant(tolua_S,"ImGuiNavInput_DpadLeft",ImGuiNavInput_DpadLeft);
  tolua_constant(tolua_S,"ImGuiNavInput_DpadRight",ImGuiNavInput_DpadRight);
  tolua_constant(tolua_S,"ImGuiNavInput_DpadUp",ImGuiNavInput_DpadUp);
  tolua_constant(tolua_S,"ImGuiNavInput_DpadDown",ImGuiNavInput_DpadDown);
  tolua_constant(tolua_S,"ImGuiNavInput_LStickLeft",ImGuiNavInput_LStickLeft);
  tolua_constant(tolua_S,"ImGuiNavInput_LStickRight",ImGuiNavInput_LStickRight);
  tolua_constant(tolua_S,"ImGuiNavInput_LStickUp",ImGuiNavInput_LStickUp);
  tolua_constant(tolua_S,"ImGuiNavInput_LStickDown",ImGuiNavInput_LStickDown);
  tolua_constant(tolua_S,"ImGuiNavInput_FocusPrev",ImGuiNavInput_FocusPrev);
  tolua_constant(tolua_S,"ImGuiNavInput_FocusNext",ImGuiNavInput_FocusNext);
  tolua_constant(tolua_S,"ImGuiNavInput_TweakSlow",ImGuiNavInput_TweakSlow);
  tolua_constant(tolua_S,"ImGuiNavInput_TweakFast",ImGuiNavInput_TweakFast);
  tolua_constant(tolua_S,"ImGuiNavInput_KeyMenu_",ImGuiNavInput_KeyMenu_);
  tolua_constant(tolua_S,"ImGuiNavInput_KeyTab_",ImGuiNavInput_KeyTab_);
  tolua_constant(tolua_S,"ImGuiNavInput_KeyLeft_",ImGuiNavInput_KeyLeft_);
  tolua_constant(tolua_S,"ImGuiNavInput_KeyRight_",ImGuiNavInput_KeyRight_);
  tolua_constant(tolua_S,"ImGuiNavInput_KeyUp_",ImGuiNavInput_KeyUp_);
  tolua_constant(tolua_S,"ImGuiNavInput_KeyDown_",ImGuiNavInput_KeyDown_);
  tolua_constant(tolua_S,"ImGuiNavInput_COUNT",ImGuiNavInput_COUNT);
  tolua_constant(tolua_S,"ImGuiNavInput_InternalStart_",ImGuiNavInput_InternalStart_);
  tolua_constant(tolua_S,"ImGuiConfigFlags_None",ImGuiConfigFlags_None);
  tolua_constant(tolua_S,"ImGuiConfigFlags_NavEnableKeyboard",ImGuiConfigFlags_NavEnableKeyboard);
  tolua_constant(tolua_S,"ImGuiConfigFlags_NavEnableGamepad",ImGuiConfigFlags_NavEnableGamepad);
  tolua_constant(tolua_S,"ImGuiConfigFlags_NavEnableSetMousePos",ImGuiConfigFlags_NavEnableSetMousePos);
  tolua_constant(tolua_S,"ImGuiConfigFlags_NavNoCaptureKeyboard",ImGuiConfigFlags_NavNoCaptureKeyboard);
  tolua_constant(tolua_S,"ImGuiConfigFlags_NoMouse",ImGuiConfigFlags_NoMouse);
  tolua_constant(tolua_S,"ImGuiConfigFlags_NoMouseCursorChange",ImGuiConfigFlags_NoMouseCursorChange);
  tolua_constant(tolua_S,"ImGuiConfigFlags_IsSRGB",ImGuiConfigFlags_IsSRGB);
  tolua_constant(tolua_S,"ImGuiConfigFlags_IsTouchScreen",ImGuiConfigFlags_IsTouchScreen);
  tolua_constant(tolua_S,"ImGuiBackendFlags_None",ImGuiBackendFlags_None);
  tolua_constant(tolua_S,"ImGuiBackendFlags_HasGamepad",ImGuiBackendFlags_HasGamepad);
  tolua_constant(tolua_S,"ImGuiBackendFlags_HasMouseCursors",ImGuiBackendFlags_HasMouseCursors);
  tolua_constant(tolua_S,"ImGuiBackendFlags_HasSetMousePos",ImGuiBackendFlags_HasSetMousePos);
  tolua_constant(tolua_S,"ImGuiBackendFlags_RendererHasVtxOffset",ImGuiBackendFlags_RendererHasVtxOffset);
  tolua_constant(tolua_S,"ImGuiCol_Text",ImGuiCol_Text);
  tolua_constant(tolua_S,"ImGuiCol_TextDisabled",ImGuiCol_TextDisabled);
  tolua_constant(tolua_S,"ImGuiCol_WindowBg",ImGuiCol_WindowBg);
  tolua_constant(tolua_S,"ImGuiCol_ChildBg",ImGuiCol_ChildBg);
  tolua_constant(tolua_S,"ImGuiCol_PopupBg",ImGuiCol_PopupBg);
  tolua_constant(tolua_S,"ImGuiCol_Border",ImGuiCol_Border);
  tolua_constant(tolua_S,"ImGuiCol_BorderShadow",ImGuiCol_BorderShadow);
  tolua_constant(tolua_S,"ImGuiCol_FrameBg",ImGuiCol_FrameBg);
  tolua_constant(tolua_S,"ImGuiCol_FrameBgHovered",ImGuiCol_FrameBgHovered);
  tolua_constant(tolua_S,"ImGuiCol_FrameBgActive",ImGuiCol_FrameBgActive);
  tolua_constant(tolua_S,"ImGuiCol_TitleBg",ImGuiCol_TitleBg);
  tolua_constant(tolua_S,"ImGuiCol_TitleBgActive",ImGuiCol_TitleBgActive);
  tolua_constant(tolua_S,"ImGuiCol_TitleBgCollapsed",ImGuiCol_TitleBgCollapsed);
  tolua_constant(tolua_S,"ImGuiCol_MenuBarBg",ImGuiCol_MenuBarBg);
  tolua_constant(tolua_S,"ImGuiCol_ScrollbarBg",ImGuiCol_ScrollbarBg);
  tolua_constant(tolua_S,"ImGuiCol_ScrollbarGrab",ImGuiCol_ScrollbarGrab);
  tolua_constant(tolua_S,"ImGuiCol_ScrollbarGrabHovered",ImGuiCol_ScrollbarGrabHovered);
  tolua_constant(tolua_S,"ImGuiCol_ScrollbarGrabActive",ImGuiCol_ScrollbarGrabActive);
  tolua_constant(tolua_S,"ImGuiCol_CheckMark",ImGuiCol_CheckMark);
  tolua_constant(tolua_S,"ImGuiCol_SliderGrab",ImGuiCol_SliderGrab);
  tolua_constant(tolua_S,"ImGuiCol_SliderGrabActive",ImGuiCol_SliderGrabActive);
  tolua_constant(tolua_S,"ImGuiCol_Button",ImGuiCol_Button);
  tolua_constant(tolua_S,"ImGuiCol_ButtonHovered",ImGuiCol_ButtonHovered);
  tolua_constant(tolua_S,"ImGuiCol_ButtonActive",ImGuiCol_ButtonActive);
  tolua_constant(tolua_S,"ImGuiCol_Header",ImGuiCol_Header);
  tolua_constant(tolua_S,"ImGuiCol_HeaderHovered",ImGuiCol_HeaderHovered);
  tolua_constant(tolua_S,"ImGuiCol_HeaderActive",ImGuiCol_HeaderActive);
  tolua_constant(tolua_S,"ImGuiCol_Separator",ImGuiCol_Separator);
  tolua_constant(tolua_S,"ImGuiCol_SeparatorHovered",ImGuiCol_SeparatorHovered);
  tolua_constant(tolua_S,"ImGuiCol_SeparatorActive",ImGuiCol_SeparatorActive);
  tolua_constant(tolua_S,"ImGuiCol_ResizeGrip",ImGuiCol_ResizeGrip);
  tolua_constant(tolua_S,"ImGuiCol_ResizeGripHovered",ImGuiCol_ResizeGripHovered);
  tolua_constant(tolua_S,"ImGuiCol_ResizeGripActive",ImGuiCol_ResizeGripActive);
  tolua_constant(tolua_S,"ImGuiCol_Tab",ImGuiCol_Tab);
  tolua_constant(tolua_S,"ImGuiCol_TabHovered",ImGuiCol_TabHovered);
  tolua_constant(tolua_S,"ImGuiCol_TabActive",ImGuiCol_TabActive);
  tolua_constant(tolua_S,"ImGuiCol_TabUnfocused",ImGuiCol_TabUnfocused);
  tolua_constant(tolua_S,"ImGuiCol_TabUnfocusedActive",ImGuiCol_TabUnfocusedActive);
  tolua_constant(tolua_S,"ImGuiCol_PlotLines",ImGuiCol_PlotLines);
  tolua_constant(tolua_S,"ImGuiCol_PlotLinesHovered",ImGuiCol_PlotLinesHovered);
  tolua_constant(tolua_S,"ImGuiCol_PlotHistogram",ImGuiCol_PlotHistogram);
  tolua_constant(tolua_S,"ImGuiCol_PlotHistogramHovered",ImGuiCol_PlotHistogramHovered);
  tolua_constant(tolua_S,"ImGuiCol_TextSelectedBg",ImGuiCol_TextSelectedBg);
  tolua_constant(tolua_S,"ImGuiCol_DragDropTarget",ImGuiCol_DragDropTarget);
  tolua_constant(tolua_S,"ImGuiCol_NavHighlight",ImGuiCol_NavHighlight);
  tolua_constant(tolua_S,"ImGuiCol_NavWindowingHighlight",ImGuiCol_NavWindowingHighlight);
  tolua_constant(tolua_S,"ImGuiCol_NavWindowingDimBg",ImGuiCol_NavWindowingDimBg);
  tolua_constant(tolua_S,"ImGuiCol_ModalWindowDimBg",ImGuiCol_ModalWindowDimBg);
  tolua_constant(tolua_S,"ImGuiCol_COUNT",ImGuiCol_COUNT);
  tolua_constant(tolua_S,"ImGuiStyleVar_Alpha",ImGuiStyleVar_Alpha);
  tolua_constant(tolua_S,"ImGuiStyleVar_WindowPadding",ImGuiStyleVar_WindowPadding);
  tolua_constant(tolua_S,"ImGuiStyleVar_WindowRounding",ImGuiStyleVar_WindowRounding);
  tolua_constant(tolua_S,"ImGuiStyleVar_WindowBorderSize",ImGuiStyleVar_WindowBorderSize);
  tolua_constant(tolua_S,"ImGuiStyleVar_WindowMinSize",ImGuiStyleVar_WindowMinSize);
  tolua_constant(tolua_S,"ImGuiStyleVar_WindowTitleAlign",ImGuiStyleVar_WindowTitleAlign);
  tolua_constant(tolua_S,"ImGuiStyleVar_ChildRounding",ImGuiStyleVar_ChildRounding);
  tolua_constant(tolua_S,"ImGuiStyleVar_ChildBorderSize",ImGuiStyleVar_ChildBorderSize);
  tolua_constant(tolua_S,"ImGuiStyleVar_PopupRounding",ImGuiStyleVar_PopupRounding);
  tolua_constant(tolua_S,"ImGuiStyleVar_PopupBorderSize",ImGuiStyleVar_PopupBorderSize);
  tolua_constant(tolua_S,"ImGuiStyleVar_FramePadding",ImGuiStyleVar_FramePadding);
  tolua_constant(tolua_S,"ImGuiStyleVar_FrameRounding",ImGuiStyleVar_FrameRounding);
  tolua_constant(tolua_S,"ImGuiStyleVar_FrameBorderSize",ImGuiStyleVar_FrameBorderSize);
  tolua_constant(tolua_S,"ImGuiStyleVar_ItemSpacing",ImGuiStyleVar_ItemSpacing);
  tolua_constant(tolua_S,"ImGuiStyleVar_ItemInnerSpacing",ImGuiStyleVar_ItemInnerSpacing);
  tolua_constant(tolua_S,"ImGuiStyleVar_IndentSpacing",ImGuiStyleVar_IndentSpacing);
  tolua_constant(tolua_S,"ImGuiStyleVar_ScrollbarSize",ImGuiStyleVar_ScrollbarSize);
  tolua_constant(tolua_S,"ImGuiStyleVar_ScrollbarRounding",ImGuiStyleVar_ScrollbarRounding);
  tolua_constant(tolua_S,"ImGuiStyleVar_GrabMinSize",ImGuiStyleVar_GrabMinSize);
  tolua_constant(tolua_S,"ImGuiStyleVar_GrabRounding",ImGuiStyleVar_GrabRounding);
  tolua_constant(tolua_S,"ImGuiStyleVar_TabRounding",ImGuiStyleVar_TabRounding);
  tolua_constant(tolua_S,"ImGuiStyleVar_ButtonTextAlign",ImGuiStyleVar_ButtonTextAlign);
  tolua_constant(tolua_S,"ImGuiStyleVar_SelectableTextAlign",ImGuiStyleVar_SelectableTextAlign);
  tolua_constant(tolua_S,"ImGuiStyleVar_LayoutAlign",ImGuiStyleVar_LayoutAlign);
  tolua_constant(tolua_S,"ImGuiStyleVar_COUNT",ImGuiStyleVar_COUNT);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_None",ImGuiColorEditFlags_None);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_NoAlpha",ImGuiColorEditFlags_NoAlpha);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_NoPicker",ImGuiColorEditFlags_NoPicker);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_NoOptions",ImGuiColorEditFlags_NoOptions);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_NoSmallPreview",ImGuiColorEditFlags_NoSmallPreview);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_NoInputs",ImGuiColorEditFlags_NoInputs);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_NoTooltip",ImGuiColorEditFlags_NoTooltip);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_NoLabel",ImGuiColorEditFlags_NoLabel);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_NoSidePreview",ImGuiColorEditFlags_NoSidePreview);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_NoDragDrop",ImGuiColorEditFlags_NoDragDrop);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_AlphaBar",ImGuiColorEditFlags_AlphaBar);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_AlphaPreview",ImGuiColorEditFlags_AlphaPreview);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_AlphaPreviewHalf",ImGuiColorEditFlags_AlphaPreviewHalf);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_HDR",ImGuiColorEditFlags_HDR);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_DisplayRGB",ImGuiColorEditFlags_DisplayRGB);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_DisplayHSV",ImGuiColorEditFlags_DisplayHSV);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_DisplayHex",ImGuiColorEditFlags_DisplayHex);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_Uint8",ImGuiColorEditFlags_Uint8);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_Float",ImGuiColorEditFlags_Float);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_PickerHueBar",ImGuiColorEditFlags_PickerHueBar);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_PickerHueWheel",ImGuiColorEditFlags_PickerHueWheel);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_InputRGB",ImGuiColorEditFlags_InputRGB);
  tolua_constant(tolua_S,"ImGuiColorEditFlags_InputHSV",ImGuiColorEditFlags_InputHSV);
  tolua_constant(tolua_S,"ImGuiColorEditFlags__OptionsDefault",ImGuiColorEditFlags__OptionsDefault);
  tolua_constant(tolua_S,"ImGuiColorEditFlags__DisplayMask",ImGuiColorEditFlags__DisplayMask);
  tolua_constant(tolua_S,"ImGuiColorEditFlags__DataTypeMask",ImGuiColorEditFlags__DataTypeMask);
  tolua_constant(tolua_S,"ImGuiColorEditFlags__PickerMask",ImGuiColorEditFlags__PickerMask);
  tolua_constant(tolua_S,"ImGuiColorEditFlags__InputMask",ImGuiColorEditFlags__InputMask);
  tolua_constant(tolua_S,"ImGuiMouseCursor_None",ImGuiMouseCursor_None);
  tolua_constant(tolua_S,"ImGuiMouseCursor_Arrow",ImGuiMouseCursor_Arrow);
  tolua_constant(tolua_S,"ImGuiMouseCursor_TextInput",ImGuiMouseCursor_TextInput);
  tolua_constant(tolua_S,"ImGuiMouseCursor_ResizeAll",ImGuiMouseCursor_ResizeAll);
  tolua_constant(tolua_S,"ImGuiMouseCursor_ResizeNS",ImGuiMouseCursor_ResizeNS);
  tolua_constant(tolua_S,"ImGuiMouseCursor_ResizeEW",ImGuiMouseCursor_ResizeEW);
  tolua_constant(tolua_S,"ImGuiMouseCursor_ResizeNESW",ImGuiMouseCursor_ResizeNESW);
  tolua_constant(tolua_S,"ImGuiMouseCursor_ResizeNWSE",ImGuiMouseCursor_ResizeNWSE);
  tolua_constant(tolua_S,"ImGuiMouseCursor_Hand",ImGuiMouseCursor_Hand);
  tolua_constant(tolua_S,"ImGuiMouseCursor_COUNT",ImGuiMouseCursor_COUNT);
  tolua_constant(tolua_S,"ImGuiCond_Always",ImGuiCond_Always);
  tolua_constant(tolua_S,"ImGuiCond_Once",ImGuiCond_Once);
  tolua_constant(tolua_S,"ImGuiCond_FirstUseEver",ImGuiCond_FirstUseEver);
  tolua_constant(tolua_S,"ImGuiCond_Appearing",ImGuiCond_Appearing);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_main (lua_State* tolua_S) {
 return tolua_main_open(tolua_S);
};
#endif

