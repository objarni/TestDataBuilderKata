cmake_minimum_required(VERSION 3.16)
set(CMAKE_VERBOSE_MAKEFILE ON)
project(Sample VERSION 1.0
        DESCRIPTION "Test Data Builder pattern in C")

set(CMAKE_C_STANDARD 11)
# uncomment these lines to enable coverage measurements using gcov
#set(CMAKE_CXX_FLAGS "--coverage")

enable_testing()
add_subdirectory(src)
add_subdirectory(test)
