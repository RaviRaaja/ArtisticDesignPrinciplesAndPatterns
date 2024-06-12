cmake_minimum_required(VERSION 3.10)

project (NotifyMe VERSION 1.0.0)

set (CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE LIB_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(library SHARED ${LIB_SRC_FILES})

# added for c flag
# add_definitions(-DPREREQUISITE)

message("current source dir = ${CMAKE_CURRENT_SOURCE_DIR}")
 
target_include_directories(library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(driver driver.cpp)

# added for cflag
# target_compile_definitions(driver PRIVATE PREREQUISITE)

target_link_libraries(driver library)