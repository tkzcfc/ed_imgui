project(fmt)


file(GLOB_RECURSE FMT_HEADERS_FILES 
    *.h)
    
set(FMT_SRC_FILES 
    src/format.cc
	src/os.cc)

source_group("Sources" FILES ${FMT_SRC_FILES})
source_group("Headers" FILES ${FMT_HEADERS_FILES})

add_library(${PROJECT_NAME} STATIC
  ${FMT_HEADERS_FILES}
  ${FMT_SRC_FILES}
)


target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

