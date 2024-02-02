cmake_minimum_required(VERSION 3.10)

project(SmartHomeProject)

add_executable(SmartHome main.cpp src/SmartHome.cpp)

target_include_directories(SmartHome PRIVATE include)
