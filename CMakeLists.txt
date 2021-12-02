cmake_minimum_required(VERSION 3.0.0)
project(CLayer VERSION 0.2.0)

#include(CTest)
#enable_testing()

set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE RelWithDebInfo)

FILE(GLOB cppsources src/*.cpp)
add_executable(CLayer ${cppsources})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
