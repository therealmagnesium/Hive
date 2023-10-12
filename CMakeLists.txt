cmake_minimum_required(VERSION 3.14.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

project("HiveEngine" VERSION 1.0)

add_subdirectory("vendor/raylib")

add_subdirectory("Hive")
add_subdirectory("Sandbox")
