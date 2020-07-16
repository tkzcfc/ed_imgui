project(subprocess)

set(LFS_SRC
  subprocess.c
  subprocess.def
  liolib-copy.c
)

source_group("" FILES ${LFS_SRC})

include_directories(
  ../lua
)

add_library(${PROJECT_NAME} SHARED ${LFS_SRC})

target_link_libraries(${PROJECT_NAME} lua5.1)

