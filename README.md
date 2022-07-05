# CppRun
A simple cpp project build with CMake

## 添加支持CMake的三方库
以sdplog为例，修改工程根CMakeLists.txt
```cmake
add_subdirectory(third-party/sdplog)
target_include_directories(
 CppRun PUBLIC 
 ${CMAKE_CURRENT_SOURCE_DIR}/third-party/spdlog/include
)
```

## 添加自定义的库
以playground为例，playground目录下添加CMakeLists.txt
```cmake
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

```

修改工程根CMakeLists.txt
```cmake
add_subdirectory(playground)
target_include_directories(CppRun PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    playground
)
```
