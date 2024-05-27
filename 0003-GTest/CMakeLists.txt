cmake_minimum_required(VERSION 3.22)

project(optarg_gtest)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB SRC
     "src/*.cpp"
)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE ${SRC})



# CMake instructions to make the static lib
ADD_LIBRARY( _${PROJECT_NAME} STATIC
             ${SRC} )


# gTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
#   GIT_REPOSITORY https://github.com/google/googletest.git
#   GIT_TAG        release-1.14.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
     ${PROJECT_NAME}_test
     tests/hello_test.cc
)

target_link_libraries(
     ${PROJECT_NAME}_test
     GTest::gtest_main
     _${PROJECT_NAME}
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_test)

# add_library(GTest::GTest INTERFACE IMPORTED)
# target_link_libraries(GTest::GTest INTERFACE gtest_main)

# add_executable(arg_test arg_test.cpp)

# target_link_libraries(arg_test
#  PRIVATE
#   GTest::GTest)

# add_test(arg_gtests arg_test)
