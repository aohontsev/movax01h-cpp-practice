# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.7)

# Set the project name
project (01_01_temperature)

# Add an library for the example classes
add_library(01_01_temperature_lib
    src/temperature.h
    src/temperature.cpp
)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/temperature.h
    src/temperature.cpp
    src/main.cpp
)

# Add an executable with the above sources
add_executable(01_01_temperature ${SOURCES})

# Add support C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


#############################################
# Unit tests

add_subdirectory(third_party/google-test)

# enable CTest testing
enable_testing()

# Add a testing executable
add_executable(01_01_temperature_unittests src/temperature_unittest.cpp)

target_link_libraries(01_01_temperature_unittests
    01_01_temperature_lib
    GTest::GTest
    GTest::Main
)

add_test(test_all 01_01_temperature_unittests)
