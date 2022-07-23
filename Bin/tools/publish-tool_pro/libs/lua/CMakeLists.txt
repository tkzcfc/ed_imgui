project(lua)


file(GLOB_RECURSE HEADERS_FILES 
    *.h)
    
file(GLOB_RECURSE SRC_FILES 
    *.c)

source_group("Sources" FILES ${SRC_FILES})
source_group("Headers" FILES ${HEADERS_FILES})

add_library(${PROJECT_NAME} STATIC
  ${HEADERS_FILES}
  ${SRC_FILES}
)


target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

