cmake_minimum_required(VERSION 3.6)
project(programming-contest CXX)

file(GLOB SRCS "codes/*/*/*.cpp")
file(GLOB SRCS2 "codes/*/*/*/*/*.cpp")
file(GLOB LIBRARIES "library/*.hpp")

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES ${SRCS} ${SRCS2} ${LIBRARIES})

add_executable(programming-contest ${SOURCE_FILES})
set_target_properties(programming-contest PROPERTIES LINKER_LANGUAGE CXX)

add_executable(output output/main.cpp)
add_executable(testrunner testrunner/main.cpp)
file(GLOB TASKS "tasks/*.cpp")
file(GLOB_RECURSE HEADERS "library/*.hpp" )

add_executable(test ${TASKS} ${HEADERS})
set_target_properties(test PROPERTIES LINKER_LANGUAGE CXX)
