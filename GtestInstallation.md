# Steps to install and use Gtest for cpp project

## Details on how cpp project CMake should look like

* Project CMakeLists.txt should look like below,

```
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(ProjectName VERSION 1.0.0)

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

add_executable(executable executable.cpp)

target_link_libraries(executable library)

```

## Using FetchContent

* Here Gtest and GMock Libs are downloaded in build directory
* Contents in CMakeLists.txt under test folder should look like below,

```# Google Test Remote
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

set(GTEST_INCLUDE_DIRS ${googletest_SOURCE_DIR}/googletest/include ${googletest_SOURCE_DIR}/googlemock/include)

# Add the include directories for Google Test
include_directories(${GTEST_INCLUDE_DIRS})

message("Google Test source directory: ${googletest_SOURCE_DIR}")

# Collect all test files in the test directory
file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Add test executable
add_executable(test_my_project ${TEST_SOURCES})

# Link against Google Test and our library
target_link_libraries(test_my_project gtest gmock gtest_main library)

# Register the test
include(GoogleTest)
gtest_discover_tests(test_my_project)

```
## Reference from installed lib in your machine (Mac/Linux).

```
git clone https://github.com/google/googletest.git
cd googletest

mkdir build
cd build

cmake ..
make
sudo make install

```
This will install gtest and gmock libraries and headers to the default system locations (e.g., /usr/local/include and /usr/local/lib)

Below is CMake to infer gtest headers from local libs
```

# Google Test Local
find_package(GTest REQUIRED)

set(GTEST_INCLUDE_DIRS ${googletest_SOURCE_DIR}/googletest/include ${googletest_SOURCE_DIR}/googlemock/include)

message("Google Test source directory: ${googletest_SOURCE_DIR}")

# Collect all test files in the test directory
file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

include_directories(${GTEST_INCLUDE_DIRS})

# Add test executable
add_executable(test_my_project ${TEST_SOURCES})

# Link against Google Test and our library
target_link_libraries(test_my_project GTest::GTest GTest::Main GTest::gmock_main GTest::gmock library)

# set definition for testing
enable_testing()

# Register the test
include(GoogleTest)
gtest_discover_tests(test_my_project)
```

## How to run unit test

* Incase of seg fault use lldb or gdb tools
* Good to have launch.json & task.json to help debugging the test failures for larger projects.

```
cd build/test/
./<Executable name mentioned in test cmake>
./test_my_project
```

## How simple cpp project structure should look

```
MyProject/
├── CMakeLists.txt
├── include/
│   └── MyClass.h
│
├── src/
│   └── MyClass.cpp
├── test/
│   ├── CMakeLists.txt
│   └── MyClassTest.cpp
└── build/

```