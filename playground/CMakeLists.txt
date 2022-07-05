cmake_minimum_required(VERSION 3.0.0)

project(playground VERSION 0.1.0)

option(PLAYGROUND_BUILD_SHARD "Build Playground as a shared library, default is true" YES)

#set(source move_demo.cpp)
file(GLOB_RECURSE source ./*.cpp)

if(${PLAYGROUND_BUILD_SHARD})
    add_library(${PROJECT_NAME} SHARED ${source})
else()
    add_library(${PROJECT_NAME} STATIC ${source})
endif()

