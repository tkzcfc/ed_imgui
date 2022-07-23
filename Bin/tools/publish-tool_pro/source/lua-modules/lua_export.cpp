/*
** Lua binding: export
** Generated automatically by tolua++-1.0.92 on Tue Jan 25 18:14:46 2022.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"
#include "tolua_fix.h"
#include <string>

/* Exported function */
TOLUA_API int  tolua_export_open (lua_State* tolua_S);

#include "core/shape/CLine.h"
#include "core/shape/CRect.h"
#include "core/Tools.h"
#include "lua_function/tolua_ext.h"
#include "MugenHelper.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_std__vector_Vec2_ (lua_State* tolua_S)
{
 std::vector<Vec2>* self = (std::vector<Vec2>*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_Vec2 (lua_State* tolua_S)
{
 Vec2* self = (Vec2*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_std__vector_std__string_ (lua_State* tolua_S)
{
 std::vector<std::string>* self = (std::vector<std::string>*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CRect (lua_State* tolua_S)
{
 CRect* self = (CRect*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CLine (lua_State* tolua_S)
{
 CLine* self = (CLine*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"std::vector<Vec2>");
 tolua_usertype(tolua_S,"std::vector<std::string>");
 tolua_usertype(tolua_S,"CLine");
 tolua_usertype(tolua_S,"Tools");
 tolua_usertype(tolua_S,"MugenHelper");
 tolua_usertype(tolua_S,"CRect");
 tolua_usertype(tolua_S,"Vec2");
}

/* method: new of class  CLine */
#ifndef TOLUA_DISABLE_tolua_export_CLine_new00
static int tolua_export_CLine_new00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CLine_new00_local
static int tolua_export_CLine_new00_local(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CLine_delete00
static int tolua_export_CLine_delete00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CLine_setPointDataByIndex00
static int tolua_export_CLine_setPointDataByIndex00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CLine_getPointCount00
static int tolua_export_CLine_getPointCount00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CLine_setPointCount00
static int tolua_export_CLine_setPointCount00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CLine_removePointByIndex00
static int tolua_export_CLine_removePointByIndex00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CLine_getNormalCount00
static int tolua_export_CLine_getNormalCount00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CLine_getAllNormal00
static int tolua_export_CLine_getAllNormal00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CLine_getAllPoint00
static int tolua_export_CLine_getAllPoint00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CLine_getLastPoint00
static int tolua_export_CLine_getLastPoint00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CLine_getPointByIndex00
static int tolua_export_CLine_getPointByIndex00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CLine_apply00
static int tolua_export_CLine_apply00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CLine_setNormalLeft00
static int tolua_export_CLine_setNormalLeft00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CLine_isLeftNormal00
static int tolua_export_CLine_isLeftNormal00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CLine_setNormalScale00
static int tolua_export_CLine_setNormalScale00(lua_State* tolua_S)
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

/* method: setAlpha of class  CLine */
#ifndef TOLUA_DISABLE_tolua_export_CLine_setAlpha00
static int tolua_export_CLine_setAlpha00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CLine_setLineCorlor00
static int tolua_export_CLine_setLineCorlor00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CLine_setNormalColor00
static int tolua_export_CLine_setNormalColor00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CLine_getLineColor00
static int tolua_export_CLine_getLineColor00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CLine_getNormalColor00
static int tolua_export_CLine_getNormalColor00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CLine_setVisible00
static int tolua_export_CLine_setVisible00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CLine_isVisible00
static int tolua_export_CLine_isVisible00(lua_State* tolua_S)
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

/* method: new of class  CRect */
#ifndef TOLUA_DISABLE_tolua_export_CRect_new00
static int tolua_export_CRect_new00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CRect_new00_local
static int tolua_export_CRect_new00_local(lua_State* tolua_S)
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

/* method: delete of class  CRect */
#ifndef TOLUA_DISABLE_tolua_export_CRect_delete00
static int tolua_export_CRect_delete00(lua_State* tolua_S)
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

/* method: setAnchorPoint of class  CRect */
#ifndef TOLUA_DISABLE_tolua_export_CRect_setAnchorPoint00
static int tolua_export_CRect_setAnchorPoint00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CRect_getAnchorPoint00
static int tolua_export_CRect_getAnchorPoint00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CRect_setContentSize00
static int tolua_export_CRect_setContentSize00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CRect_getContentSize00
static int tolua_export_CRect_getContentSize00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CRect_setPoint00
static int tolua_export_CRect_setPoint00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CRect_getPoint00
static int tolua_export_CRect_getPoint00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CRect_setScale00
static int tolua_export_CRect_setScale00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CRect_getScale00
static int tolua_export_CRect_getScale00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CRect_setRotation00
static int tolua_export_CRect_setRotation00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CRect_getRotation00
static int tolua_export_CRect_getRotation00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CRect_setSkewX00
static int tolua_export_CRect_setSkewX00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CRect_setSkewY00
static int tolua_export_CRect_setSkewY00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CRect_getSkew00
static int tolua_export_CRect_getSkew00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CRect_apply00
static int tolua_export_CRect_apply00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CRect_getVertexByIndex00
static int tolua_export_CRect_getVertexByIndex00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CRect_getVertexCount00
static int tolua_export_CRect_getVertexCount00(lua_State* tolua_S)
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

/* method: setAlpha of class  CRect */
#ifndef TOLUA_DISABLE_tolua_export_CRect_setAlpha00
static int tolua_export_CRect_setAlpha00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CRect_setVisible00
static int tolua_export_CRect_setVisible00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CRect_isVisible00
static int tolua_export_CRect_isVisible00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CRect_setColor00
static int tolua_export_CRect_setColor00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_export_CRect_getColor00
static int tolua_export_CRect_getColor00(lua_State* tolua_S)
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

/* method: copyFile of class  Tools */
#ifndef TOLUA_DISABLE_tolua_export_Tools_copyFile00
static int tolua_export_Tools_copyFile00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tools",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* existingFileName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* newFileName = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  Tools::copyFile(existingFileName,newFileName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'copyFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: serializeRoleToFile of class  MugenHelper */
#ifndef TOLUA_DISABLE_tolua_export_MugenHelper_serializeRoleToFile00
static int tolua_export_MugenHelper_serializeRoleToFile00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MugenHelper",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* content = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* filename = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  MugenHelper::serializeRoleToFile(content,filename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'serializeRoleToFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: errors of class  MugenHelper */
#ifndef TOLUA_DISABLE_tolua_export_MugenHelper_errors00
static int tolua_export_MugenHelper_errors00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MugenHelper",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::vector<std::string> tolua_ret = (std::vector<std::string>)  MugenHelper::errors();
   {
   tolua_ext_vector_string_to_luaval(tolua_S, tolua_ret, "std::vector<std::string>");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'errors'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: warings of class  MugenHelper */
#ifndef TOLUA_DISABLE_tolua_export_MugenHelper_warings00
static int tolua_export_MugenHelper_warings00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MugenHelper",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::vector<std::string> tolua_ret = (std::vector<std::string>)  MugenHelper::warings();
   {
   tolua_ext_vector_string_to_luaval(tolua_S, tolua_ret, "std::vector<std::string>");
   }
  }
 }
 return 1;
#if COCOS2D_DEBUG >= 1
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'warings'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_export_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CLine","CLine","",tolua_collect_CLine);
  #else
  tolua_cclass(tolua_S,"CLine","CLine","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CLine");
   tolua_function(tolua_S,"new",tolua_export_CLine_new00);
   tolua_function(tolua_S,"new_local",tolua_export_CLine_new00_local);
   tolua_function(tolua_S,".call",tolua_export_CLine_new00_local);
   tolua_function(tolua_S,"delete",tolua_export_CLine_delete00);
   tolua_function(tolua_S,"setPointDataByIndex",tolua_export_CLine_setPointDataByIndex00);
   tolua_function(tolua_S,"getPointCount",tolua_export_CLine_getPointCount00);
   tolua_function(tolua_S,"setPointCount",tolua_export_CLine_setPointCount00);
   tolua_function(tolua_S,"removePointByIndex",tolua_export_CLine_removePointByIndex00);
   tolua_function(tolua_S,"getNormalCount",tolua_export_CLine_getNormalCount00);
   tolua_function(tolua_S,"getAllNormal",tolua_export_CLine_getAllNormal00);
   tolua_function(tolua_S,"getAllPoint",tolua_export_CLine_getAllPoint00);
   tolua_function(tolua_S,"getLastPoint",tolua_export_CLine_getLastPoint00);
   tolua_function(tolua_S,"getPointByIndex",tolua_export_CLine_getPointByIndex00);
   tolua_function(tolua_S,"apply",tolua_export_CLine_apply00);
   tolua_function(tolua_S,"setNormalLeft",tolua_export_CLine_setNormalLeft00);
   tolua_function(tolua_S,"isLeftNormal",tolua_export_CLine_isLeftNormal00);
   tolua_function(tolua_S,"setNormalScale",tolua_export_CLine_setNormalScale00);
   tolua_function(tolua_S,"setAlpha",tolua_export_CLine_setAlpha00);
   tolua_function(tolua_S,"setLineCorlor",tolua_export_CLine_setLineCorlor00);
   tolua_function(tolua_S,"setNormalColor",tolua_export_CLine_setNormalColor00);
   tolua_function(tolua_S,"getLineColor",tolua_export_CLine_getLineColor00);
   tolua_function(tolua_S,"getNormalColor",tolua_export_CLine_getNormalColor00);
   tolua_function(tolua_S,"setVisible",tolua_export_CLine_setVisible00);
   tolua_function(tolua_S,"isVisible",tolua_export_CLine_isVisible00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CRect","CRect","",tolua_collect_CRect);
  #else
  tolua_cclass(tolua_S,"CRect","CRect","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CRect");
   tolua_function(tolua_S,"new",tolua_export_CRect_new00);
   tolua_function(tolua_S,"new_local",tolua_export_CRect_new00_local);
   tolua_function(tolua_S,".call",tolua_export_CRect_new00_local);
   tolua_function(tolua_S,"delete",tolua_export_CRect_delete00);
   tolua_function(tolua_S,"setAnchorPoint",tolua_export_CRect_setAnchorPoint00);
   tolua_function(tolua_S,"getAnchorPoint",tolua_export_CRect_getAnchorPoint00);
   tolua_function(tolua_S,"setContentSize",tolua_export_CRect_setContentSize00);
   tolua_function(tolua_S,"getContentSize",tolua_export_CRect_getContentSize00);
   tolua_function(tolua_S,"setPoint",tolua_export_CRect_setPoint00);
   tolua_function(tolua_S,"getPoint",tolua_export_CRect_getPoint00);
   tolua_function(tolua_S,"setScale",tolua_export_CRect_setScale00);
   tolua_function(tolua_S,"getScale",tolua_export_CRect_getScale00);
   tolua_function(tolua_S,"setRotation",tolua_export_CRect_setRotation00);
   tolua_function(tolua_S,"getRotation",tolua_export_CRect_getRotation00);
   tolua_function(tolua_S,"setSkewX",tolua_export_CRect_setSkewX00);
   tolua_function(tolua_S,"setSkewY",tolua_export_CRect_setSkewY00);
   tolua_function(tolua_S,"getSkew",tolua_export_CRect_getSkew00);
   tolua_function(tolua_S,"apply",tolua_export_CRect_apply00);
   tolua_function(tolua_S,"getVertexByIndex",tolua_export_CRect_getVertexByIndex00);
   tolua_function(tolua_S,"getVertexCount",tolua_export_CRect_getVertexCount00);
   tolua_function(tolua_S,"setAlpha",tolua_export_CRect_setAlpha00);
   tolua_function(tolua_S,"setVisible",tolua_export_CRect_setVisible00);
   tolua_function(tolua_S,"isVisible",tolua_export_CRect_isVisible00);
   tolua_function(tolua_S,"setColor",tolua_export_CRect_setColor00);
   tolua_function(tolua_S,"getColor",tolua_export_CRect_getColor00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Tools","Tools","",NULL);
  tolua_beginmodule(tolua_S,"Tools");
   tolua_function(tolua_S,"copyFile",tolua_export_Tools_copyFile00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"MugenHelper","MugenHelper","",NULL);
  tolua_beginmodule(tolua_S,"MugenHelper");
   tolua_function(tolua_S,"serializeRoleToFile",tolua_export_MugenHelper_serializeRoleToFile00);
   tolua_function(tolua_S,"errors",tolua_export_MugenHelper_errors00);
   tolua_function(tolua_S,"warings",tolua_export_MugenHelper_warings00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_export (lua_State* tolua_S) {
 return tolua_export_open(tolua_S);
};
#endif

