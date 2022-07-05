cmake_minimum_required(VERSION 3.0.0)

project(CppRun VERSION 0.1.0)
# set(CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(third-party/spdlog)
add_subdirectory(playground)
# include_directories()


set(CMAKE_CXX_FLAGS "-std=c++14")
file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(CppRun ${SRC_FILES})
target_include_directories(CppRun PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third-party/spdlog/include
)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    playground
)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
