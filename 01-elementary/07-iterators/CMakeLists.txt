# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.7)

# Set the project name
project (01_07_iterators)

# Create a sources variable with a link to all cpp files to compile
set(
    SOURCES
    src/main.cc
)

# Add an executable with the above sources
add_executable(01_07_iterators ${SOURCES})

# Add a testing executable
add_executable(01_07_iterators_unittests src/main_unittests.cc)

target_link_libraries(
    01_07_iterators_unittests
    GTest::GTest
    GTest::Main
)

add_test(01_07_iterators_unittests 01_07_iterators_unittests)
