# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (LCTrain)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(third_party/googletest)
# set(SOURCES "lib/**.cc" "test/**.cc")

FILE(GLOB SOURCES "lib/*.cc")

# Add an executable
add_library(LCTrain ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(LCTrain
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

enable_testing()

add_executable(
    uttest
    test/leetcode_test.cc
    test/hot.cc
    test/interview.cc
)
target_link_libraries(
    uttest
    LCTrain
    gtest_main
)
include(GoogleTest)
gtest_discover_tests(uttest)
