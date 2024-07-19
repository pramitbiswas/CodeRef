cmake_minimum_required(VERSION 3.22)

project(logging)

add_subdirectory(lib)

add_executable(${PROJECT_NAME})

find_package(Threads REQUIRED)

target_sources(${PROJECT_NAME} PRIVATE main.cpp)
target_link_libraries(${PROJECT_NAME} mylog Threads::Threads)
