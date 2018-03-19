# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.7)

# Set the project name
project (01_01_temperature)

# Add an library for the example classes
add_library(
    01_01_temperature_lib
    src/temperature.cc
    src/temperature.h
)

# Create a sources variable with a link to all cpp files to compile
set(
    SOURCES
    src/temperature.h
    src/temperature.cc
    src/main.cc
)

# Add an executable with the above sources
add_executable(01_01_temperature ${SOURCES})

# Add a testing executable
add_executable(01_01_temperature_unittests src/temperature_unittest.cc)

target_link_libraries(
    01_01_temperature_unittests
    01_01_temperature_lib
    GTest::GTest
    GTest::Main
)

add_test(01_01_temperature_unittests 01_01_temperature_unittests)
