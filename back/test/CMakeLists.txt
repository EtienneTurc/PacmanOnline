cmake_minimum_required(VERSION 2.8.9)
project (unitesting)

add_definitions( "-Wall -g -Wextra -O3 -std=c++11" )
include_directories(../headers)
include_directories(../src)
include_directories(unittest)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
file(GLOB TESTS "unittest/*.cpp")
file(GLOB SOURCES "../src/*.cpp")
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/../src/main.cpp")
add_executable(runTests ${TESTS} ${SOURCES})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
