cmake_minimum_required(VERSION 3.0.0)

project(qt-dbhelper-tests VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} " -g -O -Wall -Werror -Wextra -Wdisabled-optimization \
    -Wsign-compare -Wshadow -Wunused-parameter -Wcast-align")

find_package(Qt5 5.9.5 COMPONENTS Core Sql REQUIRED)

file(GLOB_RECURSE tst_sources "*.cpp")
if (EXISTS "../CMakeLists.txt")
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../" "${CMAKE_CURRENT_BINARY_DIR}/qt-dbhelper")
    file(COPY "../include/" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/qt-dbhelper/include/")
endif()

set(MODULES "${CMAKE_CURRENT_SOURCE_DIR}/submodules")

add_subdirectory("${MODULES}/googletest/googletest")
enable_testing()
include_directories("${gtest_SOURCE_DIR}/include" ${gtest_SOURCE_DIR})

include_directories("${CMAKE_CURRENT_BINARY_DIR}/qt-dbhelper/include/")
link_directories("${CMAKE_CURRENT_BINARY_DIR}/qt-dbhelper")

add_executable(${PROJECT_NAME} ${tst_sources})
target_link_libraries(${PROJECT_NAME} gtest gtest_main qt-dbhelper)

#target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Sql)
