cmake_minimum_required(VERSION 3.17)
project(BigFamily) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -pedantic -pedantic-errors")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-limit-debug-info")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(BigFamily AnimalCount.cpp)