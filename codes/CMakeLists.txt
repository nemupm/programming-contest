cmake_minimum_required(VERSION 3.6)
project(TEST_PROJECT)

file(GLOB SRCS1 "*/*/*.cpp")
file(GLOB SRCS2 "*/*/*/*.cpp")
file(GLOB SRCS3 "*/*/*/*/*.cpp")

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        ${SRCS1} ${SRCS2} ${SRCS3})

add_executable(TEST_PROJECT ${SOURCE_FILES})
