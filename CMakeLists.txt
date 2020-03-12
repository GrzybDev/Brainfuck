cmake_minimum_required(VERSION 3.5)

project(Brainfuck LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Brainfuck
  src/main.cpp
  src/error.cpp
  src/help.cpp
  src/interpreter.cpp
)
