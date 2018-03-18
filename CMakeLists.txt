# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required (VERSION 3.7)

project(movax01h-cpp-practice)

# Add support C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add elementary sub directories
add_subdirectory(01-elementary/01-temperature)
add_subdirectory(01-elementary/02-blocks)
add_subdirectory(01-elementary/03-tuples-and-pairs)

# Add basic sub directories

# Add intermediate sub directories

# Add advanced sub directories

# Enable unit tests

add_subdirectory(third_party/google-test)

# Enable CTest testing
enable_testing()
