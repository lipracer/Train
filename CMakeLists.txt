# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (LCTrain)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES lib/train_test.cc lib/solution.cc)

# Add an executable
add_executable(LCTrain ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(LCTrain
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)
