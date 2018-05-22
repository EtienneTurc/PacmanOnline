cmake_minimum_required(VERSION 2.8.9)
project (test)

add_definitions( "-Wall -g -std=c++11" )

#Bring the headers, such as Student.h into the project
include_directories(headers)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

add_executable(main ${SOURCES})
