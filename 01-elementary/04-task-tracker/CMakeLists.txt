# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.7)

# Set the project name
project(01_04_task_tracker)

# Add an library for the example classes
add_library(
    01_04_task_tracker_lib
    src/task_tracker.cc
    src/task_tracker.h
)

# Create a sources variable with a link to all cpp files to compile
set(
    SOURCES
    src/main.cc
    src/task_tracker.cc
    src/task_tracker.h
)

# Add an executable with the above sources
add_executable(01_04_task_tracker ${SOURCES})

# Add a testing executable
add_executable(01_04_task_tracker_unittests src/task_tracker_unittests.cc)

target_link_libraries(
    01_04_task_tracker_unittests
    01_04_task_tracker_lib
    GTest::GTest
    GTest::Main
)

add_test(01_04_task_tracker_unittests 01_04_task_tracker_unittests)
