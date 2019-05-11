cmake_minimum_required(VERSION 3.0.0)

project(qt-dbhelper-tests VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} " -g -O -Wall -Werror -Wextra -Wdisabled-optimization \
    -Wsign-compare -Wshadow -Wunused-parameter -Wno-unused-result -Wcast-align")

add_definitions(-DDB_DRIVER="QMYSQL")
add_definitions(-DDB_USER="mysql")
add_definitions(-DDB_PASSWORD="12345678")
add_definitions(-DDB_HOST="127.0.0.1")
add_definitions(-DDB_PORT=3306)
add_definitions(-DDB_DATABASE_NAME="testing")

find_package(Qt5 5.9.5 COMPONENTS Core Sql REQUIRED)

file(GLOB_RECURSE tst_headers "*.h")
file(GLOB_RECURSE tst_sources "*.cpp")

set(SAVED_COMPILER_FLAGS ${CMAKE_CXX_FLAGS})
set(CMAKE_CXX_FLAGS "")

if (EXISTS "../CMakeLists.txt")
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../" "${CMAKE_CURRENT_BINARY_DIR}/qt-dbhelper")
    file(COPY "../include/" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/qt-dbhelper/include/")
endif()

set(CMAKE_CXX_FLAGS ${SAVED_COMPILER_FLAGS})

set(MODULES "${CMAKE_CURRENT_SOURCE_DIR}/submodules")

list(FILTER tst_headers EXCLUDE REGEX "${MODULES}/googletest/googletest/*.h")
list(FILTER tst_sources EXCLUDE REGEX "${MODULES}/googletest/googletest/*.cpp")

add_subdirectory("${MODULES}/googletest/googletest")
enable_testing()
include_directories("${gtest_SOURCE_DIR}/include" ${gtest_SOURCE_DIR})

include_directories("${CMAKE_CURRENT_BINARY_DIR}/qt-dbhelper/include/")
link_directories("${CMAKE_CURRENT_BINARY_DIR}/qt-dbhelper")

file(COPY "sql" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

add_executable(${PROJECT_NAME} ${tst_headers} ${tst_sources})
target_link_libraries(${PROJECT_NAME} gtest gtest_main qt-dbhelper Qt5::Core Qt5::Sql)
