cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link singlyLinkedListTest with GTest and pthread
add_executable(singlyLinkedListTest singly_linked_list_test.cpp)
target_link_libraries(singlyLinkedListTest ${GTEST_LIBRARIES} pthread)