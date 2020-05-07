cmake_minimum_required(VERSION 3.13)

project(set-name-thread-test)
set(CMAKE_CXX_STANDARD 17)

include_directories(.)

find_package(Threads REQUIRED)
add_executable(test set_thread_name.hpp test.cpp)

