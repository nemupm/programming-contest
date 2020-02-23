cmake_minimum_required(VERSION 3.6)
project(programming-contest)

file(GLOB SRCS "codes/*/*/*.cpp")

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES ${SRCS})

add_executable(programming-contest ${SOURCE_FILES})
