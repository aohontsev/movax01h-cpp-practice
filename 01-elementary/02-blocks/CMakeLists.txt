# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.7)

# Set the project name
project (01_02_blocks)

# Add an library for the example classes
add_library(
    01_02_blocks_lib
    src/blocks.h
    src/blocks.cpp
)

# Create a sources variable with a link to all cpp files to compile
set(
    SOURCES
    src/blocks.cpp
    src/blocks.h
    src/main.cpp
)

# Add an executable with the above sources
add_executable(01_02_blocks ${SOURCES})

# Add a testing executable
add_executable(01_02_blocks_unittests src/blocks_unittest.cpp)

target_link_libraries(
    01_02_blocks_unittests
    01_02_blocks_lib
    GTest::GTest
    GTest::Main
)

add_test(test_all 01_02_blocks_unittests)
