cmake_minimum_required(VERSION 2.8.9)
project (pacman)

add_definitions( "-Wall -g -Wextra -O3 -std=c++11" )

FIND_PACKAGE( Boost 1.40 REQUIRED COMPONENTS system)
link_directories(${Boost_LIBRARY_DIR})

include_directories(headers)
include_directories(server/headers)
include_directories(../websocketpp)

file(GLOB SOURCES "src/*.cpp" "server/src/*.cpp")
add_executable(main ${SOURCES})
target_link_libraries(main Boost::system pthread)
