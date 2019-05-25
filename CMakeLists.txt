cmake_minimum_required(VERSION 3.0.0)

project(qt-dbhelper VERSION 0.1 LANGUAGES CXX)

if(DEFINED STD_VERSION)
    set(CMAKE_CXX_STANDARD ${STD_VERSION})
else()
    set(CMAKE_CXX_STANDARD 17)
endif()
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} " -g -O -Wall -Werror -Wextra -Wdisabled-optimization \
    -Winline -Wreturn-type -Wsign-compare -Wshadow -Wunused-parameter -Wmissing-declarations \
    -Wcast-align")

find_package(Qt5 5.9.5 COMPONENTS Core Sql REQUIRED)

file(GLOB_RECURSE sources "src/*.cpp")
file(GLOB_RECURSE headers "include/*.h")

include_directories("include")

add_library(${PROJECT_NAME} SHARED ${headers} ${sources})
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Sql)
