cmake_minimum_required(VERSION 3.6)
project(TEST_PROJECT)

file(GLOB SRCS "*/*/*/*.cpp")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        ${SRCS})

add_executable(TEST_PROJECT ${SOURCE_FILES})
