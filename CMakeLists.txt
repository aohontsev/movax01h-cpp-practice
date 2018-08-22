# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required (VERSION 3.7)

project(movax01h-cpp-practice)

# Add support C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable CTest testing
enable_testing()

# Add elementary sub directories
add_subdirectory(01-elementary/01-temperature)
add_subdirectory(01-elementary/02-blocks)
add_subdirectory(01-elementary/03-tuples-and-pairs)
add_subdirectory(01-elementary/04-task-tracker)
#add_subdirectory(01-elementary/05-pointers-and-references)
#add_subdirectory(01-elementary/06-function-wrapper)
add_subdirectory(01-elementary/07-iterators)

# Add basic sub directories

# Add intermediate sub directories
#add_subdirectory(03-intermediate/01-singleton-pattern)
#add_subdirectory(03-intermediate/02-singleton-with-factory)

# Add advanced sub directories

# Enable unit tests

add_subdirectory(third_party/google-test)
