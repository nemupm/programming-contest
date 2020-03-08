cmake_minimum_required(VERSION 3.6)
project(programming-contest CXX)

file(GLOB SRCS "codes/*/*/*.cpp")
file(GLOB LIBRARIES "library/*.hpp")

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES ${SRCS} ${LIBRARIES})

add_executable(programming-contest ${SOURCE_FILES})
set_target_properties(programming-contest PROPERTIES LINKER_LANGUAGE CXX)
