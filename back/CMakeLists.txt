cmake_minimum_required(VERSION 2.8.9)
project (pacman)

add_definitions( "-Wall -g -Wextra -O3 -std=c++11" )
include_directories(headers)

file(GLOB SOURCES "src/*.cpp")
add_executable(main ${SOURCES})
