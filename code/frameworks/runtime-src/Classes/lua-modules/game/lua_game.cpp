/*
** Lua binding: game
** Generated automatically by tolua++-1.0.92 on 07/02/20 22:13:05.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"
#include "tolua_fix.h"
#include <string>

/* Exported function */
TOLUA_API int  tolua_game_open (lua_State* tolua_S);

#include "lua_function/tolua_ext.h"
#include "core/type/StringArray.h"
#include "core/Tools.h"
#include "core/type/Vec2Value.h"
#include "core/type/LineValue.h"
#include "core/CRect.h"
#include "core/CLine.h"
#include "ilayer/ILayer.h"
#include "log/Logger.h"
#include "editor/EditorContext.h"
#include "editor/ScissorLayer.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Logger (lua_State* tolua_S)
{
 Logger* self = (Logger*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_StringArray (lua_State* tolua_S)
{
 StringArray* self = (StringArray*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_ImVec4 (lua_State* tolua_S)
{
 ImVec4* self = (ImVec4*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_LineValue (lua_State* tolua_S)
{
 LineValue* self = (LineValue*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_std__vector_std__string_ (lua_State* tolua_S)
{
 std::vector<std::string>* self = (std::vector<std::string>*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_std__vector_Vec2_ (lua_State* tolua_S)
{
 std::vector<Vec2>* self = (std::vector<Vec2>*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CLine (lua_State* tolua_S)
{
 CLine* self = (CLine*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_Vec2Value (lua_State* tolua_S)
{
 Vec2Value* self = (Vec2Value*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_Vec2 (lua_State* tolua_S)
{
 Vec2* self = (Vec2*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_ImVec2 (lua_State* tolua_S)
{
 ImVec2* self = (ImVec2*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CRect (lua_State* tolua_S)
{
 CRect* self = (CRect*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_Size (lua_State* tolua_S)
{
 Size* self = (Size*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"StringArray");
 tolua_usertype(tolua_S,"Vec2");
 tolua_usertype(tolua_S,"std::vector<Vec2>");
 tolua_usertype(tolua_S,"Tools");
 tolua_usertype(tolua_S,"CRect");
 tolua_usertype(tolua_S,"Size");
 tolua_usertype(tolua_S,"Logger");
 tolua_usertype(tolua_S,"ScissorLayer");
 tolua_usertype(tolua_S,"ImVec4");
 tolua_usertype(tolua_S,"LineValue");
 tolua_usertype(tolua_S,"EditorContext");
 tolua_usertype(tolua_S,"LUA_FUNCTION");
 tolua_usertype(tolua_S,"std::vector<std::string>");
 tolua_usertype(tolua_S,"cc.Layer");
 tolua_usertype(tolua_S,"ILayer");
 tolua_usertype(tolua_S,"LuaFunction");
 tolua_usertype(tolua_S,"CLine");
 tolua_usertype(tolua_S,"Vec2Value");
 tolua_usertype(tolua_S,"cc.Texture2D");
 tolua_usertype(tolua_S,"ImVec2");
 tolua_usertype(tolua_S,"cc.Node");
 tolua_usertype(tolua_S,"cc.DrawNode");
}

/* method: new of class  StringArray */
#ifndef TOLUA_DISABLE_tolua_game_StringArray_new00
static int tolua_game_StringArray_new00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"StringArray",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   StringArray* tolua_ret = (StringArray*)  Mtolua_new((StringArray)());
    tolua_ext_object_to_luaval<StringArray>(tolua_S,(void*)tolua_ret,"StringArray");
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  StringArray */
#ifndef TOLUA_DISABLE_tolua_game_StringArray_new00_local
static int tolua_game_StringArray_new00_local(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"StringArray",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   StringArray* tolua_ret = (StringArray*)  Mtolua_new((StringArray)());
    tolua_ext_object_to_luaval<StringArray>(tolua_S,(void*)tolua_ret,"StringArray");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  StringArray */
#ifndef TOLUA_DISABLE_tolua_game_StringArray_delete00
static int tolua_game_StringArray_delete00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StringArray",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StringArray* self = (StringArray*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getValueCount of class  StringArray */
#ifndef TOLUA_DISABLE_tolua_game_StringArray_getValueCount00
static int tolua_game_StringArray_getValueCount00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StringArray",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StringArray* self = (StringArray*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getValueCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getValueCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getValueCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getValueByIndex of class  StringArray */
#ifndef TOLUA_DISABLE_tolua_game_StringArray_getValueByIndex00
static int tolua_game_StringArray_getValueByIndex00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StringArray",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StringArray* self = (StringArray*)  tolua_tousertype(tolua_S,1,0);
  int InIndex = ((int)  tolua_tonumber(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getValueByIndex'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->getValueByIndex(InIndex);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getValueByIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addString of class  StringArray */
#ifndef TOLUA_DISABLE_tolua_game_StringArray_addString00
static int tolua_game_StringArray_addString00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StringArray",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StringArray* self = (StringArray*)  tolua_tousertype(tolua_S,1,0);
  const std::string InValue = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addString'", NULL);
#endif
  {
   self->addString(InValue);
   tolua_pushcppstring(tolua_S,(const char*)InValue);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: openFileMultiSelect of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_openFileMultiSelect00
static int tolua_game_Tools_openFileMultiSelect00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"StringArray",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string InFilter = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  StringArray* OutPathArr = ((StringArray*)  tolua_tousertype(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  Tools::openFileMultiSelect(InFilter,OutPathArr);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)InFilter);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'openFileMultiSelect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GbkToUtf8 of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_GbkToUtf800
static int tolua_game_Tools_GbkToUtf800(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Tools* self = (Tools*)  tolua_tousertype(tolua_S,1,0);
  const std::string strGbk = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GbkToUtf8'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GbkToUtf8(strGbk);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)strGbk);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GbkToUtf8'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Utf8ToGbk of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_Utf8ToGbk00
static int tolua_game_Tools_Utf8ToGbk00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Tools* self = (Tools*)  tolua_tousertype(tolua_S,1,0);
  const std::string strUtf8 = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Utf8ToGbk'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->Utf8ToGbk(strUtf8);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)strUtf8);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Utf8ToGbk'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFilename of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_getFilename00
static int tolua_game_Tools_getFilename00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string InPath = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   std::string tolua_ret = (std::string)  Tools::getFilename(InPath);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)InPath);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFilename'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isInRect of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_isInRect00
static int tolua_game_Tools_isInRect00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"cc.Node",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* InNode = ((Node*)  tolua_tousertype(tolua_S,2,0));
  const float InX = ((const float)  tolua_tonumber(tolua_S,3,0));
  const float InY = ((const float)  tolua_tonumber(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  Tools::isInRect(InNode,InX,InY);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isInRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMillisecond of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_getMillisecond00
static int tolua_game_Tools_getMillisecond00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   long tolua_ret = (long)  Tools::getMillisecond();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMillisecond'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: copyFile of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_copyFile00
static int tolua_game_Tools_copyFile00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string existingFileName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string newFileName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  bool bFailIfExists = ((bool)  tolua_toboolean(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  Tools::copyFile(existingFileName,newFileName,bFailIfExists);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)existingFileName);
   tolua_pushcppstring(tolua_S,(const char*)newFileName);
  }
 }
 return 3;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'copyFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: replaceString of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_replaceString00
static int tolua_game_Tools_replaceString00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string str = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string targetstr = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string replacestr = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  {
   std::string tolua_ret = (std::string)  Tools::replaceString(str,targetstr,replacestr);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)str);
   tolua_pushcppstring(tolua_S,(const char*)targetstr);
   tolua_pushcppstring(tolua_S,(const char*)replacestr);
  }
 }
 return 4;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'replaceString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: runExe of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_runExe00
static int tolua_game_Tools_runExe00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string exe = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string cmd = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  {
   Tools::runExe(exe,cmd);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'runExe'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getImguiTextureID of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_getImguiTextureID00
static int tolua_game_Tools_getImguiTextureID00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  bool isPlist = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   void* tolua_ret = (void*)  Tools::getImguiTextureID(key,isPlist);
   tolua_pushuserdata(tolua_S,(void*)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getImguiTextureID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getImguiTextureIDByTexture of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_getImguiTextureIDByTexture00
static int tolua_game_Tools_getImguiTextureIDByTexture00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"cc.Texture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Texture2D* texture = ((Texture2D*)  tolua_tousertype(tolua_S,2,0));
  {
   void* tolua_ret = (void*)  Tools::getImguiTextureIDByTexture(texture);
   tolua_pushuserdata(tolua_S,(void*)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getImguiTextureIDByTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getImguiTextureWidth of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_getImguiTextureWidth00
static int tolua_game_Tools_getImguiTextureWidth00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  bool isPlist = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   int tolua_ret = (int)  Tools::getImguiTextureWidth(key,isPlist);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getImguiTextureWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getImguiTextureHeight of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_getImguiTextureHeight00
static int tolua_game_Tools_getImguiTextureHeight00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  bool isPlist = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   int tolua_ret = (int)  Tools::getImguiTextureHeight(key,isPlist);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getImguiTextureHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: imgui_inputText of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_imgui_inputText00
static int tolua_game_Tools_imgui_inputText00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,2,0));
  std::string buf = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  unsigned int buf_size = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
  unsigned int flags = ((unsigned int)  tolua_tonumber(tolua_S,5,0));
  {
   bool tolua_ret = (bool)  Tools::imgui_inputText(label,buf,buf_size,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)buf);
  }
 }
 return 2;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'imgui_inputText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLogicalDriveStrings of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_getLogicalDriveStrings00
static int tolua_game_Tools_getLogicalDriveStrings00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::vector<std::string> tolua_ret = (std::vector<std::string>)  Tools::getLogicalDriveStrings();
   {
   tolua_ext_vector_string_to_luaval(tolua_S, tolua_ret, "std::vector<std::string>");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLogicalDriveStrings'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UTS of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_UTS00
static int tolua_game_Tools_UTS00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string str = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   std::string tolua_ret = (std::string)  Tools::UTS(str);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UTS'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: STU of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_STU00
static int tolua_game_Tools_STU00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string str = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   std::string tolua_ret = (std::string)  Tools::STU(str);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'STU'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: bor_int32 of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_bor_int3200
static int tolua_game_Tools_bor_int3200(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int a = ((int)  tolua_tonumber(tolua_S,2,0));
  int b = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   int tolua_ret = (int)  Tools::bor_int32(a,b);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bor_int32'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: bor_uint32 of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_bor_uint3200
static int tolua_game_Tools_bor_uint3200(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned int a = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int b = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  {
   unsigned int tolua_ret = (unsigned int)  Tools::bor_uint32(a,b);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bor_uint32'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWindowSize of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_getWindowSize00
static int tolua_game_Tools_getWindowSize00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Size tolua_ret = (Size)  Tools::getWindowSize();
   {
   tolua_ext_size_value_to_luaval(tolua_S, tolua_ret, "Size");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWindowSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BeginTabItem_NoClose of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_BeginTabItem_NoClose00
static int tolua_game_Tools_BeginTabItem_NoClose00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,2,0));
  int flags = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  Tools::BeginTabItem_NoClose(label,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginTabItem_NoClose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMouseClickedPos of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_getMouseClickedPos00
static int tolua_game_Tools_getMouseClickedPos00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   ImVec2 tolua_ret = (ImVec2)  Tools::getMouseClickedPos(index);
   {
   tolua_ext_imvec2_value_to_luaval(tolua_S, tolua_ret, "ImVec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMouseClickedPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BeginWindow_NoClose of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_BeginWindow_NoClose00
static int tolua_game_Tools_BeginWindow_NoClose00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int flags = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  Tools::BeginWindow_NoClose(name,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginWindow_NoClose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: check_AcceptDragDropPayload of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_check_AcceptDragDropPayload00
static int tolua_game_Tools_check_AcceptDragDropPayload00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* type = ((const char*)  tolua_tostring(tolua_S,2,0));
  int flags = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  Tools::check_AcceptDragDropPayload(type,flags);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'check_AcceptDragDropPayload'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AcceptDragDropPayload of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_AcceptDragDropPayload00
static int tolua_game_Tools_AcceptDragDropPayload00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* type = ((const char*)  tolua_tostring(tolua_S,2,0));
  int flags = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   std::string tolua_ret = (std::string)  Tools::AcceptDragDropPayload(type,flags);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AcceptDragDropPayload'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStyleColor of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_getStyleColor00
static int tolua_game_Tools_getStyleColor00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int type = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   ImVec4 tolua_ret = (ImVec4)  Tools::getStyleColor(type);
   {
   tolua_ext_imvec4_value_to_luaval(tolua_S, tolua_ret, "ImVec4");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStyleColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: copyFile of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_copyFile01
static int tolua_game_Tools_copyFile01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  std::string srcFile = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string dstFile = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  Tools::copyFile(srcFile,dstFile);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_game_Tools_copyFile00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: enumerateChildren of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_enumerateChildren00
static int tolua_game_Tools_enumerateChildren00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"cc.Node",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_ext_check_isfunction(tolua_S,4,"LuaFunction",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* node = ((Node*)  tolua_tousertype(tolua_S,2,0));
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  LuaFunction handle = (  LuaFunction(tolua_S,4,0));
  {
   Tools::enumerateChildren(node,name,handle);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'enumerateChildren'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: prettyJson of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_prettyJson00
static int tolua_game_Tools_prettyJson00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* json = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   std::string tolua_ret = (std::string)  Tools::prettyJson(json);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'prettyJson'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: imguiComboUserdata of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_imguiComboUserdata00
static int tolua_game_Tools_imguiComboUserdata00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,2,0));
  int current_item = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   int tolua_ret = (int)  Tools::imguiComboUserdata(label,current_item);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'imguiComboUserdata'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: imguiComboBool of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_imguiComboBool00
static int tolua_game_Tools_imguiComboBool00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool current_item = ((bool)  tolua_toboolean(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  Tools::imguiComboBool(label,current_item);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'imguiComboBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: helpMarker of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_helpMarker00
static int tolua_game_Tools_helpMarker00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* desc = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   Tools::helpMarker(desc);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'helpMarker'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: splitPlist of class  Tools */
#ifndef TOLUA_DISABLE_tolua_game_Tools_splitPlist00
static int tolua_game_Tools_splitPlist00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string plist = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   std::vector<std::string> tolua_ret = (std::vector<std::string>)  Tools::splitPlist(plist);
   {
   tolua_ext_vector_string_to_luaval(tolua_S, tolua_ret, "std::vector<std::string>");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'splitPlist'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  Vec2Value */
#ifndef TOLUA_DISABLE_tolua_get_Vec2Value_x
static int tolua_get_Vec2Value_x(lua_State* tolua_S)
{
  Vec2Value* self = (Vec2Value*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  Vec2Value */
#ifndef TOLUA_DISABLE_tolua_set_Vec2Value_x
static int tolua_set_Vec2Value_x(lua_State* tolua_S)
{
  Vec2Value* self = (Vec2Value*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  Vec2Value */
#ifndef TOLUA_DISABLE_tolua_get_Vec2Value_y
static int tolua_get_Vec2Value_y(lua_State* tolua_S)
{
  Vec2Value* self = (Vec2Value*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  Vec2Value */
#ifndef TOLUA_DISABLE_tolua_set_Vec2Value_y
static int tolua_set_Vec2Value_y(lua_State* tolua_S)
{
  Vec2Value* self = (Vec2Value*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vec2Value */
#ifndef TOLUA_DISABLE_tolua_game_Vec2Value_new00
static int tolua_game_Vec2Value_new00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec2Value",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Vec2Value* tolua_ret = (Vec2Value*)  Mtolua_new((Vec2Value)());
    tolua_ext_object_to_luaval<Vec2Value>(tolua_S,(void*)tolua_ret,"Vec2Value");
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vec2Value */
#ifndef TOLUA_DISABLE_tolua_game_Vec2Value_new00_local
static int tolua_game_Vec2Value_new00_local(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec2Value",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Vec2Value* tolua_ret = (Vec2Value*)  Mtolua_new((Vec2Value)());
    tolua_ext_object_to_luaval<Vec2Value>(tolua_S,(void*)tolua_ret,"Vec2Value");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vec2Value */
#ifndef TOLUA_DISABLE_tolua_game_Vec2Value_new01
static int tolua_game_Vec2Value_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec2Value",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float _x = ((float)  tolua_tonumber(tolua_S,2,0));
  float _y = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vec2Value* tolua_ret = (Vec2Value*)  Mtolua_new((Vec2Value)(_x,_y));
    tolua_ext_object_to_luaval<Vec2Value>(tolua_S,(void*)tolua_ret,"Vec2Value");
  }
 }
 return 1;
tolua_lerror:
 return tolua_game_Vec2Value_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vec2Value */
#ifndef TOLUA_DISABLE_tolua_game_Vec2Value_new01_local
static int tolua_game_Vec2Value_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec2Value",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float _x = ((float)  tolua_tonumber(tolua_S,2,0));
  float _y = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vec2Value* tolua_ret = (Vec2Value*)  Mtolua_new((Vec2Value)(_x,_y));
    tolua_ext_object_to_luaval<Vec2Value>(tolua_S,(void*)tolua_ret,"Vec2Value");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_game_Vec2Value_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  Vec2Value */
#ifndef TOLUA_DISABLE_tolua_game_Vec2Value_set00
static int tolua_game_Vec2Value_set00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec2Value",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vec2Value* self = (Vec2Value*)  tolua_tousertype(tolua_S,1,0);
  float _x = ((float)  tolua_tonumber(tolua_S,2,0));
  float _y = ((float)  tolua_tonumber(tolua_S,3,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   self->set(_x,_y);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x1 of class  LineValue */
#ifndef TOLUA_DISABLE_tolua_get_LineValue_x1
static int tolua_get_LineValue_x1(lua_State* tolua_S)
{
  LineValue* self = (LineValue*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x1'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x1 of class  LineValue */
#ifndef TOLUA_DISABLE_tolua_set_LineValue_x1
static int tolua_set_LineValue_x1(lua_State* tolua_S)
{
  LineValue* self = (LineValue*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x1'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x1 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y1 of class  LineValue */
#ifndef TOLUA_DISABLE_tolua_get_LineValue_y1
static int tolua_get_LineValue_y1(lua_State* tolua_S)
{
  LineValue* self = (LineValue*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y1'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y1 of class  LineValue */
#ifndef TOLUA_DISABLE_tolua_set_LineValue_y1
static int tolua_set_LineValue_y1(lua_State* tolua_S)
{
  LineValue* self = (LineValue*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y1'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y1 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x2 of class  LineValue */
#ifndef TOLUA_DISABLE_tolua_get_LineValue_x2
static int tolua_get_LineValue_x2(lua_State* tolua_S)
{
  LineValue* self = (LineValue*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x2'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x2 of class  LineValue */
#ifndef TOLUA_DISABLE_tolua_set_LineValue_x2
static int tolua_set_LineValue_x2(lua_State* tolua_S)
{
  LineValue* self = (LineValue*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x2'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x2 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y2 of class  LineValue */
#ifndef TOLUA_DISABLE_tolua_get_LineValue_y2
static int tolua_get_LineValue_y2(lua_State* tolua_S)
{
  LineValue* self = (LineValue*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y2'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y2 of class  LineValue */
#ifndef TOLUA_DISABLE_tolua_set_LineValue_y2
static int tolua_set_LineValue_y2(lua_State* tolua_S)
{
  LineValue* self = (LineValue*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y2'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y2 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  LineValue */
#ifndef TOLUA_DISABLE_tolua_game_LineValue_new00
static int tolua_game_LineValue_new00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LineValue",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float _x1 = ((float)  tolua_tonumber(tolua_S,2,0));
  float _y1 = ((float)  tolua_tonumber(tolua_S,3,0));
  float _x2 = ((float)  tolua_tonumber(tolua_S,4,0));
  float _y2 = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   LineValue* tolua_ret = (LineValue*)  Mtolua_new((LineValue)(_x1,_y1,_x2,_y2));
    tolua_ext_object_to_luaval<LineValue>(tolua_S,(void*)tolua_ret,"LineValue");
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  LineValue */
#ifndef TOLUA_DISABLE_tolua_game_LineValue_new00_local
static int tolua_game_LineValue_new00_local(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LineValue",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float _x1 = ((float)  tolua_tonumber(tolua_S,2,0));
  float _y1 = ((float)  tolua_tonumber(tolua_S,3,0));
  float _x2 = ((float)  tolua_tonumber(tolua_S,4,0));
  float _y2 = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   LineValue* tolua_ret = (LineValue*)  Mtolua_new((LineValue)(_x1,_y1,_x2,_y2));
    tolua_ext_object_to_luaval<LineValue>(tolua_S,(void*)tolua_ret,"LineValue");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  LineValue */
#ifndef TOLUA_DISABLE_tolua_game_LineValue_new01
static int tolua_game_LineValue_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LineValue",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   LineValue* tolua_ret = (LineValue*)  Mtolua_new((LineValue)());
    tolua_ext_object_to_luaval<LineValue>(tolua_S,(void*)tolua_ret,"LineValue");
  }
 }
 return 1;
tolua_lerror:
 return tolua_game_LineValue_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  LineValue */
#ifndef TOLUA_DISABLE_tolua_game_LineValue_new01_local
static int tolua_game_LineValue_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LineValue",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   LineValue* tolua_ret = (LineValue*)  Mtolua_new((LineValue)());
    tolua_ext_object_to_luaval<LineValue>(tolua_S,(void*)tolua_ret,"LineValue");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_game_LineValue_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  LineValue */
#ifndef TOLUA_DISABLE_tolua_game_LineValue_set00
static int tolua_game_LineValue_set00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LineValue",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LineValue* self = (LineValue*)  tolua_tousertype(tolua_S,1,0);
  float _x1 = ((float)  tolua_tonumber(tolua_S,2,0));
  float _y1 = ((float)  tolua_tonumber(tolua_S,3,0));
  float _x2 = ((float)  tolua_tonumber(tolua_S,4,0));
  float _y2 = ((float)  tolua_tonumber(tolua_S,5,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   self->set(_x1,_y1,_x2,_y2);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_new00
static int tolua_game_CRect_new00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CRect* tolua_ret = (CRect*)  Mtolua_new((CRect)());
    tolua_ext_object_to_luaval<CRect>(tolua_S,(void*)tolua_ret,"CRect");
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_new00_local
static int tolua_game_CRect_new00_local(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CRect* tolua_ret = (CRect*)  Mtolua_new((CRect)());
    tolua_ext_object_to_luaval<CRect>(tolua_S,(void*)tolua_ret,"CRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnchorPoint of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_setAnchorPoint00
static int tolua_game_CRect_setAnchorPoint00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnchorPoint'", NULL);
#endif
  {
   self->setAnchorPoint(x,y);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnchorPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnchorPoint of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_getAnchorPoint00
static int tolua_game_CRect_getAnchorPoint00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnchorPoint'", NULL);
#endif
  {
   Vec2 tolua_ret = (Vec2)  self->getAnchorPoint();
   {
   tolua_ext_vec2_value_to_luaval(tolua_S, tolua_ret, "Vec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnchorPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setContentSize of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_setContentSize00
static int tolua_game_CRect_setContentSize00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
  float w = ((float)  tolua_tonumber(tolua_S,2,0));
  float h = ((float)  tolua_tonumber(tolua_S,3,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setContentSize'", NULL);
#endif
  {
   self->setContentSize(w,h);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setContentSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getContentSize of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_getContentSize00
static int tolua_game_CRect_getContentSize00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getContentSize'", NULL);
#endif
  {
   Vec2 tolua_ret = (Vec2)  self->getContentSize();
   {
   tolua_ext_vec2_value_to_luaval(tolua_S, tolua_ret, "Vec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getContentSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPoint of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_setPoint00
static int tolua_game_CRect_setPoint00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPoint'", NULL);
#endif
  {
   self->setPoint(x,y);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPoint of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_getPoint00
static int tolua_game_CRect_getPoint00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPoint'", NULL);
#endif
  {
   Vec2 tolua_ret = (Vec2)  self->getPoint();
   {
   tolua_ext_vec2_value_to_luaval(tolua_S, tolua_ret, "Vec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScale of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_setScale00
static int tolua_game_CRect_setScale00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
  float scalex = ((float)  tolua_tonumber(tolua_S,2,0));
  float scaley = ((float)  tolua_tonumber(tolua_S,3,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'", NULL);
#endif
  {
   self->setScale(scalex,scaley);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScale of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_getScale00
static int tolua_game_CRect_getScale00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScale'", NULL);
#endif
  {
   Vec2 tolua_ret = (Vec2)  self->getScale();
   {
   tolua_ext_vec2_value_to_luaval(tolua_S, tolua_ret, "Vec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotation of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_setRotation00
static int tolua_game_CRect_setRotation00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
  float _angle = ((float)  tolua_tonumber(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotation'", NULL);
#endif
  {
   self->setRotation(_angle);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRotation of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_getRotation00
static int tolua_game_CRect_getRotation00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRotation'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getRotation();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSkewX of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_setSkewX00
static int tolua_game_CRect_setSkewX00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
  float skewx = ((float)  tolua_tonumber(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSkewX'", NULL);
#endif
  {
   self->setSkewX(skewx);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSkewX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSkewY of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_setSkewY00
static int tolua_game_CRect_setSkewY00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
  float skewy = ((float)  tolua_tonumber(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSkewY'", NULL);
#endif
  {
   self->setSkewY(skewy);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSkewY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSkew of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_getSkew00
static int tolua_game_CRect_getSkew00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSkew'", NULL);
#endif
  {
   Vec2 tolua_ret = (Vec2)  self->getSkew();
   {
   tolua_ext_vec2_value_to_luaval(tolua_S, tolua_ret, "Vec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSkew'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: apply of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_apply00
static int tolua_game_CRect_apply00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'apply'", NULL);
#endif
  {
   self->apply();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'apply'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getVertexByIndex of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_getVertexByIndex00
static int tolua_game_CRect_getVertexByIndex00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVertexByIndex'", NULL);
#endif
  {
   Vec2 tolua_ret = (Vec2)  self->getVertexByIndex(index);
   {
   tolua_ext_vec2_value_to_luaval(tolua_S, tolua_ret, "Vec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVertexByIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getVertexCount of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_getVertexCount00
static int tolua_game_CRect_getVertexCount00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVertexCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getVertexCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVertexCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: debugDraw of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_debugDraw00
static int tolua_game_CRect_debugDraw00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"cc.DrawNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
  DrawNode* pDrawNode = ((DrawNode*)  tolua_tousertype(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'debugDraw'", NULL);
#endif
  {
   self->debugDraw(pDrawNode);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'debugDraw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAlpha of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_setAlpha00
static int tolua_game_CRect_setAlpha00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
  float alpha = ((float)  tolua_tonumber(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAlpha'", NULL);
#endif
  {
   self->setAlpha(alpha);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVisible of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_setVisible00
static int tolua_game_CRect_setVisible00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVisible'", NULL);
#endif
  {
   self->setVisible(value);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isVisible of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_isVisible00
static int tolua_game_CRect_isVisible00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isVisible'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isVisible();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_setColor00
static int tolua_game_CRect_setColor00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
  unsigned int color = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'", NULL);
#endif
  {
   self->setColor(color);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColor of class  CRect */
#ifndef TOLUA_DISABLE_tolua_game_CRect_getColor00
static int tolua_game_CRect_getColor00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CRect* self = (CRect*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColor'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->getColor();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_new00
static int tolua_game_CLine_new00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CLine* tolua_ret = (CLine*)  Mtolua_new((CLine)());
    tolua_ext_object_to_luaval<CLine>(tolua_S,(void*)tolua_ret,"CLine");
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_new00_local
static int tolua_game_CLine_new00_local(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CLine* tolua_ret = (CLine*)  Mtolua_new((CLine)());
    tolua_ext_object_to_luaval<CLine>(tolua_S,(void*)tolua_ret,"CLine");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_delete00
static int tolua_game_CLine_delete00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPointDataByIndex of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_setPointDataByIndex00
static int tolua_game_CLine_setPointDataByIndex00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
  float y = ((float)  tolua_tonumber(tolua_S,4,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPointDataByIndex'", NULL);
#endif
  {
   self->setPointDataByIndex(index,x,y);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPointDataByIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPointCount of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_getPointCount00
static int tolua_game_CLine_getPointCount00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPointCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getPointCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPointCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPointCount of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_setPointCount00
static int tolua_game_CLine_setPointCount00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
  int count = ((int)  tolua_tonumber(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPointCount'", NULL);
#endif
  {
   self->setPointCount(count);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPointCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removePointByIndex of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_removePointByIndex00
static int tolua_game_CLine_removePointByIndex00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removePointByIndex'", NULL);
#endif
  {
   self->removePointByIndex(index);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removePointByIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNormalCount of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_getNormalCount00
static int tolua_game_CLine_getNormalCount00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNormalCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getNormalCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNormalCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAllNormal of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_getAllNormal00
static int tolua_game_CLine_getAllNormal00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAllNormal'", NULL);
#endif
  {
   std::vector<Vec2> tolua_ret = (std::vector<Vec2>)  self->getAllNormal();
   {
   tolua_ext_vector_vec2_to_luaval(tolua_S, tolua_ret, "std::vector<Vec2>");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAllNormal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAllPoint of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_getAllPoint00
static int tolua_game_CLine_getAllPoint00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAllPoint'", NULL);
#endif
  {
   std::vector<Vec2> tolua_ret = (std::vector<Vec2>)  self->getAllPoint();
   {
   tolua_ext_vector_vec2_to_luaval(tolua_S, tolua_ret, "std::vector<Vec2>");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAllPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLastPoint of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_getLastPoint00
static int tolua_game_CLine_getLastPoint00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLastPoint'", NULL);
#endif
  {
   Vec2 tolua_ret = (Vec2)  self->getLastPoint();
   {
   tolua_ext_vec2_value_to_luaval(tolua_S, tolua_ret, "Vec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLastPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPointByIndex of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_getPointByIndex00
static int tolua_game_CLine_getPointByIndex00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPointByIndex'", NULL);
#endif
  {
   Vec2 tolua_ret = (Vec2)  self->getPointByIndex(index);
   {
   tolua_ext_vec2_value_to_luaval(tolua_S, tolua_ret, "Vec2");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPointByIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: apply of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_apply00
static int tolua_game_CLine_apply00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'apply'", NULL);
#endif
  {
   self->apply();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'apply'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setNormalLeft of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_setNormalLeft00
static int tolua_game_CLine_setNormalLeft00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
  bool isLeft = ((bool)  tolua_toboolean(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setNormalLeft'", NULL);
#endif
  {
   self->setNormalLeft(isLeft);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNormalLeft'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isLeftNormal of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_isLeftNormal00
static int tolua_game_CLine_isLeftNormal00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isLeftNormal'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isLeftNormal();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isLeftNormal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setNormalScale of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_setNormalScale00
static int tolua_game_CLine_setNormalScale00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
  float scale = ((float)  tolua_tonumber(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setNormalScale'", NULL);
#endif
  {
   self->setNormalScale(scale);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNormalScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: debugDraw of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_debugDraw00
static int tolua_game_CLine_debugDraw00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"cc.DrawNode",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
  DrawNode* pDrawNode = ((DrawNode*)  tolua_tousertype(tolua_S,2,0));
  bool forcedDisplay = ((bool)  tolua_toboolean(tolua_S,3,false));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'debugDraw'", NULL);
#endif
  {
   self->debugDraw(pDrawNode,forcedDisplay);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'debugDraw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAlpha of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_setAlpha00
static int tolua_game_CLine_setAlpha00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
  float alpha = ((float)  tolua_tonumber(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAlpha'", NULL);
#endif
  {
   self->setAlpha(alpha);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLineCorlor of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_setLineCorlor00
static int tolua_game_CLine_setLineCorlor00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
  unsigned int color = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLineCorlor'", NULL);
#endif
  {
   self->setLineCorlor(color);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLineCorlor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setNormalColor of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_setNormalColor00
static int tolua_game_CLine_setNormalColor00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
  unsigned int color = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setNormalColor'", NULL);
#endif
  {
   self->setNormalColor(color);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNormalColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLineColor of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_getLineColor00
static int tolua_game_CLine_getLineColor00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLineColor'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->getLineColor();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLineColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNormalColor of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_getNormalColor00
static int tolua_game_CLine_getNormalColor00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNormalColor'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->getNormalColor();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNormalColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVisible of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_setVisible00
static int tolua_game_CLine_setVisible00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVisible'", NULL);
#endif
  {
   self->setVisible(value);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isVisible of class  CLine */
#ifndef TOLUA_DISABLE_tolua_game_CLine_isVisible00
static int tolua_game_CLine_isVisible00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CLine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CLine* self = (CLine*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isVisible'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isVisible();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  ILayer */
#ifndef TOLUA_DISABLE_tolua_game_ILayer_create00
static int tolua_game_ILayer_create00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ILayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ILayer* tolua_ret = (ILayer*)  ILayer::create();
    tolua_ext_object_to_luaval<ILayer>(tolua_S,(void*)tolua_ret,"ILayer");
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateImGUI of class  ILayer */
#ifndef TOLUA_DISABLE_tolua_game_ILayer_updateImGUI00
static int tolua_game_ILayer_updateImGUI00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ILayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ILayer* self = (ILayer*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateImGUI'", NULL);
#endif
  {
   self->updateImGUI();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateImGUI'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeImGUI of class  ILayer */
#ifndef TOLUA_DISABLE_tolua_game_ILayer_removeImGUI00
static int tolua_game_ILayer_removeImGUI00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ILayer",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ILayer* self = (ILayer*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeImGUI'", NULL);
#endif
  {
   self->removeImGUI(name);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeImGUI'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsAnyWindowHovered of class  ILayer */
#ifndef TOLUA_DISABLE_tolua_game_ILayer_IsAnyWindowHovered00
static int tolua_game_ILayer_IsAnyWindowHovered00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ILayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ILayer* self = (ILayer*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsAnyWindowHovered'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsAnyWindowHovered();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsAnyWindowHovered'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setChineseFont of class  ILayer */
#ifndef TOLUA_DISABLE_tolua_game_ILayer_setChineseFont00
static int tolua_game_ILayer_setChineseFont00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ILayer",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ILayer* self = (ILayer*)  tolua_tousertype(tolua_S,1,0);
  std::string fontFileName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  float size_pixels = ((float)  tolua_tonumber(tolua_S,3,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setChineseFont'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setChineseFont(fontFileName,size_pixels);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setChineseFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSystemChineseFont of class  ILayer */
#ifndef TOLUA_DISABLE_tolua_game_ILayer_setSystemChineseFont00
static int tolua_game_ILayer_setSystemChineseFont00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ILayer",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ILayer* self = (ILayer*)  tolua_tousertype(tolua_S,1,0);
  std::string fontFileName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  float size_pixels = ((float)  tolua_tonumber(tolua_S,3,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSystemChineseFont'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setSystemChineseFont(fontFileName,size_pixels);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSystemChineseFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerLuaHandle of class  ILayer */
#ifndef TOLUA_DISABLE_tolua_game_ILayer_registerLuaHandle00
static int tolua_game_ILayer_registerLuaHandle00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ILayer",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !toluafix_isfunction(tolua_S,3,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ILayer* self = (ILayer*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  LUA_FUNCTION handle = (  toluafix_ref_function(tolua_S,3,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerLuaHandle'", NULL);
#endif
  {
   self->registerLuaHandle(name,handle);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerLuaHandle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unregisterLuaHandle of class  ILayer */
#ifndef TOLUA_DISABLE_tolua_game_ILayer_unregisterLuaHandle00
static int tolua_game_ILayer_unregisterLuaHandle00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ILayer",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ILayer* self = (ILayer*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unregisterLuaHandle'", NULL);
#endif
  {
   self->unregisterLuaHandle(name);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unregisterLuaHandle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearLuaHandle of class  ILayer */
#ifndef TOLUA_DISABLE_tolua_game_ILayer_clearLuaHandle00
static int tolua_game_ILayer_clearLuaHandle00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ILayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ILayer* self = (ILayer*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearLuaHandle'", NULL);
#endif
  {
   self->clearLuaHandle();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearLuaHandle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEngulfAllTouchs of class  ILayer */
#ifndef TOLUA_DISABLE_tolua_game_ILayer_setEngulfAllTouchs00
static int tolua_game_ILayer_setEngulfAllTouchs00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ILayer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ILayer* self = (ILayer*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEngulfAllTouchs'", NULL);
#endif
  {
   self->setEngulfAllTouchs(value);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEngulfAllTouchs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isEngulfAllTouchs of class  ILayer */
#ifndef TOLUA_DISABLE_tolua_game_ILayer_isEngulfAllTouchs00
static int tolua_game_ILayer_isEngulfAllTouchs00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ILayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ILayer* self = (ILayer*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isEngulfAllTouchs'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isEngulfAllTouchs();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isEngulfAllTouchs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Logger */
#ifndef TOLUA_DISABLE_tolua_game_Logger_new00
static int tolua_game_Logger_new00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Logger",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Logger* tolua_ret = (Logger*)  Mtolua_new((Logger)());
    tolua_ext_object_to_luaval<Logger>(tolua_S,(void*)tolua_ret,"Logger");
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Logger */
#ifndef TOLUA_DISABLE_tolua_game_Logger_new00_local
static int tolua_game_Logger_new00_local(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Logger",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Logger* tolua_ret = (Logger*)  Mtolua_new((Logger)());
    tolua_ext_object_to_luaval<Logger>(tolua_S,(void*)tolua_ret,"Logger");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Logger */
#ifndef TOLUA_DISABLE_tolua_game_Logger_delete00
static int tolua_game_Logger_delete00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Logger",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Logger* self = (Logger*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  Logger */
#ifndef TOLUA_DISABLE_tolua_game_Logger_getInstance00
static int tolua_game_Logger_getInstance00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Logger",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Logger& tolua_ret = (Logger&)  Logger::getInstance();
    tolua_ext_object_to_luaval<Logger>(tolua_S,&tolua_ret,"Logger");
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstancePtr of class  Logger */
#ifndef TOLUA_DISABLE_tolua_game_Logger_getInstancePtr00
static int tolua_game_Logger_getInstancePtr00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Logger",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Logger* tolua_ret = (Logger*)  Logger::getInstancePtr();
    tolua_ext_object_to_luaval<Logger>(tolua_S,(void*)tolua_ret,"Logger");
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstancePtr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addLog of class  Logger */
#ifndef TOLUA_DISABLE_tolua_game_Logger_addLog00
static int tolua_game_Logger_addLog00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Logger",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Logger* self = (Logger*)  tolua_tousertype(tolua_S,1,0);
  int type = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* fmt = ((const char*)  tolua_tostring(tolua_S,3,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addLog'", NULL);
#endif
  {
   self->addLog(type,fmt);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addLog'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: showAppLog of class  Logger */
#ifndef TOLUA_DISABLE_tolua_game_Logger_showAppLog00
static int tolua_game_Logger_showAppLog00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Logger",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Logger* self = (Logger*)  tolua_tousertype(tolua_S,1,0);
  bool p_open = ((bool)  tolua_toboolean(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'showAppLog'", NULL);
#endif
  {
   self->showAppLog(&p_open);
   tolua_pushboolean(tolua_S,(bool)p_open);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'showAppLog'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: showAppLogNoClose of class  Logger */
#ifndef TOLUA_DISABLE_tolua_game_Logger_showAppLogNoClose00
static int tolua_game_Logger_showAppLogNoClose00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Logger",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Logger* self = (Logger*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'showAppLogNoClose'", NULL);
#endif
  {
   self->showAppLogNoClose();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'showAppLogNoClose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: showAppAndNoWindow of class  Logger */
#ifndef TOLUA_DISABLE_tolua_game_Logger_showAppAndNoWindow00
static int tolua_game_Logger_showAppAndNoWindow00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Logger",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Logger* self = (Logger*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'showAppAndNoWindow'", NULL);
#endif
  {
   self->showAppAndNoWindow();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'showAppAndNoWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clear of class  Logger */
#ifndef TOLUA_DISABLE_tolua_game_Logger_clear00
static int tolua_game_Logger_clear00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Logger",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Logger* self = (Logger*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clear'", NULL);
#endif
  {
   self->clear();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTitle of class  Logger */
#ifndef TOLUA_DISABLE_tolua_game_Logger_setTitle00
static int tolua_game_Logger_setTitle00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Logger",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Logger* self = (Logger*)  tolua_tousertype(tolua_S,1,0);
  const char* title = ((const char*)  tolua_tostring(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTitle'", NULL);
#endif
  {
   self->setTitle(title);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTitle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  EditorContext */
#ifndef TOLUA_DISABLE_tolua_game_EditorContext_create00
static int tolua_game_EditorContext_create00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EditorContext",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   EditorContext* tolua_ret = (EditorContext*)  EditorContext::create();
    tolua_ext_object_to_luaval<EditorContext>(tolua_S,(void*)tolua_ret,"EditorContext");
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getIlayer of class  EditorContext */
#ifndef TOLUA_DISABLE_tolua_game_EditorContext_getIlayer00
static int tolua_game_EditorContext_getIlayer00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditorContext",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditorContext* self = (EditorContext*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIlayer'", NULL);
#endif
  {
   ILayer* tolua_ret = (ILayer*)  self->getIlayer();
    tolua_ext_object_to_luaval<ILayer>(tolua_S,(void*)tolua_ret,"ILayer");
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getIlayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBackgroundNode of class  EditorContext */
#ifndef TOLUA_DISABLE_tolua_game_EditorContext_getBackgroundNode00
static int tolua_game_EditorContext_getBackgroundNode00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditorContext",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditorContext* self = (EditorContext*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBackgroundNode'", NULL);
#endif
  {
   Node* tolua_ret = (Node*)  self->getBackgroundNode();
    tolua_ext_object_to_luaval<Node>(tolua_S,(void*)tolua_ret,"cc.Node");
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBackgroundNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLeftPaneWidth of class  EditorContext */
#ifndef TOLUA_DISABLE_tolua_game_EditorContext_getLeftPaneWidth00
static int tolua_game_EditorContext_getLeftPaneWidth00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditorContext",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditorContext* self = (EditorContext*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLeftPaneWidth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getLeftPaneWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLeftPaneWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCenterPaneWidth of class  EditorContext */
#ifndef TOLUA_DISABLE_tolua_game_EditorContext_getCenterPaneWidth00
static int tolua_game_EditorContext_getCenterPaneWidth00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditorContext",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditorContext* self = (EditorContext*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCenterPaneWidth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getCenterPaneWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCenterPaneWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRightPaneWidth of class  EditorContext */
#ifndef TOLUA_DISABLE_tolua_game_EditorContext_getRightPaneWidth00
static int tolua_game_EditorContext_getRightPaneWidth00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditorContext",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditorContext* self = (EditorContext*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRightPaneWidth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getRightPaneWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRightPaneWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTopPanelHeight of class  EditorContext */
#ifndef TOLUA_DISABLE_tolua_game_EditorContext_getTopPanelHeight00
static int tolua_game_EditorContext_getTopPanelHeight00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditorContext",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditorContext* self = (EditorContext*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTopPanelHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getTopPanelHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTopPanelHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBottomPanelHeight of class  EditorContext */
#ifndef TOLUA_DISABLE_tolua_game_EditorContext_getBottomPanelHeight00
static int tolua_game_EditorContext_getBottomPanelHeight00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditorContext",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditorContext* self = (EditorContext*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBottomPanelHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getBottomPanelHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBottomPanelHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCenterPaneHeight of class  EditorContext */
#ifndef TOLUA_DISABLE_tolua_game_EditorContext_getCenterPaneHeight00
static int tolua_game_EditorContext_getCenterPaneHeight00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditorContext",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditorContext* self = (EditorContext*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCenterPaneHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getCenterPaneHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCenterPaneHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSplitterThickness of class  EditorContext */
#ifndef TOLUA_DISABLE_tolua_game_EditorContext_getSplitterThickness00
static int tolua_game_EditorContext_getSplitterThickness00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditorContext",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditorContext* self = (EditorContext*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSplitterThickness'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getSplitterThickness();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSplitterThickness'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerLuaHandle of class  EditorContext */
#ifndef TOLUA_DISABLE_tolua_game_EditorContext_registerLuaHandle00
static int tolua_game_EditorContext_registerLuaHandle00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditorContext",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !toluafix_isfunction(tolua_S,3,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditorContext* self = (EditorContext*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  LUA_FUNCTION handle = (  toluafix_ref_function(tolua_S,3,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerLuaHandle'", NULL);
#endif
  {
   self->registerLuaHandle(name,handle);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerLuaHandle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unregisterLuaHandle of class  EditorContext */
#ifndef TOLUA_DISABLE_tolua_game_EditorContext_unregisterLuaHandle00
static int tolua_game_EditorContext_unregisterLuaHandle00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditorContext",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditorContext* self = (EditorContext*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unregisterLuaHandle'", NULL);
#endif
  {
   self->unregisterLuaHandle(name);
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unregisterLuaHandle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearLuaHandle of class  EditorContext */
#ifndef TOLUA_DISABLE_tolua_game_EditorContext_clearLuaHandle00
static int tolua_game_EditorContext_clearLuaHandle00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditorContext",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditorContext* self = (EditorContext*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearLuaHandle'", NULL);
#endif
  {
   self->clearLuaHandle();
  }
 }
 return 0;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearLuaHandle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  ScissorLayer */
#ifndef TOLUA_DISABLE_tolua_game_ScissorLayer_create00
static int tolua_game_ScissorLayer_create00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ScissorLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ScissorLayer* tolua_ret = (ScissorLayer*)  ScissorLayer::create();
    tolua_ext_object_to_luaval<ScissorLayer>(tolua_S,(void*)tolua_ret,"ScissorLayer");
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_game_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"StringArray","StringArray","",tolua_collect_StringArray);
  #else
  tolua_cclass(tolua_S,"StringArray","StringArray","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"StringArray");
   tolua_function(tolua_S,"new",tolua_game_StringArray_new00);
   tolua_function(tolua_S,"new_local",tolua_game_StringArray_new00_local);
   tolua_function(tolua_S,".call",tolua_game_StringArray_new00_local);
   tolua_function(tolua_S,"delete",tolua_game_StringArray_delete00);
   tolua_function(tolua_S,"getValueCount",tolua_game_StringArray_getValueCount00);
   tolua_function(tolua_S,"getValueByIndex",tolua_game_StringArray_getValueByIndex00);
   tolua_function(tolua_S,"addString",tolua_game_StringArray_addString00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Tools","Tools","",NULL);
  tolua_beginmodule(tolua_S,"Tools");
   tolua_function(tolua_S,"openFileMultiSelect",tolua_game_Tools_openFileMultiSelect00);
   tolua_function(tolua_S,"GbkToUtf8",tolua_game_Tools_GbkToUtf800);
   tolua_function(tolua_S,"Utf8ToGbk",tolua_game_Tools_Utf8ToGbk00);
   tolua_function(tolua_S,"getFilename",tolua_game_Tools_getFilename00);
   tolua_function(tolua_S,"isInRect",tolua_game_Tools_isInRect00);
   tolua_function(tolua_S,"getMillisecond",tolua_game_Tools_getMillisecond00);
   tolua_function(tolua_S,"copyFile",tolua_game_Tools_copyFile00);
   tolua_function(tolua_S,"replaceString",tolua_game_Tools_replaceString00);
   tolua_function(tolua_S,"runExe",tolua_game_Tools_runExe00);
   tolua_function(tolua_S,"getImguiTextureID",tolua_game_Tools_getImguiTextureID00);
   tolua_function(tolua_S,"getImguiTextureIDByTexture",tolua_game_Tools_getImguiTextureIDByTexture00);
   tolua_function(tolua_S,"getImguiTextureWidth",tolua_game_Tools_getImguiTextureWidth00);
   tolua_function(tolua_S,"getImguiTextureHeight",tolua_game_Tools_getImguiTextureHeight00);
   tolua_function(tolua_S,"imgui_inputText",tolua_game_Tools_imgui_inputText00);
   tolua_function(tolua_S,"getLogicalDriveStrings",tolua_game_Tools_getLogicalDriveStrings00);
   tolua_function(tolua_S,"UTS",tolua_game_Tools_UTS00);
   tolua_function(tolua_S,"STU",tolua_game_Tools_STU00);
   tolua_function(tolua_S,"bor_int32",tolua_game_Tools_bor_int3200);
   tolua_function(tolua_S,"bor_uint32",tolua_game_Tools_bor_uint3200);
   tolua_function(tolua_S,"getWindowSize",tolua_game_Tools_getWindowSize00);
   tolua_function(tolua_S,"BeginTabItem_NoClose",tolua_game_Tools_BeginTabItem_NoClose00);
   tolua_function(tolua_S,"getMouseClickedPos",tolua_game_Tools_getMouseClickedPos00);
   tolua_function(tolua_S,"BeginWindow_NoClose",tolua_game_Tools_BeginWindow_NoClose00);
   tolua_function(tolua_S,"check_AcceptDragDropPayload",tolua_game_Tools_check_AcceptDragDropPayload00);
   tolua_function(tolua_S,"AcceptDragDropPayload",tolua_game_Tools_AcceptDragDropPayload00);
   tolua_function(tolua_S,"getStyleColor",tolua_game_Tools_getStyleColor00);
   tolua_function(tolua_S,"copyFile",tolua_game_Tools_copyFile01);
   tolua_function(tolua_S,"enumerateChildren",tolua_game_Tools_enumerateChildren00);
   tolua_function(tolua_S,"prettyJson",tolua_game_Tools_prettyJson00);
   tolua_function(tolua_S,"imguiComboUserdata",tolua_game_Tools_imguiComboUserdata00);
   tolua_function(tolua_S,"imguiComboBool",tolua_game_Tools_imguiComboBool00);
   tolua_function(tolua_S,"helpMarker",tolua_game_Tools_helpMarker00);
   tolua_function(tolua_S,"splitPlist",tolua_game_Tools_splitPlist00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Vec2Value","Vec2Value","",tolua_collect_Vec2Value);
  #else
  tolua_cclass(tolua_S,"Vec2Value","Vec2Value","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Vec2Value");
   tolua_variable(tolua_S,"x",tolua_get_Vec2Value_x,tolua_set_Vec2Value_x);
   tolua_variable(tolua_S,"y",tolua_get_Vec2Value_y,tolua_set_Vec2Value_y);
   tolua_function(tolua_S,"new",tolua_game_Vec2Value_new00);
   tolua_function(tolua_S,"new_local",tolua_game_Vec2Value_new00_local);
   tolua_function(tolua_S,".call",tolua_game_Vec2Value_new00_local);
   tolua_function(tolua_S,"new",tolua_game_Vec2Value_new01);
   tolua_function(tolua_S,"new_local",tolua_game_Vec2Value_new01_local);
   tolua_function(tolua_S,".call",tolua_game_Vec2Value_new01_local);
   tolua_function(tolua_S,"set",tolua_game_Vec2Value_set00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"LineValue","LineValue","",tolua_collect_LineValue);
  #else
  tolua_cclass(tolua_S,"LineValue","LineValue","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"LineValue");
   tolua_variable(tolua_S,"x1",tolua_get_LineValue_x1,tolua_set_LineValue_x1);
   tolua_variable(tolua_S,"y1",tolua_get_LineValue_y1,tolua_set_LineValue_y1);
   tolua_variable(tolua_S,"x2",tolua_get_LineValue_x2,tolua_set_LineValue_x2);
   tolua_variable(tolua_S,"y2",tolua_get_LineValue_y2,tolua_set_LineValue_y2);
   tolua_function(tolua_S,"new",tolua_game_LineValue_new00);
   tolua_function(tolua_S,"new_local",tolua_game_LineValue_new00_local);
   tolua_function(tolua_S,".call",tolua_game_LineValue_new00_local);
   tolua_function(tolua_S,"new",tolua_game_LineValue_new01);
   tolua_function(tolua_S,"new_local",tolua_game_LineValue_new01_local);
   tolua_function(tolua_S,".call",tolua_game_LineValue_new01_local);
   tolua_function(tolua_S,"set",tolua_game_LineValue_set00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CRect","CRect","",tolua_collect_CRect);
  #else
  tolua_cclass(tolua_S,"CRect","CRect","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CRect");
   tolua_function(tolua_S,"new",tolua_game_CRect_new00);
   tolua_function(tolua_S,"new_local",tolua_game_CRect_new00_local);
   tolua_function(tolua_S,".call",tolua_game_CRect_new00_local);
   tolua_function(tolua_S,"setAnchorPoint",tolua_game_CRect_setAnchorPoint00);
   tolua_function(tolua_S,"getAnchorPoint",tolua_game_CRect_getAnchorPoint00);
   tolua_function(tolua_S,"setContentSize",tolua_game_CRect_setContentSize00);
   tolua_function(tolua_S,"getContentSize",tolua_game_CRect_getContentSize00);
   tolua_function(tolua_S,"setPoint",tolua_game_CRect_setPoint00);
   tolua_function(tolua_S,"getPoint",tolua_game_CRect_getPoint00);
   tolua_function(tolua_S,"setScale",tolua_game_CRect_setScale00);
   tolua_function(tolua_S,"getScale",tolua_game_CRect_getScale00);
   tolua_function(tolua_S,"setRotation",tolua_game_CRect_setRotation00);
   tolua_function(tolua_S,"getRotation",tolua_game_CRect_getRotation00);
   tolua_function(tolua_S,"setSkewX",tolua_game_CRect_setSkewX00);
   tolua_function(tolua_S,"setSkewY",tolua_game_CRect_setSkewY00);
   tolua_function(tolua_S,"getSkew",tolua_game_CRect_getSkew00);
   tolua_function(tolua_S,"apply",tolua_game_CRect_apply00);
   tolua_function(tolua_S,"getVertexByIndex",tolua_game_CRect_getVertexByIndex00);
   tolua_function(tolua_S,"getVertexCount",tolua_game_CRect_getVertexCount00);
   tolua_function(tolua_S,"debugDraw",tolua_game_CRect_debugDraw00);
   tolua_function(tolua_S,"setAlpha",tolua_game_CRect_setAlpha00);
   tolua_function(tolua_S,"setVisible",tolua_game_CRect_setVisible00);
   tolua_function(tolua_S,"isVisible",tolua_game_CRect_isVisible00);
   tolua_function(tolua_S,"setColor",tolua_game_CRect_setColor00);
   tolua_function(tolua_S,"getColor",tolua_game_CRect_getColor00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CLine","CLine","",tolua_collect_CLine);
  #else
  tolua_cclass(tolua_S,"CLine","CLine","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CLine");
   tolua_function(tolua_S,"new",tolua_game_CLine_new00);
   tolua_function(tolua_S,"new_local",tolua_game_CLine_new00_local);
   tolua_function(tolua_S,".call",tolua_game_CLine_new00_local);
   tolua_function(tolua_S,"delete",tolua_game_CLine_delete00);
   tolua_function(tolua_S,"setPointDataByIndex",tolua_game_CLine_setPointDataByIndex00);
   tolua_function(tolua_S,"getPointCount",tolua_game_CLine_getPointCount00);
   tolua_function(tolua_S,"setPointCount",tolua_game_CLine_setPointCount00);
   tolua_function(tolua_S,"removePointByIndex",tolua_game_CLine_removePointByIndex00);
   tolua_function(tolua_S,"getNormalCount",tolua_game_CLine_getNormalCount00);
   tolua_function(tolua_S,"getAllNormal",tolua_game_CLine_getAllNormal00);
   tolua_function(tolua_S,"getAllPoint",tolua_game_CLine_getAllPoint00);
   tolua_function(tolua_S,"getLastPoint",tolua_game_CLine_getLastPoint00);
   tolua_function(tolua_S,"getPointByIndex",tolua_game_CLine_getPointByIndex00);
   tolua_function(tolua_S,"apply",tolua_game_CLine_apply00);
   tolua_function(tolua_S,"setNormalLeft",tolua_game_CLine_setNormalLeft00);
   tolua_function(tolua_S,"isLeftNormal",tolua_game_CLine_isLeftNormal00);
   tolua_function(tolua_S,"setNormalScale",tolua_game_CLine_setNormalScale00);
   tolua_function(tolua_S,"debugDraw",tolua_game_CLine_debugDraw00);
   tolua_function(tolua_S,"setAlpha",tolua_game_CLine_setAlpha00);
   tolua_function(tolua_S,"setLineCorlor",tolua_game_CLine_setLineCorlor00);
   tolua_function(tolua_S,"setNormalColor",tolua_game_CLine_setNormalColor00);
   tolua_function(tolua_S,"getLineColor",tolua_game_CLine_getLineColor00);
   tolua_function(tolua_S,"getNormalColor",tolua_game_CLine_getNormalColor00);
   tolua_function(tolua_S,"setVisible",tolua_game_CLine_setVisible00);
   tolua_function(tolua_S,"isVisible",tolua_game_CLine_isVisible00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ILayer","ILayer","cc.Layer",NULL);
  tolua_beginmodule(tolua_S,"ILayer");
   tolua_function(tolua_S,"create",tolua_game_ILayer_create00);
   tolua_function(tolua_S,"updateImGUI",tolua_game_ILayer_updateImGUI00);
   tolua_function(tolua_S,"removeImGUI",tolua_game_ILayer_removeImGUI00);
   tolua_function(tolua_S,"IsAnyWindowHovered",tolua_game_ILayer_IsAnyWindowHovered00);
   tolua_function(tolua_S,"setChineseFont",tolua_game_ILayer_setChineseFont00);
   tolua_function(tolua_S,"setSystemChineseFont",tolua_game_ILayer_setSystemChineseFont00);
   tolua_function(tolua_S,"registerLuaHandle",tolua_game_ILayer_registerLuaHandle00);
   tolua_function(tolua_S,"unregisterLuaHandle",tolua_game_ILayer_unregisterLuaHandle00);
   tolua_function(tolua_S,"clearLuaHandle",tolua_game_ILayer_clearLuaHandle00);
   tolua_function(tolua_S,"setEngulfAllTouchs",tolua_game_ILayer_setEngulfAllTouchs00);
   tolua_function(tolua_S,"isEngulfAllTouchs",tolua_game_ILayer_isEngulfAllTouchs00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Logger","Logger","",tolua_collect_Logger);
  #else
  tolua_cclass(tolua_S,"Logger","Logger","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Logger");
   tolua_function(tolua_S,"new",tolua_game_Logger_new00);
   tolua_function(tolua_S,"new_local",tolua_game_Logger_new00_local);
   tolua_function(tolua_S,".call",tolua_game_Logger_new00_local);
   tolua_function(tolua_S,"delete",tolua_game_Logger_delete00);
   tolua_function(tolua_S,"getInstance",tolua_game_Logger_getInstance00);
   tolua_function(tolua_S,"getInstancePtr",tolua_game_Logger_getInstancePtr00);
   tolua_function(tolua_S,"addLog",tolua_game_Logger_addLog00);
   tolua_function(tolua_S,"showAppLog",tolua_game_Logger_showAppLog00);
   tolua_function(tolua_S,"showAppLogNoClose",tolua_game_Logger_showAppLogNoClose00);
   tolua_function(tolua_S,"showAppAndNoWindow",tolua_game_Logger_showAppAndNoWindow00);
   tolua_function(tolua_S,"clear",tolua_game_Logger_clear00);
   tolua_function(tolua_S,"setTitle",tolua_game_Logger_setTitle00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"EditorContext","EditorContext","cc.Node",NULL);
  tolua_beginmodule(tolua_S,"EditorContext");
   tolua_function(tolua_S,"create",tolua_game_EditorContext_create00);
   tolua_function(tolua_S,"getIlayer",tolua_game_EditorContext_getIlayer00);
   tolua_function(tolua_S,"getBackgroundNode",tolua_game_EditorContext_getBackgroundNode00);
   tolua_function(tolua_S,"getLeftPaneWidth",tolua_game_EditorContext_getLeftPaneWidth00);
   tolua_function(tolua_S,"getCenterPaneWidth",tolua_game_EditorContext_getCenterPaneWidth00);
   tolua_function(tolua_S,"getRightPaneWidth",tolua_game_EditorContext_getRightPaneWidth00);
   tolua_function(tolua_S,"getTopPanelHeight",tolua_game_EditorContext_getTopPanelHeight00);
   tolua_function(tolua_S,"getBottomPanelHeight",tolua_game_EditorContext_getBottomPanelHeight00);
   tolua_function(tolua_S,"getCenterPaneHeight",tolua_game_EditorContext_getCenterPaneHeight00);
   tolua_function(tolua_S,"getSplitterThickness",tolua_game_EditorContext_getSplitterThickness00);
   tolua_function(tolua_S,"registerLuaHandle",tolua_game_EditorContext_registerLuaHandle00);
   tolua_function(tolua_S,"unregisterLuaHandle",tolua_game_EditorContext_unregisterLuaHandle00);
   tolua_function(tolua_S,"clearLuaHandle",tolua_game_EditorContext_clearLuaHandle00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ScissorLayer","ScissorLayer","cc.Layer",NULL);
  tolua_beginmodule(tolua_S,"ScissorLayer");
   tolua_function(tolua_S,"create",tolua_game_ScissorLayer_create00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_game (lua_State* tolua_S) {
 return tolua_game_open(tolua_S);
};
#endif

