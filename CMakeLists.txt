cmake_minimum_required(VERSION 3.5)
project(StemSoccer
        VERSION 0.1
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")

FILE(GLOB_RECURSE TARGET_H "src/*.hpp")
FILE(GLOB_RECURSE TARGET_CPP "src/*.cpp")
SET(TARGET_SRC ${TARGET_CPP} ${TARGET_H})

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.6.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(StemSoccer ${TARGET_SRC})
target_link_libraries (StemSoccer sfml-graphics sfml-window sfml-system)