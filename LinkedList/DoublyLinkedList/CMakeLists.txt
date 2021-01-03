cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link doublyLinkedListTest with GTest and pthread
add_executable(doublyLinkedListTest doubly_linked_list_test.cpp)
target_link_libraries(doublyLinkedListTest ${GTEST_LIBRARIES} pthread)