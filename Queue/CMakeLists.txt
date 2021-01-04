cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link queueTest with GTest and pthread
add_executable(queueTest queue_test.cpp)
target_link_libraries(queueTest ${GTEST_LIBRARIES} pthread)