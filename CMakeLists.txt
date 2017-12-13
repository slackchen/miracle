cmake_minimum_required(VERSION 3.8)
project(MiracleCpp)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SOURCE_FILES *.cpp)

add_executable(miracle ${SOURCE_FILES})

