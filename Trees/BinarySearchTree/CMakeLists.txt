cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link binarySearchTreeTest with GTest and pthread
add_executable(binarySearchTreeTest binary_search_tree_test.cpp)
target_link_libraries(binarySearchTreeTest ${GTEST_LIBRARIES} pthread)