cmake_minimum_required(VERSION 3.13)
project(StemSoccer)

set(CMAKE_CXX_STANDARD 17)

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.6.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(StemSoccer src/app/main.cpp)
target_link_libraries (StemSoccer sfml-graphics sfml-window sfml-system)