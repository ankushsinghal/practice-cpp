cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link resizableArrayTest with GTest and pthread
add_executable(resizableArrayTest resizable_array.cc resizable_array_test.cc)
target_link_libraries(resizableArrayTest ${GTEST_LIBRARIES} pthread)