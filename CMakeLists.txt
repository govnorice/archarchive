cmake_minimum_required(VERSION 3.26)
project(pizdec)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
find_package(CURL REQUIRED)

include_directories(${CURL_INCLUDE_DIRS})

add_executable(pizdec main.cpp
        modules/FileManager.cpp
        modules/FileManager.h
        modules/Logic.cpp
        modules/Logic.hpp
        modules/NetworkClient.cpp
        modules/NetworkClient.h
)

target_link_libraries(pizdec ${CURL_LIBRARIES})