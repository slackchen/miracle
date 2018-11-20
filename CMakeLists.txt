cmake_minimum_required(VERSION 3.8)
project(MiracleCpp)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCE_FILES *.cpp)
file(GLOB HEADER_FILES *.h)

add_executable(miracle ${SOURCE_FILES} ${HEADER_FILES})

