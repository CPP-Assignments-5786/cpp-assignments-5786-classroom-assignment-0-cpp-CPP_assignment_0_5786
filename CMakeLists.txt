cmake_minimum_required(VERSION 3.16)

project(assignment0_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(demo main.cpp Student.cpp)
add_executable(test_runner test.cpp Student.cpp)

target_compile_options(demo PRIVATE -Werror -Wsign-conversion)
target_compile_options(test_runner PRIVATE -Werror -Wsign-conversion)

enable_testing()
add_test(NAME assignment_tests COMMAND test_runner)