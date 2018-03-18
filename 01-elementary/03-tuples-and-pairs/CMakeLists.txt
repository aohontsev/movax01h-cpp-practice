# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.7)

# Set the project name
project (01_03_tuples_and_pairs)

# Add an library for the example classes
add_library(
    01_03_tuples_and_pairs_lib
    src/main.cpp
    src/utils.cpp
    src/utils.h
)

# Create a sources variable with a link to all cpp files to compile
set(
    SOURCES
    src/main.cpp
    src/utils.cpp
    src/utils.h
)

# Add an executable with the above sources
add_executable(01_03_tuples_and_pairs ${SOURCES})

# Add a testing executable
add_executable(01_03_tuples_and_pairs_unittests src/utils_unittest.cpp)

target_link_libraries(
    01_03_tuples_and_pairs_unittests
    01_03_tuples_and_pairs_lib
    GTest::GTest
    GTest::Main
)

add_test(test_all 01_03_tuples_and_pairs_unittests)
