cmake_minimum_required(VERSION 3.17)
project(google)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)

add_subdirectory(src)
include_directories(src)

file(GLOB tests "tests/*.cpp")

add_executable(google ${tests})
#add_executable(google main.cpp)

target_link_libraries(google src gtest gtest_main)