cmake_minimum_required(VERSION 3.10)

project(Singleton)

add_executable(Singleton main.cpp)

list(APPEND CMAKE_PREFIX_PATH "C:/Catch2")
find_package(Catch2 REQUIRED)

add_executable(tests tests.cpp)
target_include_directories(tests PUBLIC "${CMAKE_SOURCE_DIR}")
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
