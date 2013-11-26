# The name of our project is "HELLO". CMakeLists files in this project can 
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and 
# to the root binary directory of the project as ${HELLO_BINARY_DIR}. 
cmake_minimum_required (VERSION 2.6) 
project (RtRayTracing) 

set( SDL2_INCLUDE_DIRS "c:\\sdl" CACHE PATH "SDL2 include directory" )
set( SDL2_LIBRARIES "c:\\sdl\\libs\\libSDL2.dll" CACHE FILEPATH "SDL2 library" )

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(rtRayTracing element plane simpleSDL sphere test) 

target_link_libraries(rtRayTracing ${SDL2_LIBRARIES})

