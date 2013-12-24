# The name of our project is "HELLO". CMakeLists files in this project can 
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and 
# to the root binary directory of the project as ${HELLO_BINARY_DIR}. 
cmake_minimum_required (VERSION 2.6) 
project (RtRayTracing) 

set( SDL2_INCLUDE_DIRS "c:\\sdl" CACHE PATH "SDL2 include directory" )
set( SDL2_LIB_PATH "c:\\sdl\\libs\\" CACHE PATH "SDL2 library" )

set (SOURCE  plane.cpp simpleSDL.cpp sphere.cpp test.cpp light.cpp Vecteur3.txx World.cpp Rayon.cpp LightSource.cpp )
set (HEADER  color.h element.h plane.h simpleSDL.h sphere.h  light.h Vecteur3.h World.h Rayon.h LightSource.h)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(rtRayTracing ${SOURCE} ${HEADER}) 

FIND_LIBRARY(SDL2_LIB SDL2 ${SDL2_LIB_PATH})
FIND_LIBRARY(SDL2MAIN_LIB SDL2MAIN ${SDL2_LIB_PATH})

TARGET_LINK_LIBRARIES(rtRayTracing ${SDL2_LIB} ${SDL2MAIN_LIB})
