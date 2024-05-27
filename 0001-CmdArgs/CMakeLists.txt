cmake_minimum_required(VERSION 3.22)

project(cmdargs)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE main.cpp)
