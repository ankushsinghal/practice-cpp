cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link binaryHeapTest with GTest and pthread
add_executable(binaryHeapTest binary_heap.cpp binary_heap_test.cpp)
target_link_libraries(binaryHeapTest ${GTEST_LIBRARIES} pthread)