cmake_minimum_required(VERSION 3.8)

project(publish-tool)

set(SRC_FILES
    source/main.cpp
	source/MugenHelper.cpp
	source/MugenTest.cpp
    source/lfs/lfs.c
    source/cjson/fpconv.c
    source/cjson/lua_cjson.c
    source/cjson/strbuf.c
	


    source/core/math/Mat4.cpp
    source/core/math/Math.cpp
    source/core/math/Vec2.cpp
    source/core/math/Vec3.cpp
    source/core/math/Vec4.cpp
    source/core/math/Quaternion.cpp
    source/core/math/MathUtil.cpp

    source/core/Tools.cpp
    source/core/shape/CLine.cpp
    source/core/shape/CRect.cpp
    source/core/shape/LineValue.cpp
    source/lua_function/LuaFunction.cpp
    source/lua_function/LuaFunctionBond.cpp
    source/lua_function/tolua_ext.cpp
    source/lua-modules/lua_export.cpp
)

set(HEADERS_FILES
    source/lfs/lfs.h
	source/MugenHelper.h
	source/MugenTest.h
    source/cjson/fpconv.h
    source/cjson/lua_cjson.h
    source/cjson/strbuf.h
    
    source/core/Cocos.h
    source/core/math/Mat4.h
    source/core/math/Mat4.inl
    source/core/math/Math.h
    source/core/math/MathCom.h
    source/core/math/Vec2.h
    source/core/math/Vec2.inl
    source/core/math/Vec3.h
    source/core/math/Vec3.inl
    source/core/math/Vec4.h
    source/core/math/Vec4.inl
    source/core/math/Quaternion.h
    source/core/math/Quaternion.inl
    source/core/math/MathUtil.h
    source/core/math/MathUtil.inl
   

    source/core/Tools.h
    source/core/shape/CLine.h
    source/core/shape/CRect.h
    source/core/shape/LineValue.h
    source/lua_function/LuaFunction.h
    source/lua_function/LuaFunctionBond.h
    source/lua_function/tolua_ext.h
    source/lua-modules/lua_export.h
)



set(MUGEN_SRC_FILES)

file(GLOB_RECURSE mugen_files 
    source/mugen/act/*.cpp)
list(APPEND MUGEN_SRC_FILES
    ${mugen_files}
     )

file(GLOB_RECURSE mugen_files 
    source/mugen/algorithm/*.cpp)
list(APPEND MUGEN_SRC_FILES
    ${mugen_files}
     )
	 
file(GLOB_RECURSE mugen_files 
    source/mugen/allocator/*.cpp)
list(APPEND MUGEN_SRC_FILES
    ${mugen_files}
     )

	 
file(GLOB_RECURSE mugen_files 
    source/mugen/base/*.cpp)
list(APPEND MUGEN_SRC_FILES
    ${mugen_files}
     )

	 
file(GLOB_RECURSE mugen_files 
    source/mugen/collision/*.cpp)
list(APPEND MUGEN_SRC_FILES
    ${mugen_files}
     )

	 
set(mugen_files 
    source/mugen/component/GActorComponent.cpp
    source/mugen/component/GStaticDataComponent.cpp
    source/mugen/component/GAvatarComponent.cpp
    source/mugen/component/GRigidBodyComponent.cpp
)
list(APPEND MUGEN_SRC_FILES
    ${mugen_files}
     )

	 
file(GLOB_RECURSE mugen_files 
    source/mugen/fixpoint/*.cpp)
list(APPEND MUGEN_SRC_FILES
    ${mugen_files}
     )
	 
file(GLOB_RECURSE mugen_files 
    source/mugen/geometry/*.cpp)
list(APPEND MUGEN_SRC_FILES
    ${mugen_files}
     )
	 
file(GLOB_RECURSE mugen_files 
    source/mugen/serialize/*.cpp)
list(APPEND MUGEN_SRC_FILES
    ${mugen_files}
     )


#file(GLOB_RECURSE MUGEN_SRC_FILES 
#    source/mugen/*.cpp)
	
file(GLOB_RECURSE MUGEN_HEADERS_FILES 
    source/mugen/*.h)

source_group("Sources" FILES ${SRC_FILES})
source_group("Headers" FILES ${HEADERS_FILES})


source_group("mugen/Sources" FILES ${MUGEN_SRC_FILES})
source_group("mugen/Headers" FILES ${MUGEN_HEADERS_FILES})

add_definitions(-DPHYSICS_PIXEL_TO_METER=100.0f)
add_definitions(-DRUNTIME_IN_COOCS=0)


add_executable(${PROJECT_NAME} 
   ${SRC_FILES} ${HEADERS_FILES}
   ${MUGEN_SRC_FILES} ${MUGEN_HEADERS_FILES}
)

add_subdirectory(libs/lua)
add_subdirectory(libs/tolua)
add_subdirectory(libs/fmt)

target_link_libraries(${PROJECT_NAME} PRIVATE lua tolua fmt)

target_include_directories(${PROJECT_NAME} PUBLIC ./source)
