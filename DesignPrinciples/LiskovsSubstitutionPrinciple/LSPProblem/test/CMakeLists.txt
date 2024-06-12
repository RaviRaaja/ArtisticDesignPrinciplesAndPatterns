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