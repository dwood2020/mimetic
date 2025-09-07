cmake_minimum_required(VERSION 3.15)

project(mimetic
    VERSION 0.1
    DESCRIPTION "CMake build for mimetic library"
    LANGUAGES C CXX     # TODO: Remove C language!
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(BUILD_TESTS "Optionally build tests" ON)

add_subdirectory(mimetic)

if (BUILD_TESTS)
    add_subdirectory(test)
endif()
