cmake_minimum_required(VERSION 3.17)
project(Lab_7_tests)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)

add_subdirectory(src)
include_directories(src)

file(GLOB tests "tests/*.cpp")

add_executable(Lab_7_tests ${tests})
#add_executable(Lab_7_tests main.cpp)

target_link_libraries(Lab_7_tests src gtest gtest_main)