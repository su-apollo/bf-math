cmake_minimum_required(VERSION 3.4.1)
project(bf-math)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -fno-rtti -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

set(OUTPUT test.out)
set(INCLUDE ../header)
set(MAIN main.cpp)


add_executable(${OUTPUT} ${MAIN})
target_include_directories(${OUTPUT} PUBLIC ${INCLUDE})
