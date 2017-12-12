cmake_minimum_required(VERSION 3.8)
project(MiracleCpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Assembler.cpp Compiler.cpp Lexer.cpp Parser.cpp SyntaxTree.cpp)

add_executable(miracle ${SOURCE_FILES})

