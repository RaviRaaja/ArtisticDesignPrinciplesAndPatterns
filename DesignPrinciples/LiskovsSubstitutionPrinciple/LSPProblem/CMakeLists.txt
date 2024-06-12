cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(LSPProblem VERSION 1.0.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include the test directory
add_subdirectory(test)

# Add include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add source files
file(GLOB_RECURSE LIB_SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Create the library
add_library(library SHARED ${LIB_SRC_FILES})

# Optionally specify include directories for the library
target_include_directories(library PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(driver driver.cpp)

target_link_libraries(driver library)
